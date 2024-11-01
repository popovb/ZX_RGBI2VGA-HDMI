//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "CaptureSettings.hpp"
#include "SettingsLoader.hpp"

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
	  SerialReactor(mode_t, CaptureSettings&);

	  void handle();

	  bool need_to_save() const;

     private:
	  mode_t mode;
	  CaptureSettings& cs;
	  char key[20];
	  int value;
	  bool save;
	  SettingsLoader sl;

     private:
	  void handle0();
	  void handle1() const;
	  bool handle_ping() const;
	  bool handle_mode() const;
	  bool handle_exit() const;
	  bool handle_save();
	  bool check(const char*) const;
     };
}
#endif // _ZXRGB_SERIAL_REACTOR_HPP_
