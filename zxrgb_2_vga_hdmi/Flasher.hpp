//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "CaptureSettings.hpp"

#ifndef _ZXRGB_FLASHER_HPP_
#define _ZXRGB_FLASHER_HPP_

namespace zxrgb {

     class Flasher {

     public:
	  Flasher();

	  void load(CaptureSettings&) const;
	  void save(const CaptureSettings&) const;
     };
}
#endif // _ZXRGB_FLASHER_HPP_
