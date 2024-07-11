
#ifndef _BSP_BASE_H_
#define _BSP_BASE_H_

#include "bsp_ws2812.h"
#include "bsp_PixelOperation.h"



// 用来表示箭头方向
enum
{
    ARROW_DIRECTION_LEFT,
    ARROW_DIRECTION_RIGHT,
    ARROW_DIRECTION_UP,
    ARROW_DIRECTION_DOWN,
};


void Write_arrow_5x7(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,unsigned char direction);
void Write_arrow(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,unsigned char direction);
void Write_OneChar(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,char t,unsigned char size);
void Write_OneDigitalTube(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,char t,unsigned char size);

#endif
