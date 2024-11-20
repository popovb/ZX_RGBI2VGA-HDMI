//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Capturer.hpp"

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
