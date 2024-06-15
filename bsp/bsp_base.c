
#include "bsp_base.h"

static void Write_OneDigitalTube_fu(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,unsigned char t,uint16_t key,uint16_t bar);





/// @brief 指向左边的箭头
/// @param direction 箭头方向
void Write_arrow(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,unsigned char direction)
{
    switch(direction)
    {
        case ARROW_DIRECTION_LEFT:
        {
            // 向左的箭头
            Ws2812_Set(date,5,1,R,G,B);
            Ws2812_Set(date,4,2,R,G,B);
            Ws2812_Set(date,6,2,R,G,B);
            Ws2812_Set(date,3,3,R,G,B);
            Ws2812_Set(date,7,3,R,G,B);
            Ws2812_Set(date,5,2,R,G,B);
            Ws2812_Set(date,5,3,R,G,B);
            Ws2812_Set(date,5,4,R,G,B);
            Ws2812_Set(date,5,5,R,G,B);
            Ws2812_Set(date,5,6,R,G,B);
            Ws2812_Set(date,5,7,R,G,B);
        }break;
        case ARROW_DIRECTION_RIGHT:
        {
            // 向右的箭头
            Ws2812_Set(date,5,8,R,G,B);
            Ws2812_Set(date,4,7,R,G,B);
            Ws2812_Set(date,6,7,R,G,B);
            Ws2812_Set(date,3,6,R,G,B);
            Ws2812_Set(date,7,6,R,G,B);
            Ws2812_Set(date,5,7,R,G,B);
            Ws2812_Set(date,5,6,R,G,B);
            Ws2812_Set(date,5,5,R,G,B);
            Ws2812_Set(date,5,4,R,G,B);
            Ws2812_Set(date,5,3,R,G,B);
            Ws2812_Set(date,5,2,R,G,B);
        }break;
        case ARROW_DIRECTION_UP:
        {
            // 向上的箭头
            Ws2812_Set(date,1,5,R,G,B);
            Ws2812_Set(date,2,4,R,G,B);
            Ws2812_Set(date,2,6,R,G,B);
            Ws2812_Set(date,3,3,R,G,B);
            Ws2812_Set(date,3,7,R,G,B);
            Ws2812_Set(date,2,5,R,G,B);
            Ws2812_Set(date,3,5,R,G,B);
            Ws2812_Set(date,4,5,R,G,B);
            Ws2812_Set(date,5,5,R,G,B);
            Ws2812_Set(date,6,5,R,G,B);
            Ws2812_Set(date,7,5,R,G,B);
        }break;
        case ARROW_DIRECTION_DOWN:
        {
            Ws2812_Set(date,8,5,R,G,B);
            Ws2812_Set(date,7,4,R,G,B);
            Ws2812_Set(date,7,6,R,G,B);
            Ws2812_Set(date,6,3,R,G,B);
            Ws2812_Set(date,6,7,R,G,B);
            Ws2812_Set(date,2,5,R,G,B);
            Ws2812_Set(date,3,5,R,G,B);
            Ws2812_Set(date,4,5,R,G,B);
            Ws2812_Set(date,5,5,R,G,B);
            Ws2812_Set(date,6,5,R,G,B);
            Ws2812_Set(date,7,5,R,G,B);
        }break;
    }

}



