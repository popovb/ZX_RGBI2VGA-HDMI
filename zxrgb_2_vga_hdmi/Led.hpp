//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "CaptureSettings.hpp"

#ifndef _ZXRGB_LED_HPP_
#define _ZXRGB_LED_HPP_

namespace zxrgb {

     class Led {

     public:
	  Led();

	  void off() const;
	  void on() const;
     };
}
#endif // _ZXRGB_LED_HPP_
