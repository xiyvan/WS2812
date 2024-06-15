
#ifndef _BSP_COLORMIXER_H_
#define _BSP_COLORMIXER_H_

#include "bsp_ws2812.h"
#include "bsp_PixelOperation.h"


void ColorMixer_two(Picture_msg_t* date1,Picture_msg_t* date2,WS2812_msg_t* back,Picture_msg_t* out);
void ColorMixer_two_free(Picture_msg_t* date1,Picture_msg_t* date2,Picture_msg_t* out,WS2812_msg_t* back);

#endif
