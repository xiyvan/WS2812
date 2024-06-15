
#ifndef _BSP_ANIMATION_H_
#define _BSP_ANIMATION_H_


#include "bsp_ws2812.h"
#include "bsp_ColorMixer.h"

enum
{
    SLIDE_EFFECT_STATE_LEFT,
    SLIDE_EFFECT_STATE_RIGHT,
    SLIDE_EFFECT_STATE_UP,
    SLIDE_EFFECT_STATE_DOWN,
};


typedef struct 
{
    // 用来保存滚动到的数值
    short num;
    // 用来保存图片信息
    Picture_msg_t date;
    // 用来记录是不是循环完了一遍
    unsigned char state:1;
}Animation_msg_t;


void xiaoguo(Display_msg_t* data);
void blink_effect(Display_msg_t* data);
void matrix_Falling_effect(Display_msg_t* data);
void slide_effect(WS2812_msg_t data[RGB_KEY][RGB_KEY],Animation_msg_t* Animat_main,uint8_t state);

#endif
