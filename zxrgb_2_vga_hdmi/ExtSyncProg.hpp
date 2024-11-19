//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PioProg.hpp"
#include "Types.hpp"

#ifndef _ZXRGB_EXT_SYNC_PROG_HPP_
#define _ZXRGB_EXT_SYNC_PROG_HPP_

namespace zxrgb {

     class ExtSyncProg : public PioProg {

     public:
	  ExtSyncProg();

	  void set_delay(u32);
	  void set_ext_freq_div(u32);

     private:
	  static const u8 len = 16;
	  static u16 cmds[len];
     };
}
#endif // _ZXRGB_EXT_SYNC_PROG_HPP_
