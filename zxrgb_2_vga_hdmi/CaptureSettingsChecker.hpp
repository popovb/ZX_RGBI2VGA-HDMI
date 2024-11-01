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

     private:
	  static const CaptureSettings min;
	  static const CaptureSettings max;

     private:
	  template<class T>
	  void check_min_max(T&, T, T) const;
     };
}

///////////////////////////////////////////////////////////////////
template<class T> void zxrgb::CaptureSettingsChecker::
check_min_max(T& value, T min, T max) const {
     value = (value < min) ? min : value;
     value = (value > max) ? max : value;
}
///////////////////////////////////////////////////////////////////
#endif // _ZXRGB_CAPTURE_SETTINGS_CHECKER_HPP_
