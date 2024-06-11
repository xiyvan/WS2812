
#include "bsp_stringTobuff.h"
#include "Z_math.h"



void display_char(WS2812_msg_t* data,uint8_t* buf,uint8_t wei)
{
    
}


uint8_t last_num_l[4][3];



/// @brief 旋转拖尾效果
/// @param data 
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




/// @brief 旋转变化效果
/// @param data 数据
void blink_effect(Display_msg_t* data)
{
    static uint8_t num = 1;
    static uint8_t r = 0,g = 0,b = 200;

    Ws2812_Set(data,1,num,r,g,b);

    if(b >= 200)
    {
        if(g >= 1)
        {
            g -= 10;
        }
        r += 10;
    } 
    if(r >= 200)
    {
        g += 10;
        if(b >= 1)
        {
            b -= 10;
        }
    } 
    if(g >= 200) 
    {
        if(r >= 1)
        {
            r -= 10;
        }
        b += 10;
    }

    num ++;
    if(num > 12) num = 1;
}



/// @brief 矩形填充
/// @param date 页面数据
/// @param x 左上角点x坐标
/// @param y 左上角点y坐标
/// @param x_end 右下角点x坐标
/// @param y_end 右下角点y坐标
/// @param rgb 填充颜色
void write_rectangle_full(Display_msg_t* date,uint16_t x,uint16_t y,uint16_t x_end,uint16_t y_end,WS2812_msg_t* rgb)
{
    // 判断输入的数据合法性
    if((x_end - x <= 0) || ((y_end - y <= 0)))
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
void write_rectangle_no(Display_msg_t* date,uint16_t x,uint16_t y,uint16_t x_end,uint16_t y_end,WS2812_msg_t* rgb,uint16_t wide)
{
    // 判断输入的数据合法性
    if((x_end - x <= 0) || ((y_end - y <= 0)))
    {
        return ;
    }

    // 判断输入值是否超过边界
    if(x_end > RGB_KEY) x_end = RGB_KEY;
    if(y_end > RGB_BAR) y_end = RGB_BAR;
    if(wide == 0) wide = 1;

    // 上边框
    write_rectangle_full(date,x,y,x_end,(y+wide),rgb);
    // 下边框
    write_rectangle_full(date,x,(y_end - wide),x_end,y_end,rgb);
    // 左边框
    write_rectangle_full(date,x,y,(x+wide),y_end,rgb);
    // 右边框
    write_rectangle_full(date,(x - wide),y,x_end,y_end,rgb);
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

