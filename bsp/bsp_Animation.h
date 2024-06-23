
#ifndef _BSP_ANIMATION_H_
#define _BSP_ANIMATION_H_


#include "bsp_ws2812.h"
#include "bsp_ColorMixer.h"


void xiaoguo(Display_msg_t* data);
void blink_effect(Display_msg_t* data);
void matrix_Falling_effect(Display_msg_t* data);

//***********************************************  滚动效果  ********************************************************///
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
    // 用来记录动画的方向
    unsigned char direction:7;
    // 动作作用的地点
    unsigned short x;
    unsigned short y;
    unsigned short x_end;
    unsigned short y_end;
}Animation_msg_t;

void slide_effect(Picture_msg_t* data,Animation_msg_t* Animat_main);
Animation_msg_t* SlideEffect_create(Animation_msg_t* date,Picture_msg_t* pic,unsigned char direction,unsigned short x_end,unsigned short y_end);


///************************************************************** endl ******************************************/


#endif
