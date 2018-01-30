 #include "adc.h"
 #include "delay.h"
 
//adc使用格式：

//  调用头文件  #include "adc.h"
//  初始化 Adc_Init();
//  例：Get_Adc_Average(ADC_Channel_1,10); 求读取times次ADC_Channel_1通道的ADC平均值  无需初始化函数



//遥控地面站实际应用：
//  Get_Adc_Average(ADC_Channel_10,10); 对应PC0
//  Get_Adc_Average(ADC_Channel_11,10); 对应PC1
//  Get_Adc_Average(ADC_Channel_12,10); 对应PC2
//  Get_Adc_Average(ADC_Channel_13,10); 对应PC3
//






void  Adc_Init(void)  //初始化ADC      
{ 	
	ADC_InitTypeDef ADC_InitStructure;  //定义ADC初始化结构体
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO初始化结构体

	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC |RCC_APB2Periph_ADC1	, ENABLE );	  //使能GPIO C和ADC1通道时钟
 
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //设置ADC分频因子6 72M/6=12,ADC最大时间不能超过14M
	                       
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//PC0作为模拟通道输入引脚  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//设置GPIO模式为模拟输入
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//设置GPIO口速度
	GPIO_Init(GPIOC, &GPIO_InitStructure);	//初始化GPIO

	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//PC1 作为模拟通道输入引脚  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//设置GPIO模式为模拟输入
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//设置GPIO口速度
	GPIO_Init(GPIOC, &GPIO_InitStructure);	//初始化GPIO
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//PC2作为模拟通道输入引脚  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//设置GPIO模式为模拟输入
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//设置GPIO口速度
	GPIO_Init(GPIOC, &GPIO_InitStructure);	//初始化GPIO
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//PC3 作为模拟通道输入引脚  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//设置GPIO模式为模拟输入
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//设置GPIO口速度
	GPIO_Init(GPIOC, &GPIO_InitStructure);	//初始化GPIO
	
	
	
	ADC_DeInit(ADC1);  //复位ADC1,将外设 ADC1 的全部寄存器重设为缺省值

	
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC工作模式:ADC1和ADC2工作在独立模式
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;	//模数转换工作在扫描通道模式
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//模数转换工作在单次转换模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//转换由软件而不是外部触发启动
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 4;	//顺序进行规则转换的ADC通道的数目为4
	ADC_Init(ADC1, &ADC_InitStructure);	//根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器   

  
	ADC_Cmd(ADC1, ENABLE);	//使能指定的ADC1
	
	ADC_ResetCalibration(ADC1);	//使能复位校准  
	 
	while(ADC_GetResetCalibrationStatus(ADC1));	//等待复位校准结束
	
	ADC_StartCalibration(ADC1);	 //开启AD校准
 
	while(ADC_GetCalibrationStatus(ADC1));	 //等待校准结束
 


}				  

u16 Get_Adc(u8 ch)   //配置规则通道参数；开启软件转换；等待转换完成；读取ADC值；
{  
  //设置指定ADC的规则组通道，一个序列，采样时间
	ADC_RegularChannelConfig(ADC1, ch, 4, ADC_SampleTime_71Cycles5 );	//ADC1,ADC通道数目4,采样时间为239.5周期	  			    
  
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能	
	 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束

	return ADC_GetConversionValue(ADC1);	//返回最近一次ADC1规则组的转换结果，获取ADC值
}

u16 Get_Adc_Average(u8 ch,u8 times) //求读取times次ADC的平均值  示例：Get_Adc_Average(ADC_Channel_1,10);
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




