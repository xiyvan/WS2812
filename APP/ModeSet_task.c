
#include "ModeSet_task.h"
#include "Light.h"


static unsigned char ReadKey(void);


ModeSet_msg_t mode_main;
extern Light_msg_t Light_main;

void ModeSet_task(void)
{
    static char num = 0;

    if(num == 0)
    {
        memset(&mode_main,0,sizeof(mode_main));
        num = 1;
    }

    mode_main.now = ReadKey();

//********************************************************* 显示模式设置 ********************************************/

    if(mode_main.now == 0 && mode_main.last_now == 4)
    {
        mode_main.Display_mode ++;
        if(mode_main.Display_mode > 2) mode_main.Display_mode = 2;
    }
    else if(mode_main.now == 0 && mode_main.last_now == 2)
    {
        mode_main.Display_mode --;
        if(mode_main.Display_mode < 0) mode_main.Display_mode = 0;
    }


///********************************************************** 调光 **************************************************/

    if(mode_main.Display_mode == MODE_DISPLAY_LIGHT)
    {
        if(mode_main.now == 0 && mode_main.last_now == 1)
        {
            Light_main.up_state = 1;
            Light_Change();
        }
        else if(mode_main.now == 0 && mode_main.last_now == 3)
        {
            Light_main.down_state = 1;
            Light_Change();
        }
    }

///********************************************************** endl ***************************************************/


    mode_main.last_now = mode_main.now;
}






/// @brief 如果读取到按键的动作就返回相应的数字
/// @return 如果没有读取到就返回 0
static unsigned char ReadKey(void)
{
    if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0))
    {
        return 1;
    }
    else if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_2) == 0)
    {
        return 2;
    }
    else if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_3) == 0)
    {
        return 3;
    }
    else if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4) == 0)
    {
        return 4;
    }

    return 0;
}
