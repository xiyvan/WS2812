
#ifndef _MODESET_TASK_H_
#define _MODESET_TASK_H_

#include "bsp_ws2812.h"


typedef struct 
{
    // 总的显示页面
    short Display_mode;

    // 小夜灯亮度调节
    unsigned char Light_num;

    unsigned char now;          // 当前的按键状态
    unsigned char last_now;     // 上一次的按键状态
}ModeSet_msg_t;


enum
{
    MODE_DISPLAY_CLOCK,
    MODE_DISPLAY_DATE,
    MODE_DISPLAY_TEMPUTER,
    MODE_DISPLAY_LIGHT,
    MODE_DISPLAY_ALL
};




void ModeSet_task(void);



#endif
