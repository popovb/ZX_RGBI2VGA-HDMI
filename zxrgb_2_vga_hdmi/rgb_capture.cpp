// #include <stdio.h>
// #include "pico/stdlib.h"
// #include "hardware/clocks.h"
// #include "hardware/structs/pll.h"
// #include "hardware/irq.h"
// #include "PIO_capture_program.h"

#include "rgb_capture.h"
#include "CapturedPins.hpp"
#include "VideoBuffers.hpp"
#include "Buffer.hpp"
#include "CaptureSettingsChecker.hpp"
#include "PioProgHolder.hpp"
#include "SelfSyncProg.hpp"

#include <string.h>
#include <hardware/structs/systick.h>
#include <hardware/dma.h>
#include <Arduino.h>

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

//определение PIO для захвата
#define PIO_CAP (pio1)
//номера SM для захвата
#define SM_CAP  (0)

using namespace zxrgb;

static u16 F_CAP_PIN  = CapturedPins::f;
static u16 D0_CAP_PIN = CapturedPins::b;
static u16 HS_PIN     = CapturedPins::s_syn;

//#define MIN(x,y) ((x)<(y)?(x):(y))
//массив палитры
uint8_t convertArr[256];

zxrgb::CaptureSettings cap_set = {
     .shift_x = 40,
     .shift_y = 40,
     .clk_mode = ClockMode::SelfSync,
     .video_mode = VideoMode::Vga,
     .sync_mode = SyncMode::S,
     .int_freq = 6000000,
     .ext_freq_div = 2,
     .delay = 0,
     .delay_rise = 0,
     .delay_fall = 0,
     .inv_pin_mask = 0,
     .len_vs = 250,
     .color_mode = ColorMode::Pal
};

void set_cap_data(zxrgb::CaptureSettings* cap_data) {
     memcpy(&cap_set, cap_data, sizeof(zxrgb::CaptureSettings));
     CaptureSettingsChecker csc;
     csc.check(*cap_data);
     // check_cap_data(&cap_set);
};

#define TST_PIN (25)

uint8_t* capture_buf;//=g_gbuf;
//bool is_disable_INT=false;

int dma_chan;

#define SIZE_LINE_CAPTURE (1024)
//количество буферов ДМА можно увеличить, если будет подёргивание
#define N_DMA_BUF_CAPTURE 8
#define SIZE_DMA_BUF_CAPTURE (SIZE_LINE_CAPTURE*N_DMA_BUF_CAPTURE)

// static uint8_t DMA_BUF_CAP[2][SIZE_DMA_BUF_CAPTURE];
// static uint8_t* DMA_BUF_ADDR_CAP[2];

static uint32_t DMA_BUF_CAP[2][SIZE_DMA_BUF_CAPTURE/4];
static uint32_t* DMA_BUF_ADDR_CAP[2];


uint32_t i_frame=0;


