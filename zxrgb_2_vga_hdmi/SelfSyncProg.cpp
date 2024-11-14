//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "SelfSyncProg.hpp"

zxrgb::SelfSyncProg::SelfSyncProg() {
     //
     // TODO
     //
}

//       instructions{

//       	  0x0000,
//       }
// {
// //     instructions[0] = 0x0000;
//      return;
// }

/*

  //программа захвата с самосинхронизацией
uint16_t pio_program0_instructions[] = {
    
     //     .wrap_target
     0xa042, //  0: nop               //команда для формирования задержки захвата               
     0x4008, //  1: in     pins, 8                    
     //   0xa042, //  2: nop              //вставка - заменить задержкой прошлой команды         
     0x8020, //  2: push   block                      
     0xa842, //  3: nop                           [8] 
     0x00c1, //  4: jmp    pin, 1 
     0x4008, //  5: in     pins, 8       //подсинхронизация по строчной синхре     
           
     0x8020, //  6: push   block                      
     //  0x00c0, //  6: jmp    pin, 0                     
     0x00c0, //  7: jmp    pin, 0                     
     0x00c0, //  8: jmp    pin, 0                     
     0x00c0, //  9: jmp    pin, 0                     
     0x00c0, //  10: jmp    pin, 0                     
     0x00c0, //  11: jmp    pin, 0                     
     0x00c0, //  12: jmp    pin, 0                     
     0x00c0, //  13: jmp    pin, 0                     
     0x00c0, //  14: jmp    pin, 0 
     //                 
     0x00c0, //  15: jmp    pin, 0                     
   
     0x0005, // 16: jmp    5                          
     //     .wrap



};



 */
