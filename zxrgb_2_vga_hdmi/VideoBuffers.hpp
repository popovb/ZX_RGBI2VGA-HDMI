//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

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
	  u8* get_out() const;

     private:
     };
     ///////////////////////////////////////////////

     ///////////////////////////////////////////////
     VideoBuffers& get_video_buffers();
     ///////////////////////////////////////////////
}
#endif // _ZXRGB_VIDEO_BUFFERS_HPP_
