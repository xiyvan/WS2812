
#ifndef _BSP_WS1812_H_
#define _BSP_WS1812_H_

#include "stm32f4xx_hal.h"

// 点阵的行数（如果是圆形的话就：行数为1 有几个灯就是几列）
#define RGB_KEY 1
// 点阵的列数
#define RGB_BAR 12

// 灯珠总数
#define RGB_NUM (RGB_KEY * RGB_BAR)




#define WS2812_LowLevel    0xC0     // 0Ты
#define WS2812_HighLevel   0xFC     // 1Ты


typedef struct 
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
}WS2812_msg_t;



typedef struct 
{
    WS2812_msg_t date[RGB_KEY][RGB_BAR];     // 用来保存每个RGB灯珠的信息
    unsigned char buff[24 * RGB_NUM];        // 用来保存每一位要发送的数据
}Display_msg_t;



void Ws2812_Set(Display_msg_t* data,unsigned char key,unsigned char bar,unsigned char R,unsigned char G,unsigned char B);
void WS2812_Change(Display_msg_t* data);
void Display_Show(Display_msg_t* data);


#endif
