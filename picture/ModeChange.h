
#ifndef _MODE_CHANGE_H_
#define _MODE_CHANGE_H_

#include "bsp_ws2812.h"
#include "bsp_Animation.h"


typedef struct 
{
    Picture_msg_t date;
    Animation_msg_t animation;


    unsigned char mode;
    unsigned char last_mode;
}ModeChange_msg_t;




void ModeChange_show(void);


#endif
