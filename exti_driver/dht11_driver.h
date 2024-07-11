
#ifndef _DHT11_DRIVER_H_
#define _DHT11_DRIVER_H_


typedef struct 
{
    float humidity;
    float temputer;
    unsigned char buff[5];
}dht11_msg_t;



void dht11_ReadDate(dht11_msg_t* date);



#endif
