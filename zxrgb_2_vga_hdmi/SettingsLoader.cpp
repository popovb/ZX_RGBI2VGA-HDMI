//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "SettingsLoader.hpp"

zxrgb::SettingsLoader::SettingsLoader(CaptureSettings& v):
     cs(v)
{
     return;
}

void zxrgb::SettingsLoader::load(const char* s, int v) const {
     if (shift_x(s, v)) return;
     if (shift_y(s, v)) return;
     if (clk_mode(s, v)) return;
     if (video_mode(s, v)) return;
     if (sync_mode(s, v)) return;
     if (x3_buff(s, v)) return;
     if (int_freq(s, v)) return;
     if (ext_freq_div(s, v)) return;
     if (delay(s, v)) return;
     if (delay_rise(s, v)) return;
     if (delay_fall(s, v)) return;
     if (inv_pin_mask(s, v)) return;
     if (len_vs(s, v)) return;
     if (color_mode(s, v)) return;
     if (wide(s, v)) return;
     Serial.printf("wrong command\n");
}

bool zxrgb::SettingsLoader::shift_x(const char* s, int v) const {
     if (! check(s + 1, "cap_sh_x") ) return false;
     if (! check(s[0]) ) return false;
     set(cs.shift_x, s, v);
     return true;
}

bool zxrgb::SettingsLoader::shift_y(const char* s, int v) const {
     if (! check(s + 1, "cap_sh_y") ) return false;
     if (! check(s[0]) ) return false;
     set(cs.shift_y, s, v);
     return true;
}

bool zxrgb::SettingsLoader::clk_mode(const char* s, int v) const {
     if (! check(s + 1, "cap_p_clk_mode") ) return false;
     if (! check(s[0]) ) return false;
     set(cs.clk_mode, s, v);
     return true;
}

bool zxrgb::SettingsLoader::video_mode(const char* s, int v) const {
     if (! check(s + 1, "video_out") ) return false;
     if (! check(s[0]) ) return false;
     set(cs.video_mode, s, v);
     return true;
}

bool zxrgb::SettingsLoader::sync_mode(const char* s, int v) const {
     if (! check(s + 1, "cap_sync_mode") ) return false;
     if (! check(s[0]) ) return false;
     set(cs.sync_mode, s, v);
     return true;
}

bool zxrgb::SettingsLoader::x3_buff(const char* s, int v) const {
     if (! check(s + 1, "is_3X_bufmode") ) return false;
     if (! check(s[0]) ) return false;
     set(cs.x3_buff, s, v);
     return true;
}

bool zxrgb::SettingsLoader::int_freq(const char* s, int v) const {
     if (! check(s + 1, "cap_int_f") ) return false;
     if (! check(s[0]) ) return false;
     set(cs.int_freq, s, v);
     return true;
}

bool zxrgb::SettingsLoader::ext_freq_div(const char* s, int v) const {
     if (! check(s + 1, "cap_ext_f_div") ) return false;
     if (! check(s[0]) ) return false;
     set(cs.ext_freq_div, s, v);
     return true;
}

bool zxrgb::SettingsLoader::delay(const char* s, int v) const {
     if (! check(s + 1, "cap_delay") ) return false;
     if (! check(s[0]) ) return false;
     set(cs.delay, s, v);
     return true;
}

bool zxrgb::SettingsLoader::delay_rise(const char* s, int v) const {
     if (! check(s + 1, "cap_delay_rise") ) return false;
     if (! check(s[0]) ) return false;
     set(cs.delay_rise, s, v);
     return true;
}

bool zxrgb::SettingsLoader::delay_fall(const char* s, int v) const {
     if (! check(s + 1, "cap_delay_fall") ) return false;
     if (! check(s[0]) ) return false;
     set(cs.delay_fall, s, v);
     return true;
}

bool zxrgb::SettingsLoader::check(char v) const {
     if (v == 'w') return true;
     if (v == 'r') return true;
     return false;
}

bool zxrgb::SettingsLoader::check(const char* a, const char* b) const {
     if (strcmp(a, b) == 0) return true;
     return false;
}
/*
  if (strcmp(s_key+1, "cap_len_VS")==0) CAP_SET_LOAD(capture_setings.len_VS,int)
  if (strcmp(s_key+1, "cap_in_inv_mask")==0) CAP_SET_LOAD(capture_setings.inv_capture_pin_mask,int)
  if (strcmp(s_key+1, "c_mode")==0) CAP_SET_LOAD(capture_setings.c_mode,c_mode_t)
  if (strcmp(s_key+1, "wide_mode")==0) CAP_SET_LOAD(capture_setings.is_wide_mode,int)
  
printf("wrong command\n");
}
*/
/*
#define CAP_SET_LOAD(x,T) {if(s_key[0]=='r' || s_key[0]=='w') {  if(s_key[0]=='w') (x)=static_cast<T>(s_data); check_cap_data(&capture_setings); printf("%s %d\n",s_key,(x)); continue;};};
*/
