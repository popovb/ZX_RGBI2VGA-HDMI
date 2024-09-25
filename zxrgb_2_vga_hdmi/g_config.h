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

extern uint8_t pallete8[];

enum p_clk_mode_t{SELF_SYNC_MODE,EXT_SYNC_MODE,Z80_FREQ_MODE};
enum video_out_mode_t{VGA,HDMI,RGB,COMP};
enum in_sync_mode_t{S_SYNC,C_SYNC};
enum c_mode_t{PAL,NTSC,SECAM};


typedef struct cap_set_t cap_set_t;
struct cap_set_t 
{
     int16_t shX;
     int16_t shY;
     enum p_clk_mode_t p_clk_mode;
     enum video_out_mode_t video_out_mode;
     enum in_sync_mode_t in_sync_mode;
     bool is_3X_Buf;
     uint32_t int_freq;
     uint ext_freq_div;
     uint capture_delay;
     uint capture_delay_rise;
     uint capture_delay_fall;
     uint inv_capture_pin_mask;
     uint16_t len_VS;

     enum c_mode_t c_mode;
     bool is_wide_mode;


}
     ;

//определение PIO и SM для задачи VGA
#define PIO_VGA (pio0)
#define SM_VGA (0)
//определение PIO и SM для задачи HDMI

#define pio_HDMI0 pio0
#define sm_HDMI0 0

//определение PIO для захвата
#define PIO_CAP (pio1)
//номера SM для захвата
#define SM_CAP  (0)

#define V_BUF_W (320)
#define V_BUF_H (320)
#define V_BUF_SZ ((V_BUF_H+1)*V_BUF_W/2)

extern uint8_t g_gbuf[];

#define G_PRINTF_INFO  printf
