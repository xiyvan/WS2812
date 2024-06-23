
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
Animation_msg_t ani_main;

char t = 'A';

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
        Picture_Create(&one,1,70,2,2,8,8);
        SlideEffect_create(&ani_main,&one,0,8,32);
    }
    Write_OneChar(&one,ttwo.R,ttwo.G,ttwo.B,t,0);
    slide_effect(&one,&ani_main);
    if(ani_main.state == 1)
    {
        t ++;
        if(t > 'Z')
        {
            t = '0';
        }
        else if(t > '9' && t < 'A')
        {
            t = 'A';
        }
        ani_main.state = 0;
    }

    WS2812_Change_free(display_main.buff,ani_main.date.rgb);
    Display_Show(&display_main);
    memset(&one.rgb,0,sizeof(one.rgb));
    n = 1;
}



