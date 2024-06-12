
#include "Display_task.h"


extern Display_msg_t display_main;


// 50ms执行一次的任务
volatile uint8_t task_50ms = 0;






void display_show(void)
{
    blink_effect(&display_main);
    WS2812_Change(&display_main);
    Display_Show(&display_main);
}














