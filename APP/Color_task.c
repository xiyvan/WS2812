
#include "Color_task.h"
#include "Clock.h"
#include "ModeSet_task.h"



extern ModeSet_msg_t mode_main;



void Color_task(void)
{
    switch(mode_main.Display_mode)
    {
        case MODE_DISPLAY_CLOCK:
        {
            Clock_GetTime_Color();
        }break;
    }
}
