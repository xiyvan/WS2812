
#include "Display_task.h"
#include "bsp_ws2812.h"
#include "Z_math.h"
#include "bsp_ColorMixer.h"
#include "bsp_base.h"
#include "string.h"

extern Display_msg_t display_main;
extern RTC_TimeTypeDef rtc_main;
extern RTC_DateTypeDef rtc_date;
extern WS2812_msg_t change;

// 50ms执行一次的任务
volatile uint8_t task_50ms = 0;



WS2812_msg_t ttwo;
WS2812_msg_t back;
Picture_msg_t one;
char t [6] = {0};


void display_show(void)
{
    static uint8_t n = 0;
    static unsigned char key = 1,bar = 1;
    static unsigned char state = 0;
    if(n == 0)
    {
        // 初始化  这里的函数只会执行一次
        back.R = 40;
        back.G = 90;
        back.B = 115;
        ttwo.R = 0;
        ttwo.G = 0;
        ttwo.B = 0;
        change.R = 151;
        change.G = 0;
        change.B = 0;
        Picture_Create(&one,1,100,1,1,8,32);
        write_rectangle_no(&one,1,2,7,30,&back,0);
        n = 1;
    }

    sprintf(t,"%1d",rtc_main.Seconds / 10);         // 秒十位
    sprintf(&t[1],"%1d",rtc_main.Seconds % 10);         // 秒个位
    sprintf(&t[2],"%1d",rtc_main.Minutes / 10);         // 分十位
    sprintf(&t[3],"%1d",rtc_main.Minutes % 10);         // 分个位
    sprintf(&t[4],"%1d",rtc_main.Hours / 10);           // 小时十位
    sprintf(&t[5],"%1d",rtc_main.Hours % 10);           // 小时个位

    if(state == 0)
    {
        key ++;
        if(key >= 30) state = 1;
    }
    else if(state == 1)
    {
        bar ++;
        if(bar >= 7) state = 2;
    }
    else if(state == 2)
    {
        key --;
        if(key <= 2) state = 3;
    }
    else if(state == 3)
    {
        bar --;
        if(bar <= 1) state = 0;
    }

    Ws2812_Set(&one,bar,key,change.R,change.G,change.B);

    //write_rectangle_no(&one,1,2,7,30,&change,0);

    Picture_Create(&one,1,100,2,3,8,32);
    Write_OneChar(&one,66,20,150,t[4],0);
    Picture_Create(&one,1,100,2,7,8,32);
    Write_OneChar(&one,66,20,150,t[5],0);

    Picture_Create(&one,1,100,2,13,8,32);
    Write_OneChar(&one,66,20,150,t[2],0);
    Picture_Create(&one,1,100,2,17,8,32);
    Write_OneChar(&one,66,20,150,t[3],0);

    Picture_Create(&one,1,100,2,23,8,32);
    Write_OneChar(&one,66,20,150,t[0],0);
    Picture_Create(&one,1,100,2,27,8,32);
    Write_OneChar(&one,66,20,150,t[1],0);

    if(rtc_main.SubSeconds > 127)
    {
        Ws2812_Set(&one,3,11,66,20,150);
        Ws2812_Set(&one,5,11,66,20,150);

        Ws2812_Set(&one,3,21,66,20,150);
        Ws2812_Set(&one,5,21,66,20,150);
    }

    WS2812_Change_free(display_main.buff,one.rgb);
    Display_Show(&display_main);

    clear_rectangle(&one,2,3,6,29,&ttwo);
}



