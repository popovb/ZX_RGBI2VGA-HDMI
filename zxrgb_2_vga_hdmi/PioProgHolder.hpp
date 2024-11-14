//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PioProg.hpp"
#include "PioProgType.hpp"
#include "Types.hpp"

#ifndef _ZXRGB_PIO_PROG_HOLDER_HPP_
#define _ZXRGB_PIO_PROG_HOLDER_HPP_

namespace zxrgb {

     ///////////////////////////////////////////////
     class PioProgHolder {

     public:
	  PioProgHolder();

	  PioProg* get(PioProgType::type_t);

     private:
	  static const u8 len = 5;
	  PioProg* pio_progs[len];
     };
     ///////////////////////////////////////////////

     ///////////////////////////////////////////////
     PioProgHolder& get_pio_prog_holder();
     ///////////////////////////////////////////////
}
#endif // _ZXRGB_PIO_PROG_HOLDER_HPP_
