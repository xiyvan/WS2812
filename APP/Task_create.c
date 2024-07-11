/***************************
 * 创建时间：24-6-12
 * 作者：韩昂轩（HAX）
 * 
 * 任务分配函包
***************************/



#include "Task_create.h"
#include "ModeSet_task.h"

extern TIM_HandleTypeDef htim3;

///************************************** 任务专属变量定义  ******************************* */

volatile uint8_t task_delay50ms = 0;
volatile uint8_t task_delay10ms = 0;
volatile uint8_t task_delay20ms = 0;
volatile uint8_t task_delay100ms = 0;

///********************************************* 函数声明  ***********************************/
static void task_50ms(void);
static void task_100ms(void);
static void task_10ms(void);
static void task_20ms(void);

///***************************************** endl*********************************************/





/// @brief 任务开始
void Task_Star(void)
{
    while (1)
    {
        task_50ms();
        task_10ms();
        task_20ms();
        task_100ms();
    }
}





void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim == (&htim3))
    {
        task_delay50ms ++;
        task_delay10ms ++;
        task_delay20ms ++;
        task_delay100ms ++;
    }
}





/// @brief 50ms执行一次的任务
static void task_50ms(void)
{
    if(task_delay50ms >= 50)
    {
        
        task_delay50ms = 0;
    }
}


static void task_10ms(void)
{
    if(task_delay10ms >= 10)
    {
        ModeSet_task();
        task_delay10ms = 0;
    }
}



static void task_20ms(void)
{
    if(task_delay20ms >= 20)
    {
        display_show();
        task_delay20ms = 0;
    }
}


static void task_100ms(void)
{
    if(task_delay100ms >= 100)
    {
        
        task_delay100ms = 0;
    }

}
