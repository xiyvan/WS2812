
#include "bsp_PixelOperation.h"
#include "Z_math.h"



void display_char(WS2812_msg_t* data,uint8_t* buf,uint8_t wei)
{
    
}









/// @brief 矩形填充
/// @param date 页面数据
/// @param x 左上角点x坐标
/// @param y 左上角点y坐标
/// @param x_end 右下角点x坐标
/// @param y_end 右下角点y坐标
/// @param rgb 填充颜色
void write_rectangle_full(Picture_msg_t* date,uint16_t x,uint16_t y,uint16_t x_end,uint16_t y_end,WS2812_msg_t* rgb)
{
    // 判断输入的数据合法性
    if((x_end - x < 0) || ((y_end - y < 0)))
    {
        return ;
    }

    // 判断输入值是否超过边界
    if(x_end > RGB_KEY) x_end = RGB_KEY;
    if(y_end > RGB_BAR) y_end = RGB_BAR;


    for(uint8_t i = x;i <= x_end;i ++)
    {
        for(uint8_t j = y;j <= y_end;j++)
        {
            Ws2812_Set(date,i,j,rgb->R,rgb->G,rgb->B);
        }
    }
}



/// @brief 矩形框（不填充）
/// @param date 页面数据
/// @param x 左上角点x坐标
/// @param y 左上角点y坐标
/// @param x_end 右下角点x坐标
/// @param y_end 右下角点y坐标
/// @param rgb 填充颜色
/// @param wide 线宽像素
void write_rectangle_no(Picture_msg_t* date,uint16_t x,uint16_t y,uint16_t x_end,uint16_t y_end,WS2812_msg_t* rgb,uint16_t wide)
{
    // 判断输入的数据合法性
    if((x_end - x <= 0) || ((y_end - y <= 0)))
    {
        return ;
    }

    // 判断输入值是否超过边界
    if(x_end > RGB_KEY) x_end = RGB_KEY;
    if(y_end > RGB_BAR) y_end = RGB_BAR;

    // 上边框
    write_rectangle_full(date,x,y,x_end,(y+wide),rgb);
    // 下边框
    write_rectangle_full(date,x,(y_end - wide),x_end,y_end,rgb);
    // 左边框
    write_rectangle_full(date,x,y,(x+wide),y_end,rgb);
    // 右边框
    write_rectangle_full(date,(x_end - wide),y,x_end,y_end,rgb);
}



/// @brief 画圆形
/// @param date 信息结构体
/// @param x 圆心x坐标
/// @param y 圆心y坐标
/// @param r 圆的版ing
/// @param rgb 颜色
void write_circular_no(Display_msg_t* date,uint16_t x,uint16_t y,uint16_t r,WS2812_msg_t* rgb)
{
    
}





