
#include "bsp_ColorMixer.h"




static uint8_t if_sameRGB(WS2812_msg_t* data1,WS2812_msg_t* data2);





// 将混合好的颜色放到这个变量里面
extern Display_msg_t display_main;


/// @brief 两张图片混色(混色的时候忽略背景颜色)
/// @param date1 图片1
/// @param date2 图片2
/// @param back 背景颜色
void ColorMixer_two(Picture_msg_t* date1,Picture_msg_t* date2,WS2812_msg_t* back,Picture_msg_t* out)
{
    // 有空指针直接返回 不执行
    if(date1 == NULL || date2 == NULL || back == NULL || out == NULL) return;

    uint8_t state = 0;
    // 判断输入数据合法性
    if(date1->trans > 100 || date2->trans > 100)
    {
        return ;
    }

    if(date1->layer_num > date2->layer_num)
    {
        // 如果图片 1 大的话 就让state为1 
        state = 1;
    }
    else if(date1->layer_num < date2->layer_num)
    {
        // 图片2 大的话就让state 为 2
        state = 2;
    }
    else if(date1->layer_num == date2->layer_num)
    {
        // 如果他们图层相同就按照等比例混色
        state = 3;
    }

    if(state != 0)
    {
        if(state == 2)
        {
            for(uint16_t i = 0;i < RGB_KEY;i++)
            {
                for(uint16_t j = 0;j < RGB_BAR;j++)
                {
                    if(if_sameRGB(&date1->rgb[i][j],&date2->rgb[i][j]) == 1)
                    {
                        // 如果两个颜色相同就直接赋值
                        out->rgb[i][j].R = date1->rgb[i][j].R;
                        out->rgb[i][j].G = date1->rgb[i][j].G;
                        out->rgb[i][j].B = date1->rgb[i][j].B;
                    }
                    else
                    {
                        // 如果两个颜色不相同 就先判断 2 是不是背景色
                        if(if_sameRGB(&date2->rgb[i][j],back) == 1)
                        {
                            // 如果 2 是背景色的话 就说明 1 不是背景色 给他赋值 1
                            out->rgb[i][j].R = date1->rgb[i][j].R;
                            out->rgb[i][j].G = date1->rgb[i][j].G;
                            out->rgb[i][j].B = date1->rgb[i][j].B;
                        }
                        else
                        {
                            // 如果 2 不是背景色 就是直接赋值 2 
                            out->rgb[i][j].R = date2->rgb[i][j].R;
                            out->rgb[i][j].G = date2->rgb[i][j].G;
                            out->rgb[i][j].B = date2->rgb[i][j].B;
                        }
                    }
                }
            }
        }
        else if(state == 1)
        {
            for(uint16_t i = 0;i < RGB_KEY;i++)
            {
                for(uint16_t j = 0;j < RGB_BAR;j++)
                {
                    if(if_sameRGB(&date1->rgb[i][j],&date2->rgb[i][j]) == 1)
                    {
                        // 如果两个颜色相同就直接赋值
                        out->rgb[i][j].R = date1->rgb[i][j].R;
                        out->rgb[i][j].G = date1->rgb[i][j].G;
                        out->rgb[i][j].B = date1->rgb[i][j].B;
                    }
                    else
                    {
                        // 如果两个颜色不相同 就先判断 2 是不是背景色
                        if(if_sameRGB(&date1->rgb[i][j],back) == 1)
                        {
                            // 如果 2 是背景色的话 就说明 1 不是背景色 给他赋值 1
                            out->rgb[i][j].R = date2->rgb[i][j].R;
                            out->rgb[i][j].G = date2->rgb[i][j].G;
                            out->rgb[i][j].B = date2->rgb[i][j].B;
                        }
                        else
                        {
                            // 如果 2 不是背景色 就是直接赋值 2 
                            out->rgb[i][j].R = date1->rgb[i][j].R;
                            out->rgb[i][j].G = date1->rgb[i][j].G;
                            out->rgb[i][j].B = date1->rgb[i][j].B;
                        }
                    }
                }
            }
        }
    }

    // 如果没有 100% 透明度的时候
    if(state == 0)
    {
        for(uint16_t i = 0;i < RGB_KEY;i++)
        {
            for(uint16_t j = 0;j < RGB_BAR;j++)
            {
                if(if_sameRGB(&date1->rgb[i][j],back) == 1)
                {
                    // 如果 1 为背景色的话就 直接赋值 2
                    out->rgb[i][j].R = date2->rgb[i][j].R;
                    out->rgb[i][j].G = date2->rgb[i][j].G;
                    out->rgb[i][j].B = date2->rgb[i][j].B;
                }
                else
                {
                    // 如果1 不是背景色 就判断2是不是背景色
                    if(if_sameRGB(&date2->rgb[i][j],back) == 1)
                    {
                        // 如果 1 不是背景色但是 2 是背景色，就直接赋值1
                        out->rgb[i][j].R = date1->rgb[i][j].R;
                        out->rgb[i][j].G = date1->rgb[i][j].G;
                        out->rgb[i][j].B = date1->rgb[i][j].B;
                    }
                    else
                    {
                        // 如果两个都不是背景色的话  就开始混色处理
                        // 计算混色系数
                        float q = (float)date1->trans/((float)date1->trans + (float)date2->trans);
                        float p = 1-q;
                        out->rgb[i][j].R = date1->rgb[i][j].R * q + date2->rgb[i][j].R * p;
                        out->rgb[i][j].G = date1->rgb[i][j].G * q + date2->rgb[i][j].G * p;
                        out->rgb[i][j].B = date1->rgb[i][j].B * q + date2->rgb[i][j].B * p;
                    }
                }
            }
        }
        
    }
}

