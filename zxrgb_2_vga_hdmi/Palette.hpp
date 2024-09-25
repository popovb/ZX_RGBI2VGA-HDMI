//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Types.hpp"

#ifndef _ZXRGB_PALETTE_HPP_
#define _ZXRGB_PALETTE_HPP_

namespace zxrgb {

     ///////////////////////////////////////////////
     class Palette {

     public:
	  Palette();

	  u8 operator[](u8) const;

     private:
	  static const u8 N = 16;

	  u8 plt[N];
     };
     ///////////////////////////////////////////////

     ///////////////////////////////////////////////
     const Palette& get_palette();
     ///////////////////////////////////////////////
}
#endif // _ZXRGB_PALETTE_HPP_
