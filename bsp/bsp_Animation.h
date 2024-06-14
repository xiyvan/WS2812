
#ifndef _BSP_ANIMATION_H_
#define _BSP_ANIMATION_H_


#include "bsp_ws2812.h"
#include "bsp_ColorMixer.h"





void xiaoguo(Display_msg_t* data);
void blink_effect(Display_msg_t* data);
void matrix_Falling_effect(Display_msg_t* data);
void slide_right_effect(WS2812_msg_t data[RGB_KEY][RGB_KEY]);

#endif
