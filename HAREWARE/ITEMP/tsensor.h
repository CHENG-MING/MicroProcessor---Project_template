#ifndef __TSENSOR_H
#define __TSENSOR_H	
#include "stm32f10x.h"
	  
 		 
#define ADC_CH_TEMP  	ADC_Channel_16 //温度传感器通道
   

void T_Adc_Init(void); //ADC通道初始化
u16  T_Get_Adc(u8 ch); //获得某个通道值  







u16  T_Get_Adc_Temperature(void);//得到内部温度传感器通道10次采样的adc值后计算温度


#endif 
