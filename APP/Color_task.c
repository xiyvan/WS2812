
#include "Color_task.h"



extern WS2812_msg_t ttwo;
extern RTC_HandleTypeDef hrtc;
// 边框炫彩
WS2812_msg_t change;

RTC_TimeTypeDef rtc_main;
RTC_DateTypeDef rtc_date;

void Color_task(void)
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
