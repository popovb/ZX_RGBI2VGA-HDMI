#pragma once

#include "CaptureSettings.hpp"

extern "C" {
     void set_cap_shx(int sh_x);
     void set_cap_shy(int sh_y);
     void startCapture(zxrgb::CaptureSettings*);
}
