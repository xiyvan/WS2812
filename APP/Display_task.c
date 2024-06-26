
#include "Display_task.h"
#include "bsp_ws2812.h"
#include "Z_math.h"
#include "bsp_ColorMixer.h"
#include "bsp_base.h"
#include "string.h"

extern Display_msg_t display_main;


// 50ms执行一次的任务
volatile uint8_t task_50ms = 0;



WS2812_msg_t ttwo;
WS2812_msg_t back;

Picture_msg_t one;
Picture_msg_t two;
Picture_msg_t out;
Anima_drifting_msg_t ani_main;


void display_show(void)
{
    static uint8_t n = 0;
    if(n == 0)
    {
        // 初始化  这里的函数只会执行一次
        back.R = 0;
        back.G = 0;
        back.B = 0;
        ttwo.R = 66;
        ttwo.G = 20;
        ttwo.B = 150;
        // 初始化动画效果
        Picture_Create(&one,1,75,1,15,6,32);
        Picture_Create(&two,2,85,3,10,6,32);
        Picture_Create(&out,1,20,1,1,7,32);
        Write_OneChar(&one,66,20,150,'A',0);
        Write_OneChar(&two,66,20,150,'B',0);
        ColorMixer_two_free(&one,&two,&out,&back);
        Picture_Create(&one,1,75,1,5,6,32);
        Picture_Create(&two,2,85,1,1,6,32);
        Write_OneChar(&one,66,20,150,'C',0);
        ColorMixer_two_free(&out,&one,&two,&back);
        Animation_drifting_effectCreate(&ani_main,&two,SLIDE_EFFECT_STATE_DOWN,8,32);
    }
    if(ani_main.animation.state != 1)
    {
        Animation_drifting_effect(&ani_main,&two);
    }

    WS2812_Change_free(display_main.buff,ani_main.animation.date.rgb);
    Display_Show(&display_main);
    n = 1;
}