void __not_in_flash_func(dma_handler_capture()) 
{
     static uint32_t inx_buf_dma;  
     dma_hw->ints1 = 1u << dma_chan;
     dma_channel_set_read_addr(dma_chan,&DMA_BUF_ADDR_CAP[inx_buf_dma&1], false);

     int sh_x=cap_set.shift_x;
     int sh_y=cap_set.shift_y;
     bool is_csync=cap_set.sync_mode;
     int len_VS_pix=cap_set.len_vs;

     uint8_t* buf8=(uint8_t*)DMA_BUF_CAP[inx_buf_dma&1];
     inx_buf_dma++;
     gpio_put(TST_PIN,i_frame&0x20);


     static int x_s;
     static int y_s;
     static uint8_t pix8_s;


    
     uint8_t pix8 = pix8_s;
     int x = x_s;
     int y = y_s;

     auto& bf =  get_buffer();
     static uint8_t* cap_buf8s = bf.ptr();
     uint8_t* cap_buf8=cap_buf8s;

     static uint inx_VSs=0;
     uint inx_VS=inx_VSs;
   
     // is_csync=false;
     uint8_t mask_sync0=0x30;//маска синхросигналов

     if (is_csync) mask_sync0=0x10;
     for(int k=(SIZE_DMA_BUF_CAPTURE*1);k--;)
     {
	  uint8_t val8=*buf8++;
	  x++;

	  if (((val8&mask_sync0)!=mask_sync0))//есть активные синхросигналы
	  {
	       //if (inx_VS>1500) break; //ограничение длины синхры
	       if (inx_VS==5)//минимальная длина синхроимпульса 
	       {
		    y++;
		    //обновляем указатель на следующею строку в буфере
		    if ((y>=0)&&(capture_buf!=NULL))
			 cap_buf8 =
			      &(((uint8_t*)capture_buf)[y * bf.width() / 2]);
	       }
	       inx_VS++;
	       x=-sh_x-1;
	       if (is_csync) 
	       {
                    if (inx_VS<len_VS_pix) continue;
	       }
	       else
	       {
                    if ((val8&0x20)!=0) continue;
	       };
            
	       if(y >= 0) {
                    if (i_frame > 10) {
			 auto& vbs = get_video_buffers();
			 capture_buf = vbs.get_in();
		    }
                    i_frame++;                
                    // inx_VS=0;
	       }

	       y=-sh_y-1;
	       continue;
	  }
    
     


	  if (x&1)
	  {                  
	       if (capture_buf==NULL) continue;     
	       if ((x<0)||(y<0)) continue;
	       if ( (x >= bf.width()) ||
		    (y >= bf.height()) ) { continue;};
                             
	       uint8_t c_i=(pix8&0xf)|(val8<<4); 
	       *cap_buf8++=convertArr[c_i];
                                                                 
	  }
	  else
	  {                
	       inx_VS=0;
	       pix8=val8;
	  }

     }
    
     x_s=x;
     y_s=y;
     pix8_s=pix8;
     cap_buf8s=cap_buf8;
     inx_VSs=inx_VS;

}
/*
void startCapture(CaptureSettings* cap_data) {   
     // // memcpy(&cap_set,cap_data,sizeof(cap_set_t));
     // set_cap_data(cap_data);
     // //check_cap_data(&cap_set);

     // for(int i=0;i<256;i++) {
     // 	  uint8_t ch=i>>4;
     // 	  uint8_t cl=i&0xf;
     // 	  convertArr[i]=(ch<<4)|cl;
     // }

     ----------------------
     // // gpio_init(TST_PIN);
     // // gpio_set_dir(TST_PIN,GPIO_OUT);
    
     // // gpio_init(F_CAP_PIN);
     // // gpio_set_dir(F_CAP_PIN,GPIO_IN); 

     // uint pin=D0_CAP_PIN;
     // //инверсия входных сигналов
     // int inv_mask = cap_set.inv_pin_mask;
     // for(int i=0;i<7;i++)
     // {
     // 	  gpio_init(pin+i);
     // 	  gpio_set_dir(pin+i,GPIO_IN);  
     // 	  gpio_set_input_hysteresis_enabled(pin+i,true);
     //   if (inv_mask&1) gpio_set_inover(pin+i,GPIO_OVERRIDE_INVERT);
     // 	  inv_mask>>=1;
     // }
     -----------------------------------

     int sm=SM_CAP;
     
     --------------------------------------------
     uint offset;
     pio_sm_config c;
     auto& pph = get_pio_prog_holder();
     switch (cap_set.clk_mode) {

     case ClockMode::SelfSync:
     {
	  auto* s = pph.get(PioProgType::SelfSync);
	  if (s == nullptr) break;
	  auto& pp = (*(SelfSyncProg*)s);
	  pp.set_delay(cap_set.delay);
	  offset = pio_add_program(PIO_CAP, pp.get_pio_program());
	  c = pio_get_default_sm_config();
	  sm_config_set_wrap(&c,
			     offset,
			     offset + (pp.get_pio_program()->length - 1));
	  break;
     }

     case ClockMode::ExtSync:
     {
	  auto* s = pph.get(PioProgType::ExtSync);
	  if (s == nullptr) break;
	  auto& pp = (*(ExtSyncProg*)s);
	  pp.set_delay(cap_set.delay);
	  pp.set_ext_freq_div(cap_set.ext_freq_div);
	  offset = pio_add_program(PIO_CAP, pp.get_pio_program());
	  c = pio_get_default_sm_config();
	  sm_config_set_wrap(&c,
			     offset,
			     offset + (pp.get_pio_program()->length - 1));
	  break;
     }

     case ClockMode::Z80Freq:
     {
	  auto* s = pph.get(PioProgType::Z80Freq);
	  if (s == nullptr) break;
	  auto& pp = (*(Z80FreqProg*)s);
	  pp.set_delay_rise(cap_set.delay_rise);
	  pp.set_delay_fall(cap_set.delay_fall);
	  offset = pio_add_program(PIO_CAP, pp.get_pio_program());
	  c = pio_get_default_sm_config();
	  sm_config_set_wrap(&c,
			     offset,
			     offset + (pp.get_pio_program()->length - 1));
	  break;
     }

     default:
	  break;
     }

     sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_RX);
    
     sm_config_set_in_shift(&c, false, false, 8);//автопуш  не надо 
     sm_config_set_in_pins(&c, pin);
     sm_config_set_jmp_pin(&c,HS_PIN);

     pio_sm_init(PIO_CAP, sm, offset, &c);
     pio_sm_set_enabled(PIO_CAP, sm, true);

     if (cap_set.clk_mode == ClockMode::SelfSync) {
	  float fdiv=((1.0*clock_get_hz(clk_sys)/(cap_set.int_freq*12.0)) * (1 << 16)+0.5);
	  uint32_t div32=(uint32_t) (fdiv);
	  PIO_CAP->sm[sm].clkdiv=div32&0xffffffff;

     };
     ----------------------------

     ----------------------------
     DMA_BUF_ADDR_CAP[0]=&DMA_BUF_CAP[0][0];
     DMA_BUF_ADDR_CAP[1]=&DMA_BUF_CAP[1][0];

     int dma_chan0 = dma_claim_unused_channel(true);
     dma_chan  = dma_claim_unused_channel(true);

     dma_channel_config c0 = dma_channel_get_default_config(dma_chan0);
     channel_config_set_transfer_data_size(&c0, DMA_SIZE_8);

     channel_config_set_read_increment(&c0, false);
     channel_config_set_write_increment(&c0, true);

     uint dreq=DREQ_PIO1_RX0+sm;
     if (PIO_CAP==pio0) dreq=DREQ_PIO0_RX0+sm;
        
     channel_config_set_dreq(&c0, dreq);
     channel_config_set_chain_to(&c0, dma_chan);                      

     dma_channel_configure(
	  dma_chan0,
	  &c0,
	  &DMA_BUF_CAP[0][0], // Write address 
	  &PIO_CAP->rxf[SM_CAP],             //  read address
	  SIZE_DMA_BUF_CAPTURE, // 
	  false             // Don't start yet
	  );

     dma_channel_config c1 = dma_channel_get_default_config(dma_chan);
     channel_config_set_transfer_data_size(&c1, DMA_SIZE_32);
    
     channel_config_set_read_increment(&c1, false);
     channel_config_set_write_increment(&c1, false);
     channel_config_set_chain_to(&c1, dma_chan0);

     dma_channel_configure(
	  dma_chan,
	  &c1,
	  &dma_hw->ch[dma_chan0].write_addr, // Write address 
	  &DMA_BUF_ADDR_CAP[0],             // read address 
	  1, // 
	  false             // Don't start yet
	  );

  
     dma_channel_set_irq1_enabled(dma_chan, true);
     ---------------------------

     // Configure the processor to run dma_handler() when DMA IRQ 0 is asserted
     irq_set_exclusive_handler(DMA_IRQ_1, dma_handler_capture);
     irq_set_enabled(DMA_IRQ_1, true);

     dma_start_channel_mask((1u << dma_chan)) ;
     Serial.printf("init RGB capture \n");
};
*/
