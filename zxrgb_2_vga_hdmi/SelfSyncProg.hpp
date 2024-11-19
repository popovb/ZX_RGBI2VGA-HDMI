//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PioProg.hpp"
#include "Types.hpp"

#ifndef _ZXRGB_SELF_SYNC_PROG_HPP_
#define _ZXRGB_SELF_SYNC_PROG_HPP_

namespace zxrgb {

     class SelfSyncProg : public PioProg {

     public:
	  SelfSyncProg();

	  void set_delay(u32);

     private:
	  static const u8 len = 17;
	  static u16 cmds[len];
     };
}
#endif // _ZXRGB_SELF_SYNC_PROG_HPP_
