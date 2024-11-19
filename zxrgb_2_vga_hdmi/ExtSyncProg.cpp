//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "ExtSyncProg.hpp"
/*
zxrgb::u16
zxrgb::ExtSyncProg::cmds[] =
{
     // .wrap_target
     0xa042, //   0: nop
     0x4008, //   1: in pins, 8
     0x8020, //   2: push block
     0xa842, //   3: nop [8]
     0x00c1, //   4: jmp pin, 1
     0x4008, //   5: in pins, 8
     0x8020, //   6: push block
     0x00c0, //   7: jmp pin, 0
     0x00c0, //   8: jmp pin, 0
     0x00c0, //   9: jmp pin, 0
     0x00c0, //  10: jmp pin, 0
     0x00c0, //  11: jmp pin, 0
     0x00c0, //  12: jmp pin, 0
     0x00c0, //  13: jmp pin, 0
     0x00c0, //  14: jmp pin, 0
     0x00c0, //  15: jmp pin, 0
     0x0005, //  16: jmp 5
     // .wrap
};

zxrgb::ExtSyncProg::ExtSyncProg() {
     prog.instructions = cmds;
     prog.length = 17;
     prog.origin = -1;
}
*/
void zxrgb::ExtSyncProg::set_delay(u32 v) {
     cmds[0] |= ((v & 0b11111) << 8);
}
