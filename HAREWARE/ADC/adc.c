 #include "adc.h"
 #include "delay.h"
 
//adcʹ�ø�ʽ��

//  ����ͷ�ļ�  #include "adc.h"
//  ��ʼ�� Adc_Init();
//  ����Get_Adc_Average(ADC_Channel_1,10); ���ȡtimes��ADC_Channel_1ͨ����ADCƽ��ֵ  �����ʼ������



//ң�ص���վʵ��Ӧ�ã�
//  Get_Adc_Average(ADC_Channel_10,10); ��ӦPC0
//  Get_Adc_Average(ADC_Channel_11,10); ��ӦPC1
//  Get_Adc_Average(ADC_Channel_12,10); ��ӦPC2
//  Get_Adc_Average(ADC_Channel_13,10); ��ӦPC3
//






void  Adc_Init(void)  //��ʼ��ADC      
{ 	
	ADC_InitTypeDef ADC_InitStructure;  //����ADC��ʼ���ṹ��
	GPIO_InitTypeDef GPIO_InitStructure;//����GPIO��ʼ���ṹ��

	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC |RCC_APB2Periph_ADC1	, ENABLE );	  //ʹ��GPIO C��ADC1ͨ��ʱ��
 
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //����ADC��Ƶ����6 72M/6=12,ADC���ʱ�䲻�ܳ���14M
	                       
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//PC0��Ϊģ��ͨ����������  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//����GPIOģʽΪģ������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//����GPIO���ٶ�
	GPIO_Init(GPIOC, &GPIO_InitStructure);	//��ʼ��GPIO

	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//PC1 ��Ϊģ��ͨ����������  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//����GPIOģʽΪģ������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//����GPIO���ٶ�
	GPIO_Init(GPIOC, &GPIO_InitStructure);	//��ʼ��GPIO
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//PC2��Ϊģ��ͨ����������  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//����GPIOģʽΪģ������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//����GPIO���ٶ�
	GPIO_Init(GPIOC, &GPIO_InitStructure);	//��ʼ��GPIO
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//PC3 ��Ϊģ��ͨ����������  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//����GPIOģʽΪģ������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//����GPIO���ٶ�
	GPIO_Init(GPIOC, &GPIO_InitStructure);	//��ʼ��GPIO
	
	
	
	ADC_DeInit(ADC1);  //��λADC1,������ ADC1 ��ȫ���Ĵ�������Ϊȱʡֵ

	
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC����ģʽ:ADC1��ADC2�����ڶ���ģʽ
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;	//ģ��ת��������ɨ��ͨ��ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//ģ��ת�������ڵ���ת��ģʽ
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//ת��������������ⲿ��������
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC�����Ҷ���
	ADC_InitStructure.ADC_NbrOfChannel = 4;	//˳����й���ת����ADCͨ������ĿΪ4
	ADC_Init(ADC1, &ADC_InitStructure);	//����ADC_InitStruct��ָ���Ĳ�����ʼ������ADCx�ļĴ���   

  
	ADC_Cmd(ADC1, ENABLE);	//ʹ��ָ����ADC1
	
	ADC_ResetCalibration(ADC1);	//ʹ�ܸ�λУ׼  
	 
	while(ADC_GetResetCalibrationStatus(ADC1));	//�ȴ���λУ׼����
	
	ADC_StartCalibration(ADC1);	 //����ADУ׼
 
	while(ADC_GetCalibrationStatus(ADC1));	 //�ȴ�У׼����
 


}				  

u16 Get_Adc(u8 ch)   //���ù���ͨ���������������ת�����ȴ�ת����ɣ���ȡADCֵ��
{  
  //����ָ��ADC�Ĺ�����ͨ����һ�����У�����ʱ��
	ADC_RegularChannelConfig(ADC1, ch, 4, ADC_SampleTime_71Cycles5 );	//ADC1,ADCͨ����Ŀ4,����ʱ��Ϊ239.5����	  			    
  
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//ʹ��ָ����ADC1�����ת����������	
	 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//�ȴ�ת������

	return ADC_GetConversionValue(ADC1);	//�������һ��ADC1�������ת���������ȡADCֵ
}

u16 Get_Adc_Average(u8 ch,u8 times) //���ȡtimes��ADC��ƽ��ֵ  ʾ����Get_Adc_Average(ADC_Channel_1,10);
{ 
	u32 temp_val=0;
	u8 t;
	

	
	for(t=0;t<times;t++)
	{
		temp_val+=Get_Adc(ch);
		delay_ms(5);
	}

	return temp_val/times; 
} 	 




