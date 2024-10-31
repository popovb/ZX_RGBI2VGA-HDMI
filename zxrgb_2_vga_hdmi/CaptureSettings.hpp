//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"
#include "ClockMode.hpp"
#include "VideoMode.hpp"
#include "SyncMode.hpp"
#include "ColorMode.hpp"

#ifndef _ZXRGB_CAPTURE_SETTINGS_HPP_
#define _ZXRGB_CAPTURE_SETTINGS_HPP_

namespace zxrgb {

     struct CaptureSettings {
	  i16 shift_x;
	  i16 shift_y;
	  ClockMode::mode_t clk_mode;
	  VideoMode::mode_t video_mode;
	  SyncMode::mode_t sync_mode;
	  bool x3_buff;
	  u32 int_freq;
	  u32 ext_freq_div;
	  u32 delay;
	  u32 delay_rise;
	  u32 delay_fall;
	  u32 inv_pin_mask;
	  u16 len_vs;
	  ColorMode::mode_t color_mode;
	  bool wide;
     };
}
#endif // _ZXRGB_CAPTURE_SETTINGS_HPP_
