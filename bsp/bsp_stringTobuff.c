
#include "bsp_stringTobuff.h"




void display_char(WS2812_msg_t* data,uint8_t* buf,uint8_t wei)
{
    
}


uint8_t last_num_l[4][3];


void xiaoguo(Display_msg_t* data)
{
    static uint8_t r = 0,g = 0,b = 200;
    static uint8_t num = 1;
    static int8_t last_num = 1,last_num2 = 1,last_num3 = 1,last_num4 = 1;
    num ++;
    if(num > 12) num = 1;
    
    last_num = num -1;
    last_num2 = num -2;
    last_num3 = num -3;
    last_num4 = num - 4;

    if(last_num == 0) last_num = 12;

    if(last_num2 == 0) last_num2 = 12;
    else if(last_num2 == -1) last_num2 = 11; 

    if(last_num3 == 0) last_num3 = 12;
    else if(last_num3 == -1) last_num3 = 11; 
    else if(last_num3 == -2) last_num3 = 10;

    if(last_num4 == 0) last_num4 = 12;
    else if(last_num4 == -1) last_num4 = 11; 
    else if(last_num4 == -2) last_num4 = 10;
    else if(last_num4 == -3) last_num4 = 9;

    for(int i = 1;i < 13;i++)
    {
        Ws2812_Set(data,1,i,0,0,0);
    }

    if(b >= 200)
    {
        if(g >= 1)
        {
            g -= 20;
        }
        r += 20;
    } 
    if(r >= 200)
    {
        g += 20;
        if(b >= 1)
        {
            b -= 20;
        }
    } 
    if(g >= 200) 
    {
        if(r >= 1)
        {
            r -= 20;
        }
        b += 20;
    }


    Ws2812_Set(data,1,num,r,g,b);
    Ws2812_Set(data,1,last_num,last_num_l[0][0] * 0.7f,last_num_l[0][1] * 0.7f,last_num_l[0][2] * 0.7f);
    Ws2812_Set(data,1,last_num2,last_num_l[1][0] * 0.5f,last_num_l[1][1] * 0.5f,last_num_l[1][2] * 0.5f);
    Ws2812_Set(data,1,last_num3,last_num_l[2][0] * 0.3f,last_num_l[2][1] * 0.3f,last_num_l[2][2] * 0.3f);
    Ws2812_Set(data,1,last_num4,last_num_l[3][0] * 0.1f,last_num_l[3][1] * 0.1f,last_num_l[3][2] * 0.1f);

    last_num_l[0][0] = r;last_num_l[0][1] = g;last_num_l[0][2] = b;
    last_num_l[3][0] = last_num_l[2][0];last_num_l[3][1] = last_num_l[2][1];last_num_l[3][2] = last_num_l[2][2];
    last_num_l[2][0] = last_num_l[1][0];last_num_l[2][1] = last_num_l[1][1];last_num_l[2][2] = last_num_l[1][2];
    last_num_l[1][0] = last_num_l[0][0];last_num_l[1][1] = last_num_l[0][1];last_num_l[1][2] = last_num_l[0][2];

}
