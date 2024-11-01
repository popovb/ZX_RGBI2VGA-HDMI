//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "CaptureSettings.hpp"

#ifndef _ZXRGB_SETTINGS_LOADER_HPP_
#define _ZXRGB_SETTINGS_LOADER_HPP_

namespace zxrgb {

     class SettingsLoader {

     public:
	  SettingsLoader(CaptureSettings&);

	  void load(const char*, int) const;
     };
}
#endif // _ZXRGB_SETTINGS_LOADER_HPP_
