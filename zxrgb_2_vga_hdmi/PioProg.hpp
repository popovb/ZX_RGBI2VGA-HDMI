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
	  pio_program prog;
     };
}
#endif // _ZXRGB_PIO_PROG_HPP_
