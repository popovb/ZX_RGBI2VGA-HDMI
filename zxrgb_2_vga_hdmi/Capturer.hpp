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

     private:
	  const CaptureSettings& cs;

     private:
	  void pin_init() const;
	  void sm_init() const;
	  void dma_init() const;
	  void test_pin_init() const;
	  void captured_pin_init() const;
     };
}
#endif // _ZXRGB_CAPTURER_HPP_
