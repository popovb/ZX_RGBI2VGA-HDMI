//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#include "hardware/pio.h"

#ifndef _ZXRGB_PIO_PROG_HPP_
#define _ZXRGB_PIO_PROG_HPP_

namespace zxrgb {

     class PioProg {

     public:
	  virtual ~PioProg() = 0;

	  const pio_program* get_pio_program() const;

     protected:
	  static const u8 len = 17;
	  u16 instructions[len];

     private:
     };
}
#endif // _ZXRGB_PIO_PROG_HPP_
