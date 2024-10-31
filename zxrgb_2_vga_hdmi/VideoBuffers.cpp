//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "VideoBuffers.hpp"
#include <cstddef>

///////////////////////////////////////////////////////////////////
namespace zxrgb {

     static VideoBuffers _vb;

     VideoBuffers& get_video_buffers() {
	  return _vb;
     }
}
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
zxrgb::VideoBuffers::VideoBuffers():
     mode(X_1),
     buffer(get_buffer()),
     bufs{
	  buffer.buf,
	  buffer.buf + buffer.sz,
	  buffer.buf + (2 * buffer.sz),
     },
     show{ false, false, false },
     index_in(0),
     index_out(0),
     first(true),
     index_frame(0),
     frame_bufs{ 0, 0, 0 }
{
     return;
}

void zxrgb::VideoBuffers::set_mode(mode_t v) {
     mode = v;
}

// __not_in_flash_func()
zxrgb::u8* zxrgb::VideoBuffers::get_out() {
     if (first) return bufs[0];
     if (mode == X_1) return bufs[0];

     u8 idx = (index_out + 1) % 3;
     if (! show[idx]) {
	  show[index_out] = true;
	  index_out = idx;
	  return bufs[index_out];
     }

     idx = (index_out + 2) % 3;
     if(! show[idx]) {
	  show[index_out] = true;
	  index_out = idx;
	  return bufs[index_out];
     }

     return bufs[index_out];
}

// __not_in_flash_func()
zxrgb::u8* zxrgb::VideoBuffers::get_in() {
     if (mode == X_1) return bufs[0];

     if (index_in >= 0) {
	  ++index_frame;
	  if (index_frame > 1) first = false;
	  frame_bufs[index_in] = index_frame;
	  show[index_in] = false;
     }

     u8 idx = (index_in + 1) % 3;
     if (show[idx]) {
	  index_in = idx;
	  return bufs[index_in];
     }

     idx = (index_in + 2) % 3;
     if (show[idx]) {
	  index_in = idx;
	  return bufs[index_in];
     }

     return NULL;
}
///////////////////////////////////////////////////////////////////
