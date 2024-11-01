//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "CaptureSettingsChecker.hpp"

///////////////////////////////////////////////////////////////////
const zxrgb::CaptureSettings
zxrgb::CaptureSettingsChecker::min = {
     .shift_x = 0,
     .shift_y = 0,
     .clk_mode = ClockMode::SelfSync,
     .video_mode = VideoMode::Vga,
     .sync_mode = SyncMode::S,
     .int_freq = 6000000,
     .ext_freq_div = 1,
     .delay = 0,
     .delay_rise = 0,
     .delay_fall = 0,
     .inv_pin_mask = 0,
     .len_vs = 50,
     .color_mode = ColorMode::Pal
};

const zxrgb::CaptureSettings
zxrgb::CaptureSettingsChecker::max = {
     .shift_x = 200,
     .shift_y = 200,
     .clk_mode = ClockMode::Z80Freq,
     .video_mode = VideoMode::Comp,
     .sync_mode = SyncMode::C,
     .int_freq = 11000000,
     .ext_freq_div = 5,
     .delay = 31,
     .delay_rise = 31,
     .delay_fall = 31,
     .inv_pin_mask = 0x7f,
     .len_vs = 500,
     .color_mode = ColorMode::Secam
};
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
void zxrgb::CaptureSettingsChecker::check(CaptureSettings& cs) const {
     select_min_max(cs.shift_x, min.shift_x, max.shift_x);
     select_min_max(cs.shift_y, min.shift_y, max.shift_y);
     select_min_max(cs.clk_mode, min.clk_mode, max.clk_mode);
     select_min_max(cs.video_mode, min.video_mode, max.video_mode);
     select_min_max(cs.sync_mode, min.sync_mode, max.sync_mode);
     select_min_max(cs.int_freq, min.int_freq, max.int_freq);
     select_min_max(cs.ext_freq_div, min.ext_freq_div, max.ext_freq_div);
     select_min_max(cs.delay, min.delay, max.delay);
     select_min_max(cs.delay_rise, min.delay_rise, max.delay_rise);
     select_min_max(cs.delay_fall, min.delay_fall, max.delay_fall);
     select_min_max(cs.inv_pin_mask, min.inv_pin_mask, max.inv_pin_mask);
     select_min_max(cs.len_vs, min.len_vs, max.len_vs);
     select_min_max(cs.color_mode, min.color_mode, max.color_mode);
}
///////////////////////////////////////////////////////////////////
