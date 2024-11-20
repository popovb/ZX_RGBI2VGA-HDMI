#include "Capturer.hpp"
#include "VGA.h"
#include "HDMI.h"
#include "VideoBuffers.hpp"
#include "PicturesDrawer.hpp"
#include "CaptureSettingsChecker.hpp"
#include "SerialReactor.hpp"
#include "Flasher.hpp"
#include "Led.hpp"

#include <Arduino.h>
#include <hardware/vreg.h>

zxrgb::CaptureSettings capture_setings;
bool core0_is_started = false;

void setup() {
     auto& vbs = zxrgb::get_video_buffers();

     vreg_set_voltage(VREG_VOLTAGE_1_25);
     sleep_ms(100);
     set_sys_clock_khz(252000, true);
     sleep_ms(10);
     Serial.begin(115200);

     zxrgb::Flasher flshr;
     flshr.load(capture_setings);

     zxrgb::CaptureSettingsChecker csc;
     csc.check(capture_setings);

     zxrgb::Led led;
     led.on();

     if (watchdog_caused_reboot()) {
	  zxrgb::SerialReactor sr(zxrgb::SerialReactor::Mode0,
				  capture_setings);
	  sr.handle();

	  if (sr.need_to_save()) {
	       flshr.save(capture_setings);
	       Serial.printf("saving data\n");
	  }
     }

     if (capture_setings.x3_buff)
	  vbs.set_mode(zxrgb::VideoBuffers::X_3);
     else
	  vbs.set_mode(zxrgb::VideoBuffers::X_1);

     led.off();

     zxrgb::PicturesDrawer pd;
     pd.hello();

     switch (capture_setings.video_mode) {

     case zxrgb::VideoMode::Vga:
	  startVGA();
	  break;

     case zxrgb::VideoMode::Hdmi:
	  startHDMI();
	  break;

     default:
	  return;
     }

     core0_is_started = true;
}

void loop() {
     sleep_ms(3);
     zxrgb::SerialReactor sr(zxrgb::SerialReactor::Mode1,
			     capture_setings);
     sr.handle();
}

void setup1() {
     while(! core0_is_started) sleep_ms(3);
     zxrgb::Capturer caper(capture_setings);
     caper.start();
     // startCapture(&capture_setings);
}

void loop1() {
     sleep_ms(1000);    
}
