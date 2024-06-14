
#include "Display_task.h"
#include "bsp_ws2812.h"
#include "Z_math.h"
#include "bsp_ColorMixer.h"

extern Display_msg_t display_main;


// 50ms执行一次的任务
volatile uint8_t task_50ms = 0;


extern Picture_msg_t Animat_main;;
Picture_msg_t one;
Picture_msg_t two;
Picture_msg_t out;

WS2812_msg_t test;
WS2812_msg_t ttwo;
WS2812_msg_t back;

void display_show(void)
{
    one.layer_num = 1;
    one.trans = 50;
    two.layer_num = 2;
    two.trans = 50;
    test.B = 20;
    test.R = 60;
    test.G = 5;
    back.R = 0;
    back.G = 0;
    back.B = 0;
    ttwo.R = 20;
    ttwo.G = 40;
    ttwo.B = 60;
    write_rectangle_no(&one,1,1,7,7,&test,0);       // 画图形
    write_rectangle_full(&two,2,2,5,5,&ttwo);
    slide_right_effect(one.rgb);                    // 添加动作
    ColorMixer_two(&Animat_main,&two,&back,&out);        // 将动作混色
    WS2812_Change_free(display_main.buff,out.rgb);
    Display_Show(&display_main);
}





