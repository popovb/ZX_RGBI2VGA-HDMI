//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Z80FreqProg.hpp"
#include "CapturedPins.hpp"

static zxrgb::u16 F = zxrgb::CapturedPins::f;

zxrgb::u16
zxrgb::Z80FreqProg::cmds[] =
{
     (u16)(0x2080 | F), //  0: wait 1 gpio, 0
     0xa042,            //  1: nop
     0x4008,            //  2: in pins, 8
     0x8020,            //  3: push block
     (u16)(0x2000 | F), //  4: wait 0 gpio, 0
     0xa042,            //  5: nop
     0x4008,            //  6: in pins, 8
     0x8020,            //  7: push block
};

zxrgb::Z80FreqProg::Z80FreqProg() {
     prog.instructions = cmds;
     prog.length = 8;
     prog.origin = -1;
}

void zxrgb::Z80FreqProg::set_delay_rise(u32 v) {
     cmds[1] |= ((v & 0b11111) << 8);
}

void zxrgb::Z80FreqProg::set_delay_fall(u32 v) {
     cmds[5] |= ((v & 0b11111) << 8);
}
