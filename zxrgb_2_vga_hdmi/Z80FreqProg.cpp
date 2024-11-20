//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Z80FreqProg.hpp"
#include "CapturedPins.hpp"

static zxrgb::u16 F = zxrgb::CapturedPins::f;
/*
zxrgb::u16
zxrgb::Z80FreqProg::cmds[] =
{
     0xa042,            //  0: nop
     0xe020,            //  1: set x, 0
     (u16)(0x2000 | F), //  2: wait 1 gpio, 0
     0x4008,            //  3: in pins, 8
     (u16)(0x2080 | F), //  4: wait 0 gpio, 0
     0x0042,            //  5: jmp x--, 2
     0x8020,            //  6: push block
     0x00c1,            //  7: jmp pin, 1
     0xe020,            //  8: set x, 0
     (u16)(0x2000 | F), //  9: wait 1 gpio, 0
     0x00c0,            // 10: jmp pin, 0
     0x4008,            // 11: in pins, 8
     (u16)(0x2080 | F), // 12: wait 0 gpio, 1
     0x0049,            // 13: jmp x--, 9
     0x8020,            // 14: push block
     0x0008,            // 15: jmp 8
};
*/
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