/// @brief 加背景混色
/// @param date1 图片1
/// @param date2 图片2
/// @param out 输出
void ColorMixer_two_free(Picture_msg_t* date1,Picture_msg_t* date2,Picture_msg_t* out,WS2812_msg_t* back)
{
    // 有空指针直接返回 不执行
    if(date1 == NULL || date2 == NULL || back == NULL || out == NULL) return;

    uint8_t state = 0;
    // 判断输入数据合法性
    if(date1->trans > 100 || date2->trans > 100)
    {
        return ;
    }

    if(date1->layer_num > date2->layer_num)
    {
        // 如果图片 1 大的话 就让state为1 
        state = 1;
    }
    else if(date1->layer_num < date2->layer_num)
    {
        // 图片2 大的话就让state 为 2
        state = 2;
    }
    else if(date1->layer_num == date2->layer_num)
    {
        // 如果他们图层相同就按照等比例混色
        state = 3;
    }

    if(state == 1)
    {
        // 如果图片 1 在 2 的上面
        for(uint16_t i = 0;i < RGB_KEY;i ++)
        {
            for(uint16_t j = 0;j < RGB_BAR;j++)
            {
                if(if_sameRGB(&date1->rgb[i][j],back) == 1)
                {
                    float q = (float)date2->trans / 100;
                    // 如果 1 为背景色的话就 直接赋值 2
                    out->rgb[i][j].R = date2->rgb[i][j].R * q + (1 - q) * back->R;
                    out->rgb[i][j].G = date2->rgb[i][j].G * q + (1 - q) * back->G;
                    out->rgb[i][j].B = date2->rgb[i][j].B * q + (1 - q) * back->B;
                }
                else
                {
                    // 如果1 不是背景色 就判断2是不是背景色
                    if(if_sameRGB(&date2->rgb[i][j],back) == 1)
                    {
                        float q = (float)date1->trans / 100;
                        // 如果 1 不是背景色但是 2 是背景色，就直接赋值1
                        out->rgb[i][j].R = date1->rgb[i][j].R * q + (1 - q) * back->R;
                        out->rgb[i][j].G = date1->rgb[i][j].G * q + (1 - q) * back->G;
                        out->rgb[i][j].B = date1->rgb[i][j].B * q + (1 - q) * back->B;
                    }
                    else
                    {
                        // 使用Alpha混色公式 先混合 2 与 背景色
                        float q = 1 - (float)date2->trans / 100;
                        float p = (float)date2->trans / 100;
                        out->rgb[i][j].R = q * back->R + p * date2->rgb[i][j].R;
                        out->rgb[i][j].G = q * back->G + p * date2->rgb[i][j].G;
                        out->rgb[i][j].B = q * back->B + p * date2->rgb[i][j].B;

                        q = 1 - (float)date1->trans / 100;
                        p = (float)date1->trans / 100;
                        // 再使用Alpha公式让 1 与 混合色进行混色
                        out->rgb[i][j].R = q * out->rgb[i][j].R + p * date1->rgb[i][j].R;
                        out->rgb[i][j].G = q * out->rgb[i][j].G + p * date1->rgb[i][j].G;
                        out->rgb[i][j].B = q * out->rgb[i][j].B + p * date1->rgb[i][j].B;
                    }
                }
            }
        }
    }
    else if(state == 2)
    {
        // 如果图片 2 在 1 的上面
        for(uint16_t i = 0;i < RGB_KEY;i ++)
        {
            for(uint16_t j = 0;j < RGB_BAR;j++)
            {
                if(if_sameRGB(&date1->rgb[i][j],back) == 1)
                {
                    // 如果 1 为背景色的话就 直接赋值 2
                    float q = (float)date2->trans / 100;
                    // 如果 1 为背景色的话就 直接赋值 2
                    out->rgb[i][j].R = date2->rgb[i][j].R * q + (1 - q) * back->R;
                    out->rgb[i][j].G = date2->rgb[i][j].G * q + (1 - q) * back->G;
                    out->rgb[i][j].B = date2->rgb[i][j].B * q + (1 - q) * back->B;
                }
                else
                {
                    // 如果1 不是背景色 就判断2是不是背景色
                    if(if_sameRGB(&date2->rgb[i][j],back) == 1)
                    {
                        // 如果 1 不是背景色但是 2 是背景色，就直接赋值1
                        float q = (float)date1->trans / 100;
                        // 如果 1 不是背景色但是 2 是背景色，就直接赋值1
                        out->rgb[i][j].R = date1->rgb[i][j].R * q + (1 - q) * back->R;
                        out->rgb[i][j].G = date1->rgb[i][j].G * q + (1 - q) * back->G;
                        out->rgb[i][j].B = date1->rgb[i][j].B * q + (1 - q) * back->B;
                    }
                    else
                    {
                        // 使用Alpha混色公式 先混合 2 与 背景色
                        float q = 1 - (float)date1->trans / 100;
                        float p = (float)date1->trans / 100;
                        out->rgb[i][j].R = q * back->R + p * date1->rgb[i][j].R;
                        out->rgb[i][j].G = q * back->G + p * date1->rgb[i][j].G;
                        out->rgb[i][j].B = q * back->B + p * date1->rgb[i][j].B;

                        q = 1 - (float)date2->trans / 100;
                        p = (float)date2->trans / 100;
                        // 再使用Alpha公式让 1 与 混合色进行混色
                        out->rgb[i][j].R = q * out->rgb[i][j].R + p * date2->rgb[i][j].R;
                        out->rgb[i][j].G = q * out->rgb[i][j].G + p * date2->rgb[i][j].G;
                        out->rgb[i][j].B = q * out->rgb[i][j].B + p * date2->rgb[i][j].B;
                    }
                }
            }
        }
    }
    else if(state == 3)
    {
        for(uint16_t i = 0;i < RGB_KEY;i++)
        {
            for(uint16_t j = 0;j < RGB_BAR;j++)
            {
                if(if_sameRGB(&date1->rgb[i][j],back) == 1)
                {
                    // 如果 1 为背景色的话就 直接赋值 2
                    out->rgb[i][j].R = date2->rgb[i][j].R;
                    out->rgb[i][j].G = date2->rgb[i][j].G;
                    out->rgb[i][j].B = date2->rgb[i][j].B;
                }
                else
                {
                    // 如果1 不是背景色 就判断2是不是背景色
                    if(if_sameRGB(&date2->rgb[i][j],back) == 1)
                    {
                        // 如果 1 不是背景色但是 2 是背景色，就直接赋值1
                        out->rgb[i][j].R = date1->rgb[i][j].R;
                        out->rgb[i][j].G = date1->rgb[i][j].G;
                        out->rgb[i][j].B = date1->rgb[i][j].B;
                    }
                    else
                    {
                        // 如果两个都不是背景色的话  就开始混色处理
                        // 计算混色系数
                        float q = (float)date1->trans/((float)date1->trans + (float)date2->trans);
                        float p = 1-q;
                        out->rgb[i][j].R = date1->rgb[i][j].R * q + date2->rgb[i][j].R * p;
                        out->rgb[i][j].G = date1->rgb[i][j].G * q + date2->rgb[i][j].G * p;
                        out->rgb[i][j].B = date1->rgb[i][j].B * q + date2->rgb[i][j].B * p;
                    }
                }
            }
        }
    }
}





/// @brief 判断两个RGB是否相等
/// @param data1 第一个
/// @param data2 第二个
/// @return 相等返回1  不相等返回0
static uint8_t if_sameRGB(WS2812_msg_t* data1,WS2812_msg_t* data2)
{
    if(data1->R == data2->R)
    {
        if(data1->G == data2->G)
        {
            if(data1->B == data2->B)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
