//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _ZXRGB_CAPTURED_PINS_HPP_
#define _ZXRGB_CAPTURED_PINS_HPP_

namespace zxrgb {

     class CapturedPins {

     public:
	  static const u8 b     = 0; // D0_CAP_PIN
	  static const u8 g     = 1;
	  static const u8 r     = 2;
	  static const u8 i     = 3;
	  static const u8 s_syn = 4; // HS_PIN
	  static const u8 k_syn = 5;
	  static const u8 f     = 6; // F_CAP_PIN
     };
}
#endif // _ZXRGB_CAPTURED_PINS_HPP_
