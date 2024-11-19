//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PioProg.hpp"

const pio_program* zxrgb::PioProg::get_pio_program() const {
     return &prog;
}
// zxrgb::PioProg::~PioProg() {
//      return;
// }
