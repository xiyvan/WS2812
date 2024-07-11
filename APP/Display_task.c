
#include "Display_task.h"
#include "bsp_ws2812.h"
#include "Z_math.h"
#include "bsp_ColorMixer.h"
#include "bsp_base.h"
#include "string.h"
#include "Clock.h"
#include "ModeSet_task.h"
#include "Light.h"
#include "Temputer.h"


extern Display_msg_t display_main;
extern ModeSet_msg_t mode_main;


Picture_msg_t text;

void display_show(void)
{
    switch (mode_main.Display_mode)
    {
        case MODE_DISPLAY_CLOCK:
        {
            Clock_ShowClock();
        }break;
        case MODE_DISPLAY_LIGHT:
        {
            Light_Show();
        }break;
        case MODE_DISPLAY_DATE:
        {
            Clock_ShowDate();
        }break;
        case MODE_DISPLAY_TEMPUTER:
        {
            Temputer_show();
        }break;
	}
    Display_Show(&display_main);
}



