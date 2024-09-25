//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _ZXRGB_BUFFER_HPP_
#define _ZXRGB_BUFFER_HPP_

namespace zxrgb {

     ///////////////////////////////////////////////
     class Buffer {

     public:
	  u16 width() const;
	  u16 height() const;
	  u8* ptr() const;

     private:
	  static const u16 w      = 320;
	  static const u16 h      = 320;
	  static constexpr u32 sz = (h + 1) * w / 2;
	  static u8 buf[sz];
     };
     ///////////////////////////////////////////////

     ///////////////////////////////////////////////
     Buffer& get_buffer();
     ///////////////////////////////////////////////
}
#endif // _ZXRGB_BUFFER_HPP_
