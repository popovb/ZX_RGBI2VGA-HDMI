//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

// #include "Types.hpp"
// #include "Buffer.hpp"

#ifndef _ZXRGB_PICTURES_DRAWER_HPP_
#define _ZXRGB_PICTURES_DRAWER_HPP_

namespace zxrgb {

     class PicturesDrawer {

     public:
	  void hello() const;
     };
}
#endif // _ZXRGB_PICTURES_DRAWER_HPP_
/*
  static void draw_hello_image() {
  using namespace zxrgb;
  auto& vbs = get_video_buffers();
  uint8_t* vbuf = vbs.get_out();
  // uint8_t* vbuf1=vbuf+V_BUF_SZ;
  // uint8_t* vbuf2=vbuf1+V_BUF_SZ;

  auto& bf = get_buffer();
  for (int y = 0; y < bf.height(); y++)
  for (int x=0; x < bf.width() / 2; x++) {
  uint8_t i=(y/15)&0x0f;
  uint8_t c=((i&1)<<3)|(i>>1);
  c|=c<<4;

  //uint8_t c=img01[y*(V_BUF_W/2)+x];
  *vbuf++=c;
  // *vbuf1++=c;
  // *vbuf2++=c;
  }
    

  }
*/
