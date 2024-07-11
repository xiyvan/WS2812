
#include "Temputer.h"
#include "string.h"


temputer_msg_t Temputer_main;
extern Display_msg_t display_main;


void Temputer_show(void)
{
    static unsigned char n = 0;
    static unsigned char number = 0;    // 用来延时
    if(n == 0)
    {

        n = 1;
    }

    number ++;

    if(number >= 25)
    {
        dht11_ReadDate(&Temputer_main.temp_date);       // 读取温度

        sprintf(Temputer_main.T,"%1d",(short)Temputer_main.temp_date.temputer / 10);                      // 温度十位
        sprintf(&Temputer_main.T[1],"%1d",(short)Temputer_main.temp_date.temputer % 10);               // 温度个位
        sprintf(&Temputer_main.T[2],"%1d",(short)(Temputer_main.temp_date.temputer * 10) % 10);        // 温度小数位

        sprintf(&Temputer_main.T[3],"%1d",(short)Temputer_main.temp_date.humidity / 10);                      // 湿度十位
        sprintf(&Temputer_main.T[4],"%1d",(short)Temputer_main.temp_date.humidity % 10);               // 湿度个位
        sprintf(&Temputer_main.T[5],"%1d",(short)(Temputer_main.temp_date.humidity * 10) % 10);        // 湿度小数位

        Picture_Create(&Temputer_main.date,1,100,2,2,8,32);                     // 温度
        Write_OneChar(&Temputer_main.date,209,59,13,Temputer_main.T[0],0);
        Picture_Create(&Temputer_main.date,1,100,2,6,8,32);
        Write_OneChar(&Temputer_main.date,209,59,13,Temputer_main.T[1],0);
        Ws2812_Set(&Temputer_main.date,6,10,209,59,13);                         // 小数点
        Picture_Create(&Temputer_main.date,1,100,2,12,8,32);
        Write_OneChar(&Temputer_main.date,209,59,13,Temputer_main.T[2],0);      // 小数位


        Picture_Create(&Temputer_main.date,1,100,2,18,8,32);                     // 湿度
        Write_OneChar(&Temputer_main.date,54,135,222,Temputer_main.T[3],0);
        Picture_Create(&Temputer_main.date,1,100,2,22,8,32);
        Write_OneChar(&Temputer_main.date,54,135,222,Temputer_main.T[4],0);
        Ws2812_Set(&Temputer_main.date,6,26,54,135,222);                         // 小数点
        Picture_Create(&Temputer_main.date,1,100,2,28,8,32);
        Write_OneChar(&Temputer_main.date,54,135,222,Temputer_main.T[5],0);      // 小数位


        WS2812_Change_free(display_main.buff,Temputer_main.date.rgb);
        clear_all(&Temputer_main.date.rgb);

        number = 0;
    }

}

