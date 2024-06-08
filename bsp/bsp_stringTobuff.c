
#include "bsp_stringTobuff.h"


unsigned char last_rgb[12];

void display_char(WS2812_msg_t* data,uint8_t* buf,uint8_t wei)
{
    
}



void xiaoguo(Display_msg_t* data)
{
    static uint8_t r = 0,g = 0,b = 200;

    Ws2812_Set(data,1,2,r*liang,g*liang,b*liang);
    if(b >= 200)
    {
        if(g >= 1)
        {
            g --;
        }
        r ++;
    } 
    if(r >= 200)
    {
        g ++;
        if(b >= 1)
        {
            b --;
        }
    } 
    if(g >= 200) 
    {
        if(r >= 1)
        {
            r --;
        }
        b ++;
    }
    liang = 1;


    Ws2812_Set(data,1,1,r*liang,g*liang,b*liang);
    Ws2812_Set(data,1,3,r*liang,g*liang,b*liang);
    Ws2812_Set(data,1,4,r*liang,g*liang,b*liang);
    Ws2812_Set(data,1,5,r*liang,g*liang,b*liang);
    Ws2812_Set(data,1,6,r*liang,g*liang,b*liang);
    Ws2812_Set(data,1,7,r*liang,g*liang,b*liang);
    Ws2812_Set(data,1,8,r*liang,g*liang,b*liang);
    Ws2812_Set(data,1,9,r*liang,g*liang,b*liang);
    Ws2812_Set(data,1,10,r*liang,g*liang,b*liang);
    Ws2812_Set(data,1,11,r*liang,g*liang,b*liang);
    Ws2812_Set(data,1,12,r*liang,g*liang,b*liang);

    last_rgb();
}
