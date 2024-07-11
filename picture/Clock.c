
#include "Clock.h"
#include "bsp_PixelOperation.h"

extern Display_msg_t display_main;
extern RTC_TimeTypeDef rtc_main;
extern RTC_DateTypeDef rtc_date;
extern RTC_HandleTypeDef hrtc;

// 边框炫彩
WS2812_msg_t change;

/// 保存RTC时间
RTC_TimeTypeDef rtc_main;

// 保存RTC日期
RTC_DateTypeDef rtc_date;

WS2812_msg_t ttwo;
WS2812_msg_t back;

// 用来显示时间
Picture_msg_t one;

// 用来显示日期的图片
Picture_msg_t Date_main;
char t [6] = {0};



/// @brief 根据获取到的时间与选炫彩的更新，将他们显示到屏幕上面
void Clock_ShowClock(void)
{
    static uint8_t n = 0;
    static unsigned char key = 1,bar = 1;
    static unsigned char state = 0;
    // 用来记录运行了几次
    static unsigned char number = 0;

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
    // 每20ms运行一次
    Clock_GetTime_Color();
    number ++;
    // 每100ms运行一次
    if(number >= 4)
    {
        sprintf(t,"%1d",rtc_main.Seconds / 10);             // 秒十位
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
        clear_rectangle(&one,2,3,6,29,&ttwo);
        number = 0;
    }

}

/// @brief 显示日期
void Clock_ShowDate(void)
{
    static unsigned char number = 0;
    static uint8_t n = 0;
    char t [6] = {0};

    n ++;
    if(n >= 4)
    {
        Ws2812_Set(&Date_main,4,11,66,20,150);

        sprintf(t,"%1d",rtc_date.Month/10);                     // 月十位
        sprintf(&t[1],"%1d",rtc_date.Month % 10);               // 月个位
        sprintf(&t[2],"%1d",rtc_date.Date / 10);                // 日十位
        sprintf(&t[3],"%1d",rtc_date.Date % 10);                // 日个位
        sprintf(&t[4],"%1d",rtc_date.WeekDay / 10);             // 星期十位
        sprintf(&t[5],"%1d",rtc_date.WeekDay % 10);             // 星期个位

        Picture_Create(&Date_main,1,100,2,3,8,32);              // 显示月份
        Write_OneChar(&Date_main,66,20,150,t[0],0);
        Picture_Create(&Date_main,1,100,2,7,8,32);
        Write_OneChar(&Date_main,66,20,150,t[1],0);

        Picture_Create(&Date_main,1,100,2,13,8,32);             // 显示日期
        Write_OneChar(&Date_main,66,20,150,t[2],0);
        Picture_Create(&Date_main,1,100,2,17,8,32);
        Write_OneChar(&Date_main,66,20,150,t[3],0);

			
        Picture_Create(&Date_main,1,100,2,23,8,32);             // 显示星期
        Write_OneChar(&Date_main,66,20,150,t[4],0);
        Picture_Create(&Date_main,1,100,2,27,8,32);
        Write_OneChar(&Date_main,66,20,150,t[5],0);

        WS2812_Change_free(display_main.buff,Date_main.rgb);
        clear_all(&Date_main);
        n = 0;
    }
}



/// @brief 获取时间并刷新炫彩颜色
void Clock_GetTime_Color(void)
{
    static unsigned char num = 0;

    if(num >= 5)
    {
        if(change.B >= 150)
        {
            if(change.G >= 1)
            {
                change.G -= 2;
            }
            change.R += 2;
        } 
        if(change.R >= 150)
        {
            change.G += 2;
            if(change.B >= 1)
            {
                change.B -= 2;
            }
        } 
        if(change.G >= 150) 
        {
            if(change.R >= 1)
            {
                change.R -= 2;
            }
            change.B += 2;
        }
        num = 0;
    }

    num ++;
    HAL_RTC_GetTime(&hrtc,&rtc_main,RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc,&rtc_date,RTC_FORMAT_BIN);
}


/// @brief 时钟模式的图标
/// @param date 图片信息
void Clock_icon(Picture_msg_t* date)
{
    Ws2812_Set(date,1,13,60,40,10);
    Ws2812_Set(date,1,14,60,40,10);
    Ws2812_Set(date,1,18,60,40,10);
    Ws2812_Set(date,1,19,60,40,10);
    Ws2812_Set(date,2,13,60,40,10);
    Ws2812_Set(date,2,14,60,40,10);
    Ws2812_Set(date,2,15,60,40,10);
    Ws2812_Set(date,2,16,60,40,10);
    Ws2812_Set(date,2,17,60,40,10);
    Ws2812_Set(date,2,18,60,40,10);
    Ws2812_Set(date,2,19,60,40,10);
    Ws2812_Set(date,3,13,60,40,10);
    Ws2812_Set(date,3,16,60,40,10);
    Ws2812_Set(date,3,19,60,40,10);
    Ws2812_Set(date,4,13,60,40,10);
    Ws2812_Set(date,4,16,60,40,10);
    Ws2812_Set(date,4,19,60,40,10);
    Ws2812_Set(date,5,13,60,40,10);
    Ws2812_Set(date,5,16,60,40,10);
    Ws2812_Set(date,5,17,60,40,10);
    Ws2812_Set(date,5,19,60,40,10);
    Ws2812_Set(date,6,13,60,40,10);
    Ws2812_Set(date,6,19,60,40,10);
    Ws2812_Set(date,7,13,60,40,10);
    Ws2812_Set(date,7,14,60,40,10);
    Ws2812_Set(date,7,15,60,40,10);
    Ws2812_Set(date,7,16,60,40,10);
    Ws2812_Set(date,7,17,60,40,10);
    Ws2812_Set(date,7,18,60,40,10);
    Ws2812_Set(date,7,19,60,40,10);
}
