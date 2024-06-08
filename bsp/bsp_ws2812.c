
#include "bsp_ws2812.h"


extern SPI_HandleTypeDef hspi1;


Display_msg_t display_main;




/// @brief 颜色设置函数
/// @param data 信息结构体
/// @param key 行号
/// @param bar 列号
/// @param R 红
/// @param G 绿
/// @param B 蓝
void Ws2812_Set(Display_msg_t* data,unsigned char key,unsigned char bar,unsigned char R,unsigned char G,unsigned char B)
{
    data->date[key-1][bar-1].R = R;
    data->date[key-1][bar-1].G = G;
    data->date[key-1][bar-1].B = B;
}





/// @brief 显示转换 由灯珠颜色转换到缓存
void WS2812_Change(Display_msg_t* data)
{
    unsigned int j = 0;

    for(int k = 0;k < RGB_KEY;k++)
    {
        for(int b = 0;b < RGB_BAR;b++)
        {
            for (int i = 0; i < 8; i++)
            {
                data->buff[(j * 24) + 7 - i]  = (((data->date[k][b].G >>i)&0x01) ? WS2812_HighLevel : WS2812_LowLevel)>>1;
                data->buff[(j * 24) + 15 - i] = (((data->date[k][b].R >>i)&0x01) ? WS2812_HighLevel : WS2812_LowLevel)>>1;
                data->buff[(j * 24) + 23 - i] = (((data->date[k][b].B >>i)&0x01) ? WS2812_HighLevel : WS2812_LowLevel)>>1;
            }
            j++;
        }
    }
}


/// @brief 显示推送
/// @param data 屏显信息结构体指针
void Display_Show(Display_msg_t* data)
{
    unsigned char res = 0;
    while (hspi1.State != HAL_SPI_STATE_READY);
    HAL_SPI_Transmit(&hspi1,data->buff, RGB_NUM * 24, 0xFFFF);
    for (int i = 0; i < 100; i++)
    {
        HAL_SPI_Transmit(&hspi1, &res, 1, 0xFFFF);
    }
}



