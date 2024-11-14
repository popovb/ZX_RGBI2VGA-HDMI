//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "PioProgHolder.hpp"

///////////////////////////////////////////////////////////////////
namespace zxrgb {

     static PioProgHolder _pph;

     PioProgHolder& get_pio_prog_holder() {
	  return _pph;
     }
}
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
zxrgb::PioProgHolder::PioProgHolder():
     pio_progs{
	  &ssp,
	  nullptr,
     }
{
     return;
}

zxrgb::PioProg* zxrgb::PioProgHolder::get(PioProgType::type_t v) {
     if (v >= len) return nullptr;
     return pio_progs[v];
}
///////////////////////////////////////////////////////////////////
