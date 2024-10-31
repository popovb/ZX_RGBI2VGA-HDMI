//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "CaptureSettings.hpp"

#ifndef _ZXRGB_CAPTURE_SETTINGS_CHECKER_HPP_
#define _ZXRGB_CAPTURE_SETTINGS_CHECKER_HPP_

namespace zxrgb {

     class CaptureSettingsChecker {

     public:
	  void check(CaptureSettings&) const;
     };
}
#endif // _ZXRGB_CAPTURE_SETTINGS_CHECKER_HPP_
