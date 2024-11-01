//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "SerialReactor.hpp"
#include <Arduino.h>

zxrgb::SerialReactor::SerialReactor(mode_t v, CaptureSettings& vv):
     mode(v),
     cs(vv),
     key{ '\0', },
     value(0),
     save(false)
{
     return;
}

bool zxrgb::SerialReactor::need_to_save() const {
     return save;
}

void zxrgb::SerialReactor::handle() const {
     if (mode == Mode0) return handle0();
     handle1();
}

void zxrgb::SerialReactor::handle0() const {
     while (true) {
	  String s = Serial.readStringUntil('\n');
	  if (s.length() == 0) continue;
	  sscanf(s.c_str(), "%19s%d" , key, &value);

	  if (handle_ping()) continue;
	  if (handle_mode()) continue;
	  if (handle_exit()) break;
	  if (handle_save()) break;
	  
	  //
	  // TODO
	  //
     }
}

bool zxrgb::SerialReactor::handle_ping() const {
     if (! check("ping") ) return false;
     Serial.printf("ping ok\n");
     return true;
}

void zxrgb::SerialReactor::handle1() const {
     //
     // TODO
     //
}
