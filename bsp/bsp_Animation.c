
#include "bsp_Animation.h"
#include <string.h>

/*
/// 旋转拖尾用
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

    Ws2812_Set(data,1,num,200,0,0);
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
            g -= 2;
        }
        r += 2;
    } 
    if(r >= 200)
    {
        g += 2;
        if(b >= 1)
        {
            b -= 2;
        }
    } 
    if(g >= 200) 
    {
        if(r >= 1)
        {
            r -= 2;
        }
        b += 2;
    }

    num ++;
    if(num > 12) num = 1;
    else if(num == 1) num = 0;

}





/// @brief 坠落效果函数（圆形 从顶上发出到地下结束）
/// @param data 
void Falling_effect(Display_msg_t* data)
{
    static uint8_t num = 1;
    static uint8_t num_ = 13;
    static uint8_t state = 1;
    static uint8_t r = 0,g = 0,b = 200;

    for(int i = 1;i < 13;i++)
    {
        Ws2812_Set(data,1,i,0,0,0);
    }

    Ws2812_Set(data,1,num,r,g,b);
    Ws2812_Set(data,1,num_,r,g,b);



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


    if(state == 1)
    {
        num_ --;
        num ++;
    }
    else if(state == 0)
    {
        num_ ++;
        num --;
    }

    if(num > 6) state = 0;
    else if(num == 1) state = 1;
}





/// @brief 点阵屏旋转效果
void matrix_Falling_effect(Display_msg_t* data)
{
    static uint8_t num = 1,key = 1;
    static uint8_t state = 0;
    static uint8_t r = 0,g = 0,b = 100;


    Ws2812_Set(data,key,num,r,g,b);

    if(b >= 100)
    {
        if(g >= 1)
        {
            g -= 2;
        }
        r += 2;
    } 
    if(r >= 100)
    {
        g += 2;
        if(b >= 1)
        {
            b -= 2;
        }
    } 
    if(g >= 100) 
    {
        if(r >= 1)
        {
            r -= 2;
        }
        b += 2;
    }

    if(state == 0)
    {
        num ++;
    }
    else if(state == 1)
    {
        num --;
    }

    if(num > 8)
    {
        state = 1;
        num = 8;
        key ++;
        if(key > 5) key = 1;
    }
    else if(num < 1)
    {
        state = 0;
        num = 1;
        key ++;
        if(key > 5) key = 1;
    }
}


///点阵屏测试
void matrix_test(Display_msg_t* display_main)
{
    static WS2812_msg_t test[2];
    test[0].R = 30;
    test[0].G = 5;
    test[0].B = 0;
    test[1].R = 78;
    test[1].G = 102;
    test[1].B = 24;
    static int8_t num = 0,state = 0;
    write_rectangle_full(display_main,1,1,5,8,&test[0]);
    if(num == 0) write_rectangle_no(display_main,1,2,5,7,&test[1],0);
    else if(num == 1) write_rectangle_no(display_main,2,3,4,6,&test[1],0);
    else if(num == 2) write_rectangle_full(display_main,3,4,3,5,&test[1]);

    if(state == 0)
    {
        num ++;
    }
    else if(state == 1)
    {
        num --;
    }

    if(num >= 2) state = 1;
    else if(num < 1)
    {
        state = 0;
    } 
}

*/

//WS2812_msg_t Animat_main[RGB_KEY+1][RGB_BAR];
Picture_msg_t Animat_main;


/// @brief 从右向左移动效果
/// @param data 
void slide_right_effect(WS2812_msg_t data[RGB_KEY][RGB_KEY])
{
    static uint16_t num = 0;
    Animat_main.trans = 99;
    Animat_main.layer_num = 1;

    // 让每列的数值都向左移动
    for(uint8_t j = 0;j < (RGB_BAR-1); j++)
    {
        for(uint8_t i = 0;i < RGB_KEY;i++)
        {
            Animat_main.rgb[i][j] = Animat_main.rgb[i][j+1];
        }
    }

    // 更新最右边的一列
    for(uint8_t i = 0;i < RGB_KEY;i++)
    {
        Animat_main.rgb[i][RGB_BAR-1] = data[i][num];
    }

    num ++;
    if(num > RGB_BAR-1)
    {
        num = 0;
    } 
}
