
#include "Display_task.h"
#include "bsp_ws2812.h"
#include "Z_math.h"
#include "bsp_ColorMixer.h"
#include "bsp_base.h"
#include "string.h"

extern Display_msg_t display_main;


// 50ms执行一次的任务
volatile uint8_t task_50ms = 0;


Picture_msg_t* one;
Picture_msg_t two;
Picture_msg_t out;
Animation_msg_t* animat_main;
Animation_msg_t animat_arro;
Picture_msg_t* test;

WS2812_msg_t ttwo;
WS2812_msg_t back;

char T = '0';

void display_show(void)
{
    static uint8_t n = 0;
    if(n == 0)
    {
        // 初始化  这里的函数只会执行一次
        animat_arro.date.layer_num = 2;
        animat_arro.date.trans = 100;
        back.R = 0;
        back.G = 0;
        back.B = 0;
        ttwo.R = 100;
        ttwo.G = 20;
        ttwo.B = 10;
        // 初始化动画效果
        test = Picture_Create(2,50,1,1,8,8);
        one = Picture_Create(1,70,3,3,8,8);
        write_rectangle_no(test,2,2,8,7,&ttwo,0);
        animat_main = SlideEffect_create(one,SLIDE_EFFECT_STATE_LEFT,7,6);
        memset(&display_main.buff,0,sizeof(display_main.buff));
    }

    Write_OneDigitalTube(one,20,100,10,T,0);
    slide_effect(one,animat_main);            // 添加动作
    if(animat_main->state == 1)
    {
        T ++;
        // 设为未循环完
        animat_main->state = 0;
    }
    if(T > '9') T = '0';
    ColorMixer_two_free(test,&animat_main->date,&out,&back);
    WS2812_Change_free(display_main.buff,out.rgb);
    Display_Show(&display_main);
    memset(one->rgb,0,sizeof(one->rgb));

    n = 1;
}





