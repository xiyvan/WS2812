
#ifndef _TEMPUTER_H_
#define _TEMPUTER_H_


#include "dht11_driver.h"
#include "bsp_ws2812.h"


typedef struct 
{
    Picture_msg_t date;
    dht11_msg_t temp_date;
    char T[6];              // 用来保存6个字符
}temputer_msg_t;





void Temputer_show(void);





#endif
