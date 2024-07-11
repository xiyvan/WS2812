
#include "dht11_driver.h"
#include "string.h"
#include "stm32f4xx_hal.h"

///****************************************** 函数声明 ****************************************/






/// ***************************************** 变量定义 ***************************************/
extern TIM_HandleTypeDef htim2;





///****************************************** 中间函数 ********************************************* */

/// @brief dht11的IO口的输出电平状态
/// @param state 电平 1 ~ 0
static void dht11_GpioOut(unsigned char state)
{
    if(state)
    {
        GPIOB->BSRR = GPIO_PIN_11;
    }
    else
    {
        GPIOB->BSRR = (unsigned int)GPIO_PIN_11 << 16;
    }
}


/// @brief 设置dht11的IO口模式
/// @param Mode 0 输出 1 输入
static void dht11_GpioInit(unsigned char Mode)
{
    GPIO_InitTypeDef init;

    init.Pin = GPIO_PIN_11;
    init.Speed = GPIO_SPEED_MEDIUM;

    if(Mode == 0)
    {
        init.Mode = GPIO_MODE_OUTPUT_PP;
    }
    else 
    {
        init.Mode = GPIO_MODE_INPUT;
    }

    HAL_GPIO_Init(GPIOB,&init);
}


/// @brief dht11用的微妙级延时
/// @param time 延时时间
static void dht11_DelayUs(unsigned int time)
{
    HAL_TIM_Base_Start(&htim2);
    while(time --)
    {
        while(!__HAL_TIM_GET_FLAG(&htim2,TIM_FLAG_UPDATE));
        __HAL_TIM_CLEAR_FLAG(&htim2,TIM_FLAG_UPDATE);
    }
    HAL_TIM_Base_Stop(&htim2);
}


/// @brief 读取dht11的引脚电平状态
/// @return 返回引脚电平状态
static unsigned char dht11_ReadGpioState(void)
{
    return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11);
}




///************************************* endl ********************************/





/// @brief dht11的起始信号
/// @return 应答成功 1 ，应答失败 0
static unsigned char dht11_Star(void)
{
    unsigned int n = 150;     // 等待dht11回应时间

    dht11_GpioInit(0);          // 设置为输出模式
    dht11_GpioOut(0);           // 拉低电平
    dht11_DelayUs(20000);       // 延时20ms
    dht11_GpioOut(1);           // 释放总线
    dht11_DelayUs(30);
    dht11_GpioInit(1);          // 设置为输入模式

    // 等待dht11拉低信号进行应答
    while (n --)
    {
        // 如果产生了拉低信号 说明进行了应答
        if(dht11_ReadGpioState() == 0)
        {
            // 推出循环
            break;
        }
        // 每隔1us检测一次
        dht11_DelayUs(1);
    }

    // 如果n等于0被退出循环的说明应答超时
    if(n == 0)
    {
        // 返回应答失败
        return 0;
    }
    return 1;
}




void dht11_ReadDate(dht11_msg_t* date)
{
    if(date == 0) return ;

    memset(&date->buff,0,sizeof(date->buff));   // 清除缓存

    if(dht11_Star() == 0) return ;

    //dht11_DelayUs(80);  // 等待高电平结束
    while(!dht11_ReadGpioState());

    for(unsigned char j = 0;j<5;j++)
    {
        for(unsigned char i = 0;i<8;i++)
        {
            while(dht11_ReadGpioState());       // 等待读到低电平
            while(!dht11_ReadGpioState());      // 等待高电平  如果接受到高电平--
            dht11_DelayUs(30);                  // 等待35us然后检测电平
            if(dht11_ReadGpioState() == 1)
            {
                date->buff[j] = (date->buff[j] << 1) | 0x01;  
            }
            else
            {
                date->buff[j] = (date->buff[j] << 1);
            }
        }
    }

    if((unsigned char)(date->buff[0] + date->buff[1] + date->buff[2] + date->buff[3]) == date->buff[4])
    {
        date->humidity = date->buff[0] + (float)date->buff[1] / 10.0f;      // 计算湿度
        date->temputer = date->buff[2] + (float)date->buff[3] / 10.0f;      // 计算温度
    }

}


