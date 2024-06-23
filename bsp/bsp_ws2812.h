
#ifndef _BSP_WS1812_H_
#define _BSP_WS1812_H_

#include "stm32f4xx_hal.h"

// 点阵的行数（如果是圆形的话就：行数为1 有几个灯就是几列）
#define RGB_KEY 8
// 点阵的列数
#define RGB_BAR 32

// 单板行数
#define RGB_KEY_ONE 8
// 单板列数
#define RGB_BAR_ONE 8

// 灯珠总数
#define RGB_NUM (RGB_KEY * RGB_BAR)

// 横向拼接的块数
#define RGB_MIX_KEY (RGB_BAR / RGB_BAR_ONE)
// 纵向拼接的块数
#define RGB_MIX_BAR (RGB_KEY / RGB_KEY_ONE)




#define WS2812_LowLevel    0xC0     // 0Ты
#define WS2812_HighLevel   0xFC     // 1Ты


/// @brief 图片尺寸结构体
typedef struct 
{
    unsigned short x;
    unsigned short y;
    unsigned short x_end;
    unsigned short y_end;
}PictureSize_msg_t;


/// @brief rgb颜色结构体
typedef struct 
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
}WS2812_msg_t;


/// @brief 屏幕缓存
typedef struct 
{
    unsigned char buff[24 * RGB_NUM];        // 用来保存每一位要发送的数据
}Display_msg_t;

/// @brief 图片结构体
typedef struct
{
    // 保存图片的尺寸
    PictureSize_msg_t size;
    // 图片的RGB信息
    WS2812_msg_t rgb[RGB_KEY][RGB_BAR];
    // 图片的图层数
    unsigned char layer_num;
    // 图片的透明度
    unsigned char  trans;
}Picture_msg_t;


void Ws2812_Set(Picture_msg_t* data,unsigned char key,unsigned char bar,unsigned char R,unsigned char G,unsigned char B);
void Display_Show(Display_msg_t* data);
void WS2812_Change_free(unsigned char* data,WS2812_msg_t ws[RGB_KEY][RGB_BAR]);
Picture_msg_t* Picture_Create(Picture_msg_t* date,unsigned char layer_num,unsigned char trans,unsigned short x,unsigned short y,unsigned short x_end,unsigned short y_end);
#endif
