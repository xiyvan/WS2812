
#include "bsp_Animation.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

///**************************************************  滚动效果  ****************************************************/

/// @brief 滚动效果
/// @param data 颜色数据
/// @param Animat_main 反回的图片数据
void slide_effect(Picture_msg_t* data,Animation_msg_t* Animat_main)
{
    // 空指针直接返回不执行
    if(Animat_main == NULL || data == NULL) return ;

    switch(Animat_main->direction)
    {
        case SLIDE_EFFECT_STATE_LEFT:
        {
            // 向左边滚
            // 让每列的数值都向左移动
            for(uint8_t j = (Animat_main->y - 1);j < (Animat_main->y_end - 1); j++)
            {
                for(uint8_t i = (Animat_main->x - 1);i < (Animat_main->x_end);i++)
                {
                    Animat_main->date.rgb[i][j] = Animat_main->date.rgb[i][j+1];
                }
            }
            // 更新最右边的一列
            for(uint8_t i = (Animat_main->x -1);i < (Animat_main->x_end);i++)
            {
                Animat_main->date.rgb[i][Animat_main->y_end - 1] = data->rgb[i][Animat_main->num];
            }

            Animat_main->num ++;
            if(Animat_main->num > (data->size.y_end - 1))
            {
                Animat_main->num = (data->size.y - 1);
                // 标记为循环完1遍
                Animat_main->state = 1;
            }
            
        }break;
        case SLIDE_EFFECT_STATE_RIGHT:
        {
            // 向右滚
            for(uint8_t j = (Animat_main->y_end -1);j > (Animat_main->y -1); j--)
            {
                for(uint8_t i = (Animat_main->x -1);i < (Animat_main->x_end);i++)
                {
                    Animat_main->date.rgb[i][j] = Animat_main->date.rgb[i][j-1];
                }
            }

            // 更新最左边的一列
            for(uint8_t i = (Animat_main->x -1);i < (Animat_main->x_end);i++)
            {
                Animat_main->date.rgb[i][Animat_main->y - 1] = data->rgb[i][Animat_main->num];
            }

            Animat_main->num --;
            if(Animat_main->num < (data->size.y - 1))
            {
                Animat_main->num = (data->size.y_end - 1);
                // 标记为循环完1遍
                Animat_main->state = 1;
            }
        }break;
        case SLIDE_EFFECT_STATE_UP:
        {
            // 向上滚
            for(uint8_t j = (Animat_main->x -1);j < (Animat_main->x_end-1); j++)
            {
                for(uint8_t i = (Animat_main->y -1);i < Animat_main->y_end;i++)
                {
                    Animat_main->date.rgb[j][i] = Animat_main->date.rgb[j+1][i];
                }
            }

            for(uint8_t i = (Animat_main->x - 1);i < Animat_main->x_end;i++)
            {
                Animat_main->date.rgb[Animat_main->x_end-1][i] = data->rgb[Animat_main->num][i];
            }

            Animat_main->num ++;
            if(Animat_main->num > Animat_main->x_end-1)
            {
                Animat_main->num = Animat_main->x -1;
                // 标记为循环完1遍
                Animat_main->state = 1;
            }
        }break;
        case SLIDE_EFFECT_STATE_DOWN:
        {
            // 向下滚动
            for(uint8_t j = (Animat_main->x_end - 1);j > (Animat_main->x-1); j--)
            {
                for(uint8_t i = Animat_main->y-1;i < Animat_main->y_end;i++)
                {
                    Animat_main->date.rgb[j][i] = Animat_main->date.rgb[j-1][i];
                }
            }

            for(uint8_t i = Animat_main->x-1;i < Animat_main->x_end;i++)
            {
                Animat_main->date.rgb[Animat_main->x-1][i] = data->rgb[Animat_main->num][i];
            }

            Animat_main->num --;
            if(Animat_main->num < Animat_main->x-1)
            {
                Animat_main->num =Animat_main->x_end-1;
                // 标记为循环完1遍
                Animat_main->state = 1;
            }  
        }break;
    }
}




