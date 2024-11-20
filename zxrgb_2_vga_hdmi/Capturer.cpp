//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Capturer.hpp"
#include "CapturedPins.hpp"
#include <Arduino.h>

///////////////////////////////////////////////////////////////////
static const zxrgb::u8 test_pin = 25;
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
zxrgb::Capturer::Capturer(const CaptureSettings& v):
     cs(v)
{
     return;
}

void zxrgb::Capturer::start() const {
     pin_init();
     sm_init();
     dma_init();
     //
     // TODO
     //
}

void zxrgb::Capturer::pin_init() const {
     test_pin_init();
     captured_pin_init();
}

void zxrgb::Capturer::test_pin_init() const {
     gpio_init(test_pin);
     gpio_set_dir(test_pin, GPIO_OUT);
}

void zxrgb::Capturer::captured_pin_init() const {
     const u8 start_pin = CapturedPins::b;
     for (u8 i = 0; i < 7; i++) {
	  u8 pin = start_pin + i;
	  gpio_init(pin);
	  gpio_set_dir(pin, GPIO_OUT);
	  gpio_set_input_hysteresis_enabled(pin, true);
	  if ( (cs.inv_pin_mask >> i) & 1 )
	       gpio_set_inover(pin, GPIO_OVERRIDE_INVERT);
     }
}
///////////////////////////////////////////////////////////////////
