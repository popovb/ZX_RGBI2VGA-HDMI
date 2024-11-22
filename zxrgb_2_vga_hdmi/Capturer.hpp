//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "CaptureSettings.hpp"
#include "PioProg.hpp"

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

#ifndef _ZXRGB_CAPTURER_HPP_
#define _ZXRGB_CAPTURER_HPP_

namespace zxrgb {

     class Capturer {

     public:
	  Capturer(const CaptureSettings&);

	  void start() const;

     private:
	  const CaptureSettings& cs;
	  PIO pio;

     private:
	  void pin_init() const;
	  void sm_init() const;
	  void dma_init() const;
	  void test_pin_init() const;
	  void captured_pin_init() const;
	  int add_program(const PioProg&, pio_sm_config&) const;
     };
}
#endif // _ZXRGB_CAPTURER_HPP_
