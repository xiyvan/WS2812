/***************************
 * 创建时间：24-6-12
 * 作者：韩昂轩（HAX）
 * 
 * 任务分配函包
***************************/



#include "Task_create.h"


extern TIM_HandleTypeDef htim3;

///************************************** 任务专属变量定义  ******************************* */

volatile uint16_t task_delay50ms = 0;


///********************************************* 函数声明  ***********************************/
static void task_50ms(void);



///***************************************** endl*********************************************/





/// @brief 任务开始
void Task_Star(void)
{
    while (1)
    {
        task_50ms();
    }
}





void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim == (&htim3))
    {
        task_delay50ms ++;
    }
}





/// @brief 50ms执行一次的任务
static void task_50ms(void)
{
    if(task_delay50ms >= 170)
    {
        display_show();
        task_delay50ms = 0;
    }
}


