#include "pico/stdlib.h"
#include "hardware/vreg.h"
#include "hardware/flash.h"
#include "stdio.h"

#include "rgb_capture.h"
#include "VGA.h"
#include "HDMI.h"
#include "VideoBuffers.hpp"
#include "PicturesDrawer.hpp"
//#include "SettingsLoader.hpp"
#include "CaptureSettingsChecker.hpp"
#include "SerialReactor.hpp"

#define printf Serial.printf

zxrgb::CaptureSettings capture_setings;

// int data_for_save[FLASH_PAGE_SIZE/sizeof(int)]; 
const int *flash_data_for_save = (const int *) (XIP_BASE + (PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE));

bool is_start_core0=false;

void setup() {
     using namespace zxrgb;
     auto& vbs = get_video_buffers();

     vreg_set_voltage(VREG_VOLTAGE_1_25);
     sleep_ms(100);
     set_sys_clock_khz(252000, true);
     sleep_ms(10);
     Serial.begin(115200);

//      //загружаем ранее сохранённые данные заxвата
     memcpy(&capture_setings,
						flash_data_for_save,
						sizeof(zxrgb::CaptureSettings));
     // memset(&capture_setings,0,sizeof(cap_set_t));//test

     // подправляем , если в ячйках мусор
     // check_cap_data(&capture_setings);
		 CaptureSettingsChecker csc;
		 csc.check(capture_setings);

		 pinMode(LED_BUILTIN, OUTPUT);
     digitalWrite(LED_BUILTIN, HIGH);  // если попадём в настройки после wdt_reboot, то индикатор это покажет

 
///////////////////////////////////////////////////////////////////
     if (watchdog_caused_reboot()) {
					SerialReactor sr(SerialReactor::Mode0);
					sr.handle();

					if (sr.need_to_save()) {
							 //
							 // TODO
							 //
					}
		 }
			 /*
					SettingsLoader sl;

					char s_key[20];
					int s_data;

					bool is_save=false;
					//цикл с разбором команд
					while (true) {
							 String s1=Serial.readStringUntil('\n');
							 if (s1.length()==0) continue;
							 sscanf(s1.c_str(),"%19s%d",s_key,&s_data);


							 if (strcmp(s_key, "ping")==0) { printf("ping ok\n"); continue;};
							 if (strcmp(s_key, "mode")==0) { printf("mode 0\n"); continue;};

							 if (strcmp(s_key, "exit")==0) { printf("exit ok\n"); break;};
							 if (strcmp(s_key, "save")==0) { is_save=true; printf("saving...\n"); break;};
							 if (! sl.load(capture_setings, s_key + 1))
										printf("wrong command\n");
					}

//сохранение параметров
					if (is_save)
					{
							 // check_cap_data(&capture_setings);
							 csc.check(capture_setings);
							 uint32_t ints = save_and_disable_interrupts();
							 flash_range_erase((PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE), FLASH_SECTOR_SIZE);                           
							 flash_range_program((PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE), ( uint8_t*) &capture_setings, FLASH_PAGE_SIZE);
							 restore_interrupts (ints);

							 printf("saving data\n");
					};
			 

     }*/
		 
///////////////////////////////////////////////////////////////////     
     
     if (capture_setings.x3_buff)
					vbs.set_mode(VideoBuffers::X_3);
     else
					vbs.set_mode(VideoBuffers::X_1);

     digitalWrite(LED_BUILTIN, LOW);  // сбрасываем индикаторный светодиод

     //draw_hello_image();
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
