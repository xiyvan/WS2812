
#ifndef _CLOCK_H_
#define _CLOCK_H_

#include "bsp_ws2812.h"



// 时钟显示函数
void Clock_ShowClock(void);
// 时钟时间获取函数
void Clock_GetTime_Color(void);
// 时钟图标
void Clock_icon(Picture_msg_t* date);


#endif
