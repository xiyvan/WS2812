
#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "bsp_ws2812.h"



typedef struct 
{
    Picture_msg_t date;
    unsigned char num;
    WS2812_msg_t color;
    WS2812_msg_t clolor_change;

    unsigned char up_state:1;
    unsigned char down_state:1;
}Light_msg_t;



void Light_Show(void);
void Light_Change(void);



#endif
