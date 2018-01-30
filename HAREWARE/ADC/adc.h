#ifndef __ADC_H
#define __ADC_H	
#include "sys.h"

void Adc_Init(void);
u16  Get_Adc(u8 ch);



u16 Get_Adc_Average(u8 ch,u8 times); //求读取times次ADC的平均值  示例：Get_Adc_Average(ADC_Channel_1,10);

 
#endif 
