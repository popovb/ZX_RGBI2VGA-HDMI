//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#ifndef _ZXRGB_VIDEO_MODE_HPP_
#define _ZXRGB_VIDEO_MODE_HPP_

namespace zxrgb {

     class VideoMode {

     public:
	  enum mode_t {
	       Vga,
	       Hdmi,
	       Rgb,
	       Comp,
	  };
     };
}
#endif // _ZXRGB_VIDEO_MODE_HPP_
