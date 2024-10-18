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
     first(true)
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
///////////////////////////////////////////////////////////////////
/*
 * #include "g_config.h"
 * uint8_t* v_bufs[3]={g_gbuf,g_gbuf+V_BUF_SZ,g_gbuf+2*V_BUF_SZ};
 *
 * bool is_show_vbuf[]={false,false,false};
 *
 * int inxVbufIn=0;
 * int inxVbufOut=0;
 * bool is_3x_bufmode=false;
 * bool is_first_image=true;
 *

uint64_t inx_frame=0;
uint64_t i_frame_vbuf[3]={0,0,0};

void* __not_in_flash_func(v_buf_get_in)()
{
     if (!is_3x_bufmode) return v_bufs[0];

        

     if (inxVbufIn>=0)
     {
	  inx_frame++;
	  if ((inx_frame)>1) is_first_image=false;
	  i_frame_vbuf[inxVbufIn]=inx_frame;
	  is_show_vbuf[inxVbufIn]=false;
     }
        
     if(is_show_vbuf[(inxVbufIn+1)%3]) 
     {
	  inxVbufIn=(inxVbufIn+1)%3;
	  return v_bufs[inxVbufIn];
     }

     if(is_show_vbuf[(inxVbufIn+2)%3]) 
     {
	  inxVbufIn=(inxVbufIn+2)%3;
	  return v_bufs[inxVbufIn];
     }

     return NULL;
};
*/
