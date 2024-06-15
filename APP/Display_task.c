
#include "Display_task.h"
#include "bsp_ws2812.h"
#include "Z_math.h"
#include "bsp_ColorMixer.h"
#include "bsp_base.h"
#include "string.h"

extern Display_msg_t display_main;


// 50ms执行一次的任务
volatile uint8_t task_50ms = 0;


Picture_msg_t one;
Picture_msg_t two;
Picture_msg_t out;
Animation_msg_t animat_main;
Animation_msg_t animat_arro;

WS2812_msg_t test;
WS2812_msg_t ttwo;
WS2812_msg_t back;

char T = '0';

void display_show(void)
{
    one.layer_num = 1;
    one.trans = 50;
    animat_main.date.trans = 50;
    animat_main.date.layer_num = 1;
    animat_arro.date.layer_num = 2;
    animat_arro.date.trans = 100;
    back.R = 0;
    back.G = 0;
    back.B = 0;

    Write_OneDigitalTube(&one,20,100,10,T,2,1);
    Write_arrow(&two,50,10,17,ARROW_DIRECTION_LEFT);   // 画一个箭头
    slide_effect(two.rgb,&animat_arro,SLIDE_EFFECT_STATE_LEFT);
    slide_effect(one.rgb,&animat_main,SLIDE_EFFECT_STATE_DOWN);            // 添加动作
    if(animat_main.state == 1)
    {
        T ++;
        // 设为未循环完
        animat_main.state = 0;
    }
    if(T > '9') T = '0';
    ColorMixer_two_free(&animat_arro.date,&animat_main.date,&out,&back);
    WS2812_Change_free(display_main.buff,out.rgb);
    Display_Show(&display_main);
    memset(&one,0,sizeof(one));
}





