
#ifndef _BSP_STRINGTOBUFF_H_
#define _BSP_STRINGTOBUFF_H_

#include "stm32f4xx_hal.h"
#include "bsp_ws2812.h"

// 一行显示多少字符
#define ONES_KEY_NUM 8


typedef struct 
{
    unsigned char ds_long[ONES_KEY_NUM+5];
    unsigned char show[ONES_KEY_NUM];
}DisplayChange_msg_t;



void display_char(WS2812_msg_t* data,uint8_t* buf,uint8_t wei);
void xiaoguo(Display_msg_t* data);

#endif
