//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Flasher.hpp"
#include <hardware/sync.h>
#include <hardware/flash.h>
#include <cstring>

zxrgb::Flasher::Flasher():
     offset(PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE)
{
     return;
}

void zxrgb::Flasher::save(const CaptureSettings& cs) const {
     u32 i = save_and_disable_interrupts();
     flash_range_erase(offset, FLASH_SECTOR_SIZE);
     flash_range_program(offset, (u8*)&cs, FLASH_PAGE_SIZE);
     restore_interrupts(i);
}

void zxrgb::Flasher::load(CaptureSettings& cs) const {
     memcpy(&cs, (u32*)(XIP_BASE + offset), sizeof(CaptureSettings));
}
