//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "CapturedPins.hpp"
// #include "VgaPins.hpp"
// #include "HdmiPins.hpp"

#ifndef _ZXRGB_PINS_HPP_
#define _ZXRGB_PINS_HPP_

namespace zxrgb {

     class Pins {

     public:
	  static CapturedPins captured;
	  // static VgaPins vga;
	  // static HdmiPins hdmi;
     };
}
#endif // _ZXRGB_PINS_HPP_
