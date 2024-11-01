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
     save(false),
     sl(vv)
{
     return;
}

bool zxrgb::SerialReactor::need_to_save() const {
     return save;
}

void zxrgb::SerialReactor::handle() {
     if (mode == Mode0) return handle0();
     handle1();
}

void zxrgb::SerialReactor::handle0() {
     while (true) {
	  String s = Serial.readStringUntil('\n');
	  if (s.length() == 0) continue;
	  sscanf(s.c_str(), "%19s%d" , key, &value);

	  if (handle_ping()) continue;
	  if (handle_mode()) continue;
	  if (handle_exit()) break;
	  if (handle_save()) break;

	  sl.load(key, value);
     }
}

bool zxrgb::SerialReactor::handle_ping() const {
     if (! check("ping") ) return false;
     Serial.printf("ping ok\n");
     return true;
}

bool zxrgb::SerialReactor::handle_exit() const {
     if (! check("exit") ) return false;
     Serial.printf("exit ok\n");
     return true;
}

bool zxrgb::SerialReactor::handle_mode() const {
     if (! check("mode") ) return false;
     switch (mode) {

     case Mode0:
	  Serial.printf("mode 0\n");
	  break;

     case Mode1:
	  Serial.printf("mode 1\n");
	  break;

     default:
	  break;
     }
     return true;
}

bool zxrgb::SerialReactor::handle_save() {
     if (! check("save") ) return false;
     Serial.printf("saving...\n");
     save = true;
     return true;
}

bool zxrgb::SerialReactor::check(const char* s) const {
     if (strcmp(key, s) == 0) return true;
     return false;
}

void zxrgb::SerialReactor::handle1() const {
     //
     // TODO
     //
}
