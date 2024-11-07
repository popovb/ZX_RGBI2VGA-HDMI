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

void zxrgb::SerialReactor::handle1() const {
     String s = Serial.readStringUntil('\n');
     if (s.length() == 0) return;
     sscanf(s.c_str(), "%19s%d" , key, &value);

     if (handle_ping()) return;
     if (handle_reset()) return;
     if (handle_restart()) return;
     if (handle_mode()) return;
     //
     // TODO
     //
}
     /*
     if (strcmp(s_key, "reset")==0 || strcmp(s_key, "restart")==0 ) {printf("reset...\n");rp2040.restart();};
     if (strcmp(s_key+1, "cap_sh_x")==0) {if(s_key[0]=='w') set_cap_shx(s_data); return;}
     if (strcmp(s_key+1, "cap_sh_y")==0) {if(s_key[0]=='w') set_cap_shy(s_data); return;}
     */
bool zxrgb::SerialReactor::handle_ping() const {
     if (! check("ping") ) return false;
     Serial.printf("ping ok\n");
     return true;
}

bool zxrgb::SerialReactor::handle_reset() const {
     if (! check("reset") ) return false;
     print_reset();
     restart();
     return true;
}

void zxrgb::SerialReactor::print_reset() const {
     Serial.printf("reset...\n");
}

void zxrgb::SerialReactor::restart() const {
     rp2040.restart();
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
