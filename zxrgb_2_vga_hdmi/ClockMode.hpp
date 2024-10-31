//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#ifndef _ZXRGB_CLOCK_MODE_HPP_
#define _ZXRGB_CLOCK_MODE_HPP_

namespace zxrgb {

     class ClockMode {

     public:
	  enum mode_t {
	       SelfSync,
	       ExtSync,
	       Z80Freq,
	  };
     };
}
#endif // _ZXRGB_CLOCK_MODE_HPP_
