//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PicturesDrawer.hpp"
#include "VideoBuffers.hpp"
#include "Buffer.hpp"

void zxrgb::PicturesDrawer::hello() const {
     auto& vbs = get_video_buffers();
     uint8_t* vbuf = vbs.get_out();
     auto& bf = get_buffer();

     for (int y = 0; y < bf.height(); y++) {
	  for (int x = 0; x < bf.width() / 2; x++) {
	       u8 i = (y / 15) & 0x0F;
	       u8 c = ((i & 1) << 3) | (i >> 1);
	       c |= c << 4;
	       *vbuf++ = c;
	  }
     }
}
