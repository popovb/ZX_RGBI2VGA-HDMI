//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

// #include "Types.hpp"

#ifndef _ZXRGB_SERIAL_REACTOR_HPP_
#define _ZXRGB_SERIAL_REACTOR_HPP_

namespace zxrgb {

     class SerialReactor {

     public:
	  enum mode_t {
	       Mode0,
	       Mode1,
	  };

     public:
	  SerialReactor(mode_t);

	  void handle() const;

	  bool need_to_save() const;
     };
}
#endif // _ZXRGB_SERIAL_REACTOR_HPP_
