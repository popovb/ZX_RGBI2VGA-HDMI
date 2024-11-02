//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Flasher.hpp"
#include <hardware/sync.h>
#include <hardware/flash.h>

void zxrgb::Flasher::save(const CaptureSettings& cs) const {
     u32 i = save_and_disable_interrupts();
     flash_range_erase(PICO_FLASH_SIZE_BYTES -
		       FLASH_SECTOR_SIZE,
		       FLASH_SECTOR_SIZE);
     flash_range_program(PICO_FLASH_SIZE_BYTES -
			 FLASH_SECTOR_SIZE,
			 (u8*)&cs,
			 FLASH_PAGE_SIZE);
     restore_interrupts(i);
}
