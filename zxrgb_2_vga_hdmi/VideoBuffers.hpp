//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"
#include "Buffer.hpp"

#ifndef _ZXRGB_VIDEO_BUFFERS_HPP_
#define _ZXRGB_VIDEO_BUFFERS_HPP_

namespace zxrgb {

     ///////////////////////////////////////////////
     class VideoBuffers {

     public:
	  enum mode_t {
	       X_1,
	       X_3,
	  };

     public:
	  VideoBuffers();

	  void set_mode(mode_t);

	  u8* get_in() const;
	  u8* get_out();

     private:
	  mode_t mode;

     private:
	  Buffer& buffer;
	  u8* bufs[3];
	  bool show[3];
	  u8 index_in;
	  u8 index_out;
	  bool first;
     };
     ///////////////////////////////////////////////

     ///////////////////////////////////////////////
     VideoBuffers& get_video_buffers();
     ///////////////////////////////////////////////
}
#endif // _ZXRGB_VIDEO_BUFFERS_HPP_
