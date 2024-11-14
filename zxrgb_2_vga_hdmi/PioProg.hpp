//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "hardware/pio.h"

#ifndef _ZXRGB_PIO_PROG_HPP_
#define _ZXRGB_PIO_PROG_HPP_

namespace zxrgb {

     class PioProg {

     public:
	  PioProg();
	  virtual ~PioProg() = 0;

	  const pio_program* get_pio_program() const;

     private:
     };
}
#endif // _ZXRGB_PIO_PROG_HPP_
