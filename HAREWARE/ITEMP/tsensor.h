#ifndef __TSENSOR_H
#define __TSENSOR_H	
#include "stm32f10x.h"
	  
 		 
#define ADC_CH_TEMP  	ADC_Channel_16 //�¶ȴ�����ͨ��
   

void T_Adc_Init(void); //ADCͨ����ʼ��
u16  T_Get_Adc(u8 ch); //���ĳ��ͨ��ֵ  







u16  T_Get_Adc_Temperature(void);//�õ��ڲ��¶ȴ�����ͨ��10�β�����adcֵ������¶�


#endif 
