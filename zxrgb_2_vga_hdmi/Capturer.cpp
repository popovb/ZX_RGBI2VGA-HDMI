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
     cs(v),
     pio(pio1)
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

     switch (cs.clk_mode) {

     case ClockMode::SelfSync:
	  offset = add_selfsync_prog(sm_conf);
	  break;

     case ClockMode::ExtSync:
	  offset = add_extsync_prog(sm_conf);
	  break;

     case ClockMode::Z80Freq:
	  offset = add_z80freq_prog(sm_conf);
	  break;

     default:
	  break;
     }


     //
     // TODO
     //
}

int zxrgb::Capturer::add_program(const PioProg& pp,
				 pio_sm_config& sm_conf) const {
     int offset = pio_add_program(pio, pp.get_pio_program());
     sm_conf = pio_get_default_sm_config();
     sm_config_set_wrap(&sm_conf,
			offset,
			offset + (pp.get_pio_program()->length - 1));
     return offset;
}

int zxrgb::Capturer::add_selfsync_prog(pio_sm_config& sm_conf) const {
     auto& pph = get_pio_prog_holder();
     auto* s = pph.get(PioProgType::SelfSync);
     if (s == nullptr) return -1;
     auto& pp = (*(SelfSyncProg*)s);
     pp.set_delay(cs.delay);
     return add_program(pp, sm_conf);
}

int zxrgb::Capturer::add_extsync_prog(pio_sm_config& sm_conf) const {
     auto& pph = get_pio_prog_holder();
     auto* s = pph.get(PioProgType::ExtSync);
     if (s == nullptr) return -1;
     auto& pp = (*(ExtSyncProg*)s);
     pp.set_delay(cs.delay);
     pp.set_ext_freq_div(cs.ext_freq_div);
     return add_program(pp, sm_conf);
}

int zxrgb::Capturer::add_z80freq_prog(pio_sm_config& sm_conf) const {
     auto& pph = get_pio_prog_holder();
     auto* s = pph.get(PioProgType::Z80Freq);
     if (s == nullptr) return -1;
     auto& pp = (*(Z80FreqProg*)s);
     pp.set_delay_rise(cs.delay_rise);
     pp.set_delay_fall(cs.delay_fall);
     return add_program(pp, sm_conf);
}
///////////////////////////////////////////////////////////////////
