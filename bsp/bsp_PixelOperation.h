
#ifndef _BSP_STRINGTOBUFF_H_
#define _BSP_STRINGTOBUFF_H_

#include "stm32f4xx_hal.h"
#include "bsp_ws2812.h"






void display_char(WS2812_msg_t* data,uint8_t* buf,uint8_t wei);
void write_rectangle_no(Picture_msg_t* date,uint16_t x,uint16_t y,uint16_t x_end,uint16_t y_end,WS2812_msg_t* rgb,uint16_t wide);
void write_rectangle_full(Picture_msg_t* date,uint16_t x,uint16_t y,uint16_t x_end,uint16_t y_end,WS2812_msg_t* rgb);

#endif
