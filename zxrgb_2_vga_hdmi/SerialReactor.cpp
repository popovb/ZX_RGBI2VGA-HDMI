//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "SerialReactor.hpp"

zxrgb::SerialReactor::SerialReactor(mode_t v):
     mode(v),
     key{ '\0', },
     value(0),
     save(false)
{
     return;
}

/*
	  void handle() const;

	  bool need_to_save() const;

     private:
	  mode_t mode;
	  char key[20];
	  int value;
	  bool save;
*/
