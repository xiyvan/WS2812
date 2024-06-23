
#include "Color_task.h"



extern WS2812_msg_t ttwo;


void Color_task(void)
{
    if(ttwo.B >= 150)
    {
        if(ttwo.G >= 1)
        {
            ttwo.G -= 5;
        }
        ttwo.R += 5;
    } 
    if(ttwo.R >= 150)
    {
        ttwo.G += 5;
        if(ttwo.B >= 1)
        {
            ttwo.B -= 5;
        }
    }
    if(ttwo.G >= 150) 
    {
        if(ttwo.R >= 1)
        {
            ttwo.R -= 5;
        }
        ttwo.B += 5;
    }
}