/// @brief 显示一个字符
/// @param t 字符内容
void Write_OneChar(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,char t)
{
    switch(t)
    {
        case '1':
        {
            Ws2812_Set(date,2,7,R,G,B);
            Ws2812_Set(date,3,7,R,G,B);
            Ws2812_Set(date,4,7,R,G,B);
            Ws2812_Set(date,5,7,R,G,B);
            Ws2812_Set(date,6,7,R,G,B);
            Ws2812_Set(date,7,7,R,G,B);
            Ws2812_Set(date,8,7,R,G,B);
        }break;
        case 'A':
        {
            Ws2812_Set(date,8,1,R,G,B);
            Ws2812_Set(date,2,2,R,G,B);
            Ws2812_Set(date,3,2,R,G,B);
            Ws2812_Set(date,4,2,R,G,B);
            Ws2812_Set(date,5,2,R,G,B);
            Ws2812_Set(date,6,2,R,G,B);
            Ws2812_Set(date,7,2,R,G,B);
            Ws2812_Set(date,8,2,R,G,B);
            Ws2812_Set(date,2,3,R,G,B);
            Ws2812_Set(date,5,3,R,G,B);
            Ws2812_Set(date,8,3,R,G,B);
            Ws2812_Set(date,2,4,R,G,B);
            Ws2812_Set(date,5,4,R,G,B);
            Ws2812_Set(date,2,5,R,G,B);
            Ws2812_Set(date,5,5,R,G,B);
            Ws2812_Set(date,2,6,R,G,B);
            Ws2812_Set(date,5,6,R,G,B);
            Ws2812_Set(date,8,6,R,G,B);
            Ws2812_Set(date,2,7,R,G,B);
            Ws2812_Set(date,3,7,R,G,B);
            Ws2812_Set(date,4,7,R,G,B);
            Ws2812_Set(date,5,7,R,G,B);
            Ws2812_Set(date,6,7,R,G,B);
            Ws2812_Set(date,7,7,R,G,B);
            Ws2812_Set(date,8,7,R,G,B);
            Ws2812_Set(date,8,8,R,G,B);
        }break;
        case 'H':
        {
            Ws2812_Set(date,2,1,R,G,B);
            Ws2812_Set(date,3,1,R,G,B);
            Ws2812_Set(date,4,1,R,G,B);
            Ws2812_Set(date,5,1,R,G,B);
            Ws2812_Set(date,6,1,R,G,B);
            Ws2812_Set(date,7,1,R,G,B);
            Ws2812_Set(date,8,1,R,G,B);

            Ws2812_Set(date,5,2,R,G,B);
            Ws2812_Set(date,5,3,R,G,B);
            Ws2812_Set(date,5,4,R,G,B);
            Ws2812_Set(date,5,5,R,G,B);

            Ws2812_Set(date,2,6,R,G,B);
            Ws2812_Set(date,3,6,R,G,B);
            Ws2812_Set(date,4,6,R,G,B);
            Ws2812_Set(date,5,6,R,G,B);
            Ws2812_Set(date,6,6,R,G,B);
            Ws2812_Set(date,7,6,R,G,B);
            Ws2812_Set(date,8,6,R,G,B);
        }break;
        case 'X':
        {
            Ws2812_Set(date,2,1,R,G,B);
            Ws2812_Set(date,8,1,R,G,B);
            Ws2812_Set(date,3,2,R,G,B);
            Ws2812_Set(date,7,2,R,G,B);
            Ws2812_Set(date,4,3,R,G,B);
            Ws2812_Set(date,6,3,R,G,B);
            Ws2812_Set(date,5,4,R,G,B);
            Ws2812_Set(date,4,5,R,G,B);
            Ws2812_Set(date,6,5,R,G,B);
            Ws2812_Set(date,3,6,R,G,B);
            Ws2812_Set(date,7,6,R,G,B);
            Ws2812_Set(date,2,7,R,G,B);
            Ws2812_Set(date,8,7,R,G,B);
        }break;
    }
}




/// @brief 添加一个数码管 占地 7*5
/// @param t 要显示的数字
/// @param key 左上角行数坐标
/// @param bar 左上角列数坐标
void Write_OneDigitalTube(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,char t,uint16_t key,uint16_t bar)
{
    switch (t)
    {
        case '0':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,2,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,3,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,4,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,5,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,6,key,bar);
        }break;
        case '1':
        {
            Write_OneDigitalTube_fu(date,R,G,B,2,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,3,key,bar);
        }break;
        case '2':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,2,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,7,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,4,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,5,key,bar);
        }break;
        case '3':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,2,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,3,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,4,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,7,key,bar);
        }break;
        case '4':
        {
            Write_OneDigitalTube_fu(date,R,G,B,2,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,3,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,6,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,7,key,bar);
        }break;
        case '5':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,3,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,4,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,6,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,7,key,bar);
        }break;
        case '6':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,3,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,4,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,5,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,6,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,7,key,bar);
        }break;
        case '7':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,2,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,3,key,bar);
        }break;
        case '8':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,2,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,3,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,4,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,5,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,6,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,7,key,bar);
        }break;
        case '9':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,2,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,3,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,4,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,6,key,bar);
            Write_OneDigitalTube_fu(date,R,G,B,7,key,bar);
        }
    }
}


/// @brief 数码管段码
/// @param t 第几段
/// @param key 
/// @param bar 
static void Write_OneDigitalTube_fu(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,unsigned char t,uint16_t key,uint16_t bar)
{
    WS2812_msg_t temp;
    temp.R = R;
    temp.G = G;
    temp.B = B;
    switch(t)
    {
        case 1:
        {
            write_rectangle_full(date,key,bar,key,bar+4,&temp);
        }break;
        case 2:
        {
            write_rectangle_full(date,key,bar+4,key+3,bar+4,&temp);
        }break;
        case 3:
        {
            write_rectangle_full(date,key+3,bar+4,key+6,bar+4,&temp);
        }break;
        case 4:
        {
            write_rectangle_full(date,key+6,bar,key+6,bar+4,&temp);
        }break;
        case 5:
        {
            write_rectangle_full(date,key+3,bar,key+6,bar,&temp);
        }break;
        case 6:
        {
            write_rectangle_full(date,key,bar,key+3,bar,&temp);
        }break;
        case 7:
        {
            write_rectangle_full(date,key+3,bar,key+3,bar+4,&temp);
        }break;
    }
}

