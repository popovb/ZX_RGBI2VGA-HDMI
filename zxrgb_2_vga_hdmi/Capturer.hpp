//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "CaptureSettings.hpp"

#ifndef _ZXRGB_CAPTURER_HPP_
#define _ZXRGB_CAPTURER_HPP_

namespace zxrgb {

     class Capturer {

     public:
	  Capturer(const CaptureSettings&);

	  void start() const;
     };
}
#endif // _ZXRGB_CAPTURER_HPP_
