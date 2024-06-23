
#include "bsp_base.h"

static void Write_OneDigitalTube_fu(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,unsigned char t,uint16_t key,uint16_t bar,unsigned char size);





/// @brief 指向左边的箭头
/// @param direction 箭头方向
void Write_arrow_5x7(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,unsigned char direction)
{
    if(date == NULL) return ;

    switch(direction)
    {
        case ARROW_DIRECTION_LEFT:
        {
            // 向左的箭头
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+4,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+5,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+6,R,G,B);
            date->size.x_end = date->size.x+4;
            date->size.y_end = date->size.y+6;
        }break;
        case ARROW_DIRECTION_RIGHT:
        {
            // 向右的箭头
            Ws2812_Set(date,date->size.x+2,date->size.y+6,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+5,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+5,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+4,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+4,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+5,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+4,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            date->size.x_end = date->size.x+4;
            date->size.y_end = date->size.y+6;
        }break;
        case ARROW_DIRECTION_UP:
        {
            // 向上的箭头
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+4,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+5,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+6,date->size.y+2,R,G,B);
            date->size.x_end = date->size.x+6;
            date->size.y_end = date->size.y+4;
        }break;
        case ARROW_DIRECTION_DOWN:
        {
            Ws2812_Set(date,date->size.x+6,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+5,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+5,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+4,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+5,date->size.y+2,R,G,B);
            date->size.x_end = date->size.x+6;
            date->size.y_end = date->size.y+4;
        }break;
    }
}



/// @brief 显示一个字符  5x4 占地(初M、W外)5x5
/// @param t 字符内容
void Write_OneChar(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,char t,unsigned char size)
{
    if(date == NULL) return ;
    date->size.y_end = date->size.y + 4;
    date->size.x_end = date->size.x + 5;
    switch(t)
    {
        case 'A':
        {
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+3,R,G,B);
        }break;
        case 'B':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
        }break;
        case 'C':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+3,R,G,B);
        }break;
        case 'D':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+3,R,G,B);
        }break;
        case 'E':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+3,R,G,B);
        }break;
        case 'F':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
        }break;
        case 'G':
        {
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+3,R,G,B);
        }break;
        case 'H':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+3,R,G,B);
        }break;
        case 'I':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            date->size.y_end = date->size.y + 3;
        }break;
        case 'J':
        {
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
        }break;
        case 'K':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+3,R,G,B);
        }break;
        case 'L':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+3,R,G,B);
        }break;
        case 'M':
        {
            // M占用 5x5
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+4,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+4,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+4,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+4,R,G,B);
            date->size.y_end = date->size.y + 5;
        }break;
        case 'N':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+3,R,G,B);
        }break;
        case 'O':
        {
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
        }break;
        case 'P':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
        }break;
        case 'Q':
        {
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+3,R,G,B);
        }break;
        case 'R':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+3,R,G,B);
        }break;
        case 'S':
        {
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
        }break;
        case 'T':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            date->size.y_end = date->size.y + 3;
        }break;
        case 'U':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+3,R,G,B);
        }break;
        case 'V':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+3,R,G,B);
        }break;
        case 'W':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+4,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+4,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+4,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+4,R,G,B);
            date->size.y_end = date->size.y + 5;
        }break;
        case 'X':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            date->size.y_end = date->size.y + 3;
        }break;
        case 'Y':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+2,R,G,B);
            date->size.y_end = date->size.y + 3;
        }break;
        case 'Z':
        {
            Ws2812_Set(date,date->size.x,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x,date->size.y+3,R,G,B);
            Ws2812_Set(date,date->size.x+1,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+2,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+3,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+1,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+2,R,G,B);
            Ws2812_Set(date,date->size.x+4,date->size.y+3,R,G,B);
        }break;

        default:
        {
            Write_OneDigitalTube(date,R,G,B,t,size);
        }break;
    }


}




/// @brief 添加一个数码管 占地 7*5
/// @param t 要显示的数字
/// @param key 左上角行数坐标
/// @param bar 左上角列数坐标
void Write_OneDigitalTube(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,char t,unsigned char size)
{
    if(date == NULL) return ;

    switch (t)
    {
        case '0':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,2,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,3,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,4,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,5,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,6,date->size.x,date->size.y,size);
        }break;
        case '1':
        {
            Write_OneDigitalTube_fu(date,R,G,B,2,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,3,date->size.x,date->size.y,size);
        }break;
        case '2':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,2,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,7,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,4,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,5,date->size.x,date->size.y,size);
        }break;
        case '3':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,2,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,3,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,4,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,7,date->size.x,date->size.y,size);
        }break;
        case '4':
        {
            Write_OneDigitalTube_fu(date,R,G,B,2,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,3,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,6,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,7,date->size.x,date->size.y,size);
        }break;
        case '5':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,3,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,4,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,6,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,7,date->size.x,date->size.y,size);
        }break;
        case '6':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,3,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,4,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,5,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,6,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,7,date->size.x,date->size.y,size);
        }break;
        case '7':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,2,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,3,date->size.x,date->size.y,size);
        }break;
        case '8':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,2,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,3,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,4,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,5,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,6,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,7,date->size.x,date->size.y,size);
        }break;
        case '9':
        {
            Write_OneDigitalTube_fu(date,R,G,B,1,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,2,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,3,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,4,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,6,date->size.x,date->size.y,size);
            Write_OneDigitalTube_fu(date,R,G,B,7,date->size.x,date->size.y,size);
        }break;
        case '.':
        {
            Write_OneDigitalTube_fu(date,R,G,B,8,date->size.x,date->size.y,size);
        }break;
    }
}


/// @brief 数码管段码
/// @param t 第几段
/// @param key 
/// @param bar 
static void Write_OneDigitalTube_fu(Picture_msg_t* date,unsigned char R,unsigned char G,unsigned char B,unsigned char t,uint16_t key,uint16_t bar,unsigned char size)
{
    if(date == NULL) return ;

    WS2812_msg_t temp;
    temp.R = R;
    temp.G = G;
    temp.B = B;
    if(size == 1)
    {
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
        date->size.x_end = date->size.x + 4;
        date->size.y_end = date->size.y + 6;
    }
    else if(size == 0)
    {
        switch(t)
        {
            case 1:
            {
                write_rectangle_full(date,key,bar,key,bar+2,&temp);
            }break;
            case 2:
            {
                write_rectangle_full(date,key,bar+2,key+2,bar+2,&temp);
            }break;
            case 3:
            {
                write_rectangle_full(date,key+2,bar+2,key+4,bar+2,&temp);
            }break;
            case 4:
            {
                write_rectangle_full(date,key+4,bar,key+4,bar+2,&temp);
            }break;
            case 5:
            {
                write_rectangle_full(date,key+2,bar,key+4,bar,&temp);
            }break;
            case 6:
            {
                write_rectangle_full(date,key,bar,key+2,bar,&temp);
            }break;
            case 7:
            {
                write_rectangle_full(date,key+2,bar,key+2,bar+2,&temp);
            }break;
            case 8:
            {
                Ws2812_Set(date,key+4,bar,R,G,B);
                date->size.x_end = date->size.x + 4;
                date->size.y_end = date->size.y + 1;
                return ;
            };
        }
        date->size.x_end = date->size.x + 4;
        date->size.y_end = date->size.y + 3;
    }
}



