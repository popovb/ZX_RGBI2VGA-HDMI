#include "rgb_capture.h"
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
     using namespace zxrgb;
     auto& vbs = get_video_buffers();

     vreg_set_voltage(VREG_VOLTAGE_1_25);
     sleep_ms(100);
     set_sys_clock_khz(252000, true);
     sleep_ms(10);
     Serial.begin(115200);

     Flasher flshr;
     flshr.load(capture_setings);

     CaptureSettingsChecker csc;
     csc.check(capture_setings);

     Led led;
     led.on();

     if (watchdog_caused_reboot()) {
	  SerialReactor sr(SerialReactor::Mode0, capture_setings);
	  sr.handle();

	  if (sr.need_to_save()) {
	       flshr.save(capture_setings);
	       Serial.printf("saving data\n");
	  }
     }

     if (capture_setings.x3_buff)
	  vbs.set_mode(VideoBuffers::X_3);
     else
	  vbs.set_mode(VideoBuffers::X_1);

     led.off();

     PicturesDrawer pd;
     pd.hello();

     switch (capture_setings.video_mode) {

     case VideoMode::Vga:
	  startVGA();
	  break;

     case VideoMode::Hdmi:
	  startHDMI();
	  break;

     default:
	  return;
     }

     core0_is_started = true;
}

// the loop function runs over and over again forever
void loop() {
     char s_key[20];
     int s_data;
     sleep_ms(3);

     String s1=Serial.readStringUntil('\n');
     if (s1.length()==0) return;
     sscanf(s1.c_str(),"%19s%d",s_key,&s_data);
    
     if (strcmp(s_key, "ping")==0) { printf("ping ok\n"); return;};
     if (strcmp(s_key, "reset")==0 || strcmp(s_key, "restart")==0 ) {printf("reset...\n");rp2040.restart();};
     if (strcmp(s_key, "mode")==0) { printf("mode 1\n"); return;};
     if (strcmp(s_key+1, "cap_sh_x")==0) {if(s_key[0]=='w') set_cap_shx(s_data); return;}
     if (strcmp(s_key+1, "cap_sh_y")==0) {if(s_key[0]=='w') set_cap_shy(s_data); return;}
}

void setup1() {
     while(! core0_is_started) sleep_ms(3);
     startCapture(&capture_setings);
}

void loop1() {
     sleep_ms(1000);    
}
