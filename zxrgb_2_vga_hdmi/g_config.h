#pragma once
#include "stdio.h"
#include "inttypes.h"
#include "stdbool.h"
//#include "pico/platform.h"
#include "pico.h"
#define FW_VER "0.5A"

#define BOARD_CODE_36LJU22
//#define BOARD_CODE_09LJV23

///////////////////////////////////////////////////////////////////
//конфигурация под конкретные платы
#ifdef   BOARD_CODE_36LJU22

#define HDMI_PIN_invert_diffpairs (0)
#define HDMI_PIN_RGB_notBGR (0)
#define beginHDMI_PIN_data (8)
#define beginHDMI_PIN_clk (14)
#define beginVGA_PIN (8)

#endif
///////////////////////////////////////////////////////////////////

//определение PIO и SM для задачи VGA
#define PIO_VGA (pio0)
#define SM_VGA (0)
//определение PIO и SM для задачи HDMI

#define pio_HDMI0 pio0
#define sm_HDMI0 0

#define G_PRINTF_INFO  printf
