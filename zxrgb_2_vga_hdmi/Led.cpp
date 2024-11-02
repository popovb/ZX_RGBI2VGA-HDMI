//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Led.hpp"
#include <Arduino.h>

zxrgb::Led::Led() {
     pinMode(LED_BUILTIN, OUTPUT);
     off();
}