/// @brief 滚动动画创建 
/// @param direction 滚动方向
/// @return 动画效果指针
Animation_msg_t* SlideEffect_create(Animation_msg_t* date,Picture_msg_t* pic,unsigned char direction,unsigned short x_end,unsigned short y_end)
{
    //Animation_msg_t* date = (Animation_msg_t*)malloc(sizeof(Animation_msg_t));
    if(date == NULL) return NULL;

    date->x = pic->size.x;
    date->y = pic->size.y;
    date->x_end = x_end;
    date->y_end = y_end;
    date->direction = direction;
    date->date.size.x = pic->size.x;
    date->date.size.y = pic->size.y;
    date->date.size.x_end = x_end;
    date->date.size.y_end = y_end;
    date->date.layer_num = pic->layer_num;
    date->date.trans = pic->trans;
    
    return date;
}



///**************************************************  飘落入场效果  ****************************************************/



void Animation_drifting_effect(Anima_drifting_msg_t* date,Picture_msg_t* pic)
{
    if(date == NULL || pic == NULL) return ;


    if(date->animation.direction == SLIDE_EFFECT_STATE_DOWN)
    {
        // 向下飘落
        if(date->state == 0)
        {
            date->num = 0;
            // 如果是第一次进入飘落
            for(uint8_t i = date->animation.y - 1;i < date->animation.y_end - 1;i++)
            {
                date->animation.date.rgb[0][i] = pic->rgb[pic->size.x_end - date->animation.num][i];
            }
            // 让飘落到文字的哪一行了 +1
            date->animation.num ++;
            // 不是第一次飘落 置一
            date->state = 1;
        }
        else
        {
            // 不是第一次进入飘落的话  就让每个像素点向下移动到指定位置 然后让标志位置零开启下一次飘落
            // 判断飘子有没有成功落位
            if(date->num >= date->animation.x_end - date->animation.num - 1)
            {
                // 如果落位成功就开启下一次飘落
                date->state = 0;
                if(date->animation.num >= date->animation.x_end - date->animation.x)
                {
                    // 标记为循环完毕
                    date->animation.state = 1;
					date->animation.num = 0;
                }
            }
            else
            {
                // 没有落位成功
                // 整体向下移位
                for(uint8_t i = date->animation.x_end-1-date->animation.num;i > 0;i--)
                {
                    for(uint8_t j = date->animation.y-1;j < date->animation.y_end;j++)
                    {
                        date->animation.date.rgb[i][j] = date->animation.date.rgb[i-1][j];
                    }
                }
            }
            if(date->animation.state != 1)
            {
                WS2812_msg_t temp;
                temp.B = 0;
                temp.R = 0;
                temp.G = 0;
                for(uint8_t j = date->animation.y-1;j < date->animation.y_end;j++)
                {
                    date->animation.date.rgb[0][j] = temp;
                }
            }

			date->num ++;
        }
    }
}



/// @brief 初始化飘落动画
/// @param date 飘落动画结构体变量指针
/// @param pic 图片指针
/// @param direction 飘落方向
/// @param x_end 动画结束的坐标
/// @param y_end 动画结束的坐标
/// @note 动画继承图片的初始坐标、图层号与透明度
void Animation_drifting_effectCreate(Anima_drifting_msg_t* date,Picture_msg_t* pic,unsigned char direction,unsigned short x_end,unsigned short y_end)
{
    if(date == NULL || pic == NULL) return ;

    date->animation.x = pic->size.x;
    date->animation.y = pic->size.y;
    date->animation.x_end = x_end;
    date->animation.y_end = y_end;
    date->animation.direction = direction;
    date->animation.date.size.x = pic->size.x;
    date->animation.date.size.y = pic->size.y;
    date->animation.date.size.x_end = x_end;
    date->animation.date.size.y_end = y_end;
    date->animation.date.layer_num = pic->layer_num;
    date->animation.date.trans = pic->trans;
    date->state = 0;
    date->animation.num = 0;
    date->animation.state = 0;

}


