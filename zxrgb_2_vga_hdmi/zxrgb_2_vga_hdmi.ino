#include "pico/stdlib.h"
#include "hardware/vreg.h"
#include "hardware/flash.h"
#include "stdio.h"

#include "rgb_capture.h"
#include "VGA.h"
#include "HDMI.h"
#include "VideoBuffers.hpp"
#include "PicturesDrawer.hpp"
#include "CaptureSettingsChecker.hpp"
#include "SerialReactor.hpp"
#include "Flasher.hpp"

zxrgb::CaptureSettings capture_setings;

bool is_start_core0=false;

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

		 pinMode(LED_BUILTIN, OUTPUT);
     digitalWrite(LED_BUILTIN, HIGH);  // если попадём в настройки после wdt_reboot, то индикатор это покажет

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

     digitalWrite(LED_BUILTIN, LOW);  // сбрасываем индикаторный светодиод

     PicturesDrawer pd;
     pd.hello();

     if (capture_setings.video_mode == VideoMode::Vga) {startVGA();}//setVGAWideMode(capture_setings.is_wide_mode);
     if (capture_setings.video_mode == VideoMode::Hdmi) { startHDMI();};
  
     is_start_core0=true;
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
     while(! is_start_core0) sleep_ms(3);
     startCapture(&capture_setings);
}

void loop1() {
     sleep_ms(1000);    
}
