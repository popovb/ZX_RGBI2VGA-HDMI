//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Capturer.hpp"
#include "CapturedPins.hpp"
#include "PioProgHolder.hpp"
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

void zxrgb::Capturer::sm_init() const {
     int offset;
     pio_sm_config sm_conf;
     auto& pph = get_pio_prog_holder();

     switch (cs.clk_mode) {

     case ClockMode::SelfSync:
     {
	  auto* s = pph.get(PioProgType::SelfSync);
	  if (s == nullptr) break;
	  auto& pp = (*(SelfSyncProg*)s);
	  pp.set_delay(cs.delay);
	  offset = add_program(pp, sm_conf);
	  /*
	  ///
	  offset = pio_add_program(PIO_CAP, pp.get_pio_program());
	  sm_conf = pio_get_default_sm_config();
	  sm_config_set_wrap(&sm_conf,
			     offset,
			     offset + (pp.get_pio_program()->length - 1));
	  ///
	  */
	  break;
     }

     case ClockMode::ExtSync:
     {
	  auto* s = pph.get(PioProgType::ExtSync);
	  if (s == nullptr) break;
	  auto& pp = (*(ExtSyncProg*)s);
	  pp.set_delay(cs.delay);
	  pp.set_ext_freq_div(cs.ext_freq_div);
	  offset = add_program(pp, sm_conf);
	  /*
	  ///
	  offset = pio_add_program(PIO_CAP, pp.get_pio_program());
	  sm_conf = pio_get_default_sm_config();
	  sm_config_set_wrap(&sm_conf,
			     offset,
			     offset + (pp.get_pio_program()->length - 1));
	  ///
	  */
	  break;
     }

     case ClockMode::Z80Freq:
     {
	  auto* s = pph.get(PioProgType::Z80Freq);
	  if (s == nullptr) break;
	  auto& pp = (*(Z80FreqProg*)s);
	  pp.set_delay_rise(cs.delay_rise);
	  pp.set_delay_fall(cs.delay_fall);
	  offset = add_program(pp, sm_conf);
	  /*
	  ///
	  offset = pio_add_program(PIO_CAP, pp.get_pio_program());
	  sm_conf = pio_get_default_sm_config();
	  sm_config_set_wrap(&sm_conf,
			     offset,
			     offset + (pp.get_pio_program()->length - 1));
	  ///
	  */
	  break;
     }

     default:
	  break;
     }


     //
     // TODO
     //
}
///////////////////////////////////////////////////////////////////
