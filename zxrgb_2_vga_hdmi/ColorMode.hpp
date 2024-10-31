//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#ifndef _ZXRGB_COLOR_MODE_HPP_
#define _ZXRGB_COLOR_MODE_HPP_

namespace zxrgb {

     class ColorMode {

     public:
	  enum mode_t {
	       Pal,
	       Ntsc,
	       Secam,
	  };
     };
}
#endif // _ZXRGB_COLOR_MODE_HPP_
