
#include "bsp_ws2812.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

extern SPI_HandleTypeDef hspi1;


Display_msg_t display_main;




/// @brief 颜色设置函数
/// @param data 信息结构体
/// @param key 行号
/// @param bar 列号
/// @param R 红
/// @param G 绿
/// @param B 蓝
void Ws2812_Set(Picture_msg_t* data,unsigned char key,unsigned char bar,unsigned char R,unsigned char G,unsigned char B)
{
    data->rgb[key-1][bar-1].R = R;
    data->rgb[key-1][bar-1].G = G;
    data->rgb[key-1][bar-1].B = B;
}


/// @brief 显示转换 由灯珠颜色转换到缓存
void WS2812_Change_free(unsigned char* data,WS2812_msg_t ws[RGB_KEY][RGB_BAR])
{
    unsigned int j = 0;

    // 横向拼接行数
    for(unsigned short key = 0;key < RGB_MIX_KEY;key++)
    {
        for(int k = 0;k < RGB_KEY_ONE;k++)
        {
            // 单块板行数
            for(int b = 0;b < RGB_BAR_ONE;b++)
            {
                // 单块板列数
                for (int i = 0; i < 8; i++)
                {
                    // 灯的RGB各个位数
                    data[(j * 24) + 7 - i]  = (((ws[k][b+key*RGB_BAR_ONE].G >>i)&0x01) ? WS2812_HighLevel : WS2812_LowLevel)>>1;
                    data[(j * 24) + 15 - i] = (((ws[k][b+key*RGB_BAR_ONE].R >>i)&0x01) ? WS2812_HighLevel : WS2812_LowLevel)>>1;
                    data[(j * 24) + 23 - i] = (((ws[k][b+key*RGB_BAR_ONE].B >>i)&0x01) ? WS2812_HighLevel : WS2812_LowLevel)>>1;
                }
                j++;
            }
        }
    }
}



/// @brief 显示推送
/// @param data 屏显信息结构体指针
void Display_Show(Display_msg_t* data)
{
    while (hspi1.State != HAL_SPI_STATE_READY);
    HAL_SPI_Transmit_DMA(&hspi1,data->buff,RGB_NUM * 24);
}



/// @brief 新建一个图片
/// @param layer_num 图层数目
/// @param trans 透明度 1~100
/// @param x 左上角x坐标
/// @param y 左上角y坐标
/// @param x_end 右下角x坐标
/// @param y_end 右下角y坐标
/// @return 
Picture_msg_t* Picture_Create(Picture_msg_t* date,unsigned char layer_num,unsigned char trans,unsigned short x,unsigned short y,unsigned short x_end,unsigned short y_end)
{
    // 申请内存空间
    //Picture_msg_t* date = (Picture_msg_t*)malloc(sizeof(Picture_msg_t));
    if(date == NULL) return NULL;

    // 初始化图片参数
    date->layer_num = layer_num;
    date->trans = trans;
    date->size.x = x;
    date->size.y = y;
    date->size.x_end = x_end;
    date->size.y_end = y_end;

    // 返回结构体变量指针
    return date;
}


/// @brief 删除图片
/// @param date 图片指针
void Picture_Delete(Picture_msg_t* date)
{
    free(date);
    date = NULL;
}

