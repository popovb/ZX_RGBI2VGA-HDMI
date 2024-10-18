//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Buffer.hpp"

///////////////////////////////////////////////////////////////////
namespace zxrgb {

     static Buffer _bu;

     Buffer& get_buffer() {
	  return _bu;
     }
}
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
zxrgb::u16 zxrgb::Buffer::width() const {
     return w;
}

zxrgb::u16 zxrgb::Buffer::height() const {
     return h;
}

zxrgb::u8* zxrgb::Buffer::ptr() {
     return buf;
}
///////////////////////////////////////////////////////////////////
