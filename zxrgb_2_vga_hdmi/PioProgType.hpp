//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#ifndef _ZXRGB_PIO_PROG_TYPE_HPP_
#define _ZXRGB_PIO_PROG_TYPE_HPP_

namespace zxrgb {

     class PioProgType {

     public:
	  enum type_t {
	       SelfSync = 0,
	       ExtSync  = 1,
	       Z80Freq  = 2,
	       Vga      = 3,
	       Hdmi     = 4,
	  };
     };
}
#endif // _ZXRGB_PIO_PROG_TYPE_HPP_
