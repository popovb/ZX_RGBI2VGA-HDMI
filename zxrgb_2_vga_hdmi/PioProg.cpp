//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PioProg.hpp"

zxrgb::PioProg::~PioProg() {
     return;
}

const pio_program* zxrgb::PioProg::get_pio_program() const {
     return &prog;
}
