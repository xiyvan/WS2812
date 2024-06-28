
#ifndef _BSP_STRINGTOBUFF_H_
#define _BSP_STRINGTOBUFF_H_

#include "stm32f4xx_hal.h"
#include "bsp_ws2812.h"






void write_rectangle_no(Picture_msg_t* date,uint16_t x,uint16_t y,uint16_t x_end,uint16_t y_end,WS2812_msg_t* rgb,uint16_t wide);
void write_rectangle_full(Picture_msg_t* date,uint16_t x,uint16_t y,uint16_t x_end,uint16_t y_end,WS2812_msg_t* rgb);
void clear_rectangle(Picture_msg_t* date,unsigned char x,unsigned char y,unsigned char x_end,unsigned char y_end,WS2812_msg_t* back);
void clear_all(Picture_msg_t* date);

#endif
