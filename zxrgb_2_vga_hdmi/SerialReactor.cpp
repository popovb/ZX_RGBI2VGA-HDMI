//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "SerialReactor.hpp"

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

/*
	  void handle() const;

*/
