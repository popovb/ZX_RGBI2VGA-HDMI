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
     };
     ///////////////////////////////////////////////

     ///////////////////////////////////////////////
     const Palette& get_palette();
     ///////////////////////////////////////////////
}
#endif // _ZXRGB_PALETTE_HPP_

/*
  u8 pallete8[]= {
  0b00000000,
  0b00100000,
  0b00001000,
  0b00101000,
  0b00000010,
  0b00100010,
  0b00001010,
  0b00101010,

  0b00000000,
  0b00110000,
  0b00001100,
  0b00111100,
  0b00000011,
  0b00110011,
  0b00001111,
  0b00111111,

  };
*/
