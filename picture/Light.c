
#include "Light.h"
#include "bsp_PixelOperation.h"
#include "ModeSet_task.h"


static void Light_ColorSet(Light_msg_t* date);



Light_msg_t Light_main;
extern Display_msg_t display_main;


void Light_Show(void)
{
    static unsigned char num = 0;
    if(num == 0)
    {
        Light_main.color.R = 240;
        Light_main.color.G = 160;
        Light_main.color.B = 40;
        Light_main.num = 1;
        Light_ColorSet(&Light_main);
        num = 1;
    }

    write_rectangle_full(&Light_main.date,1,1,8,32,&Light_main.clolor_change);
    WS2812_Change_free(display_main.buff,Light_main.date.rgb);
}



void Light_Change(void)
{
    if(Light_main.up_state)
    {
        Light_main.num ++;
        Light_main.up_state = 0;
        if(Light_main.num > 10) Light_main.num = 10;
        Light_ColorSet(&Light_main);
    }
    else if(Light_main.down_state)
    {
        Light_main.num --;
        Light_main.down_state = 0;
        if(Light_main.num < 1) Light_main.num = 1;
        Light_ColorSet(&Light_main);
    }
}



static void Light_ColorSet(Light_msg_t* date)
{
    date->clolor_change.R = date->color.R * (date->num / 10.0f);
    date->clolor_change.G = date->color.G * (date->num / 10.0f);
    date->clolor_change.B = date->color.B * (date->num / 10.0f);
}



void Light_icon(Picture_msg_t* date)
{


}
