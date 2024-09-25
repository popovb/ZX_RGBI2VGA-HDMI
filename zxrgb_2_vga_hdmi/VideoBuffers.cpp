//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "VideoBuffers.hpp"

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
     mode(X_1)
{
     return;
}

void zxrgb::VideoBuffers::set_mode(mode_t v) {
     mode = v;
}
///////////////////////////////////////////////////////////////////
