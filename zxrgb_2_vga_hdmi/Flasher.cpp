//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Flasher.hpp"
#include <hardware/sync.h>
#include <hardware/flash.h>
#include <cstring>

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

void zxrgb::Flasher::load(CaptureSettings& cs) const {
     u32 offset = PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE;
     memcpy(&cs, (u32*)(XIP_BASE + offset), sizeof(CaptureSettings));
}

/*
// Flash-based address of the last sector
#define FLASH_TARGET_OFFSET (PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE)

int *p, addr, value;

// Compute the memory-mapped address, remembering to include the offset for RAM
addr = XIP_BASE +  FLASH_TARGET_OFFSET
    p = (int *)addr; // Place an int pointer at our memory-mapped address
    value = *p; // Store the value at this address into a variable for later use
}


// int data_for_save[FLASH_PAGE_SIZE/sizeof(int)]; 
const int *flash_data_for_save = (const int *) (XIP_BASE + (PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE));


//загружаем ранее сохранённые данные заxвата
     memcpy(&capture_setings,
     flash_data_for_save,
     sizeof(zxrgb::CaptureSettings));

*/
