//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "CaptureSettings.hpp"

#ifndef _ZXRGB_SETTINGS_LOADER_HPP_
#define _ZXRGB_SETTINGS_LOADER_HPP_

namespace zxrgb {

     class SettingsLoader {

     public:
	  SettingsLoader(CaptureSettings&);

	  void load(const char*, int) const;

     private:
	  CaptureSettings& cs;

     private:
	  bool shift_x(const char*, int) const;
	  bool shift_y(const char*, int) const;
	  bool clk_mode(const char*, int) const;
	  bool video_mode(const char*, int) const;
	  bool sync_mode(const char*, int) const;
	  bool x3_buff(const char*, int) const;
	  bool int_freq(const char*, int) const;
	  bool ext_freq_div(const char*, int) const;
	  bool delay(const char*, int) const;
	  bool delay_rise(const char*, int) const;
	  bool delay_fall(const char*, int) const;
	  bool inv_pin_mask(const char*, int) const;
	  bool len_vs(const char*, int) const;
	  bool color_mode(const char*, int) const;
	  bool wide(const char*, int) const;
     };
}
#endif // _ZXRGB_SETTINGS_LOADER_HPP_
