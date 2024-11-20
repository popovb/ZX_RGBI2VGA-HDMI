//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Capturer.hpp"

///////////////////////////////////////////////////////////////////
static const zxrgb::u8 test_pin = 25;
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
zxrgb::Capturer::Capturer(const CaptureSettings& v):
     cs(v)
{
     return;
}

void zxrgb::Capturer::start() const {
     pin_init();
     sm_init();
     dma_init();
     //
     // TODO
     //
}

void zxrgb::Capturer::pin_init() const {
     test_pin_init();
     captured_pin_init();
}
///////////////////////////////////////////////////////////////////
