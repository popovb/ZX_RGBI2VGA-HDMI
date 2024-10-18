//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Buffer.hpp"

namespace zxrgb {

     static Buffer _bu;

     Buffer& get_buffer() {
	  return _bu;
     }
}
