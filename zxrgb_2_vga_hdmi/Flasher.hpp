//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "CaptureSettings.hpp"

#ifndef _ZXRGB_FLASHER_HPP_
#define _ZXRGB_FLASHER_HPP_

namespace zxrgb {

     class Flasher {

     public:
	  // Flasher();

	  void save(const CaptureSettings&) const;
     };
}
#endif // _ZXRGB_FLASHER_HPP_

/*
uint32_t ints = save_and_disable_interrupts();
flash_range_erase((PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE), FLASH_SECTOR_SIZE);                           
flash_range_program((PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE), ( uint8_t*) &capture_setings, FLASH_PAGE_SIZE);
restore_interrupts (ints);
*/
