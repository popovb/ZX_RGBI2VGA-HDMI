//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "SettingsLoader.hpp"
/*
bool zxrgb::SettingsLoader::load(CaptureSettings& cs, char* s) const {
     //if (
     //
     // TODO
     //
     return true;
}


void CAP_SET_LOAD(x, T) {
     if(s_key[0]=='r' || s_key[0]=='w') {
	  if(s_key[0]=='w') (x)=static_cast<T>(s_data);
	  check_cap_data(&capture_setings);
	  printf("%s %d\n",s_key,(x));
	  continue;
     }
}
*/
/*
//обработчик загрузки параметров захвата
#define CAP_SET_LOAD(x,T) {if(s_key[0]=='r' || s_key[0]=='w') {  if(s_key[0]=='w') (x)=static_cast<T>(s_data); check_cap_data(&capture_setings); printf("%s %d\n",s_key,(x)); continue;};};
	       
//смещение изображения
if (strcmp(s_key+1, "cap_sh_x") == 0)        CAP_SET_LOAD(capture_setings.shX, int)
if (strcmp(s_key+1, "cap_sh_y") == 0)        CAP_SET_LOAD(capture_setings.shY, int)
if (strcmp(s_key+1, "cap_delay") == 0)       CAP_SET_LOAD(capture_setings.capture_delay, int)
if (strcmp(s_key+1, "cap_delay_fall") == 0)  CAP_SET_LOAD(capture_setings.capture_delay_fall, int)
if (strcmp(s_key+1, "cap_delay_rise") == 0)  CAP_SET_LOAD(capture_setings.capture_delay_rise, int)
if (strcmp(s_key+1, "cap_ext_f_div") == 0)   CAP_SET_LOAD(capture_setings.ext_freq_div, int)
if (strcmp(s_key+1, "cap_sync_mode") == 0)   CAP_SET_LOAD(capture_setings.in_sync_mode, in_sync_mode_t)
if (strcmp(s_key+1, "cap_len_VS") == 0)      CAP_SET_LOAD(capture_setings.len_VS,int)
if (strcmp(s_key+1, "cap_p_clk_mode") == 0)  CAP_SET_LOAD(capture_setings.p_clk_mode, p_clk_mode_t)
if (strcmp(s_key+1, "video_out") == 0)       CAP_SET_LOAD(capture_setings.video_out_mode, video_out_mode_t)
if (strcmp(s_key+1, "cap_int_f") == 0)       CAP_SET_LOAD(capture_setings.int_freq, int)
if (strcmp(s_key+1, "cap_in_inv_mask") == 0) CAP_SET_LOAD(capture_setings.inv_capture_pin_mask, int)
if (strcmp(s_key+1, "is_3X_bufmode") == 0)   CAP_SET_LOAD(capture_setings.is_3X_Buf, int)
if (strcmp(s_key+1, "c_mode") == 0)          CAP_SET_LOAD(capture_setings.c_mode, c_mode_t)
if (strcmp(s_key+1, "wide_mode") == 0)       CAP_SET_LOAD(capture_setings.is_wide_mode, int)

printf("wrong command\n");

}
*/
