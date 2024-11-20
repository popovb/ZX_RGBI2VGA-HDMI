//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PioProg.hpp"
#include "Types.hpp"

#ifndef _ZXRGB_Z80_FREQ_PROG_HPP_
#define _ZXRGB_Z80_FREQ_PROG_HPP_

namespace zxrgb {

     class Z80FreqProg : public PioProg {

     public:
	  Z80FreqProg();

	  void set_delay_rise(u32);
	  void set_delay_fall(u32);

     private:
	  static const u8 len = 8;
	  static u16 cmds[len];
     };
}
#endif // _ZXRGB_Z80_FREQ_PROG_HPP_
