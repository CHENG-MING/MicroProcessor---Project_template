#include"led.h"
#include"stm32f10x.h"


//LED使用格式：

//调用头文件 #include"led.h"
//需初始化函数
//通过 通过LED0，LED1或PAout(8),PDout(2)来控制led亮灭



void LED_Init(void)

{ GPIO_InitTypeDef GPIO_InitStructure;     	//定义GPIO初始化结构体
	
	
	
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);  //使能端口时钟
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;               //配置GPIO端口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;        //配置输入、输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; 	//配置IO口速度
	
	GPIO_Init(GPIOD,&GPIO_InitStructure);                 //根据设定参数初始化GPIO
  GPIO_SetBits(GPIOD,GPIO_Pin_2);                       //配置GPIO默认输出高电平
	
	
	
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);  
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;               
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;        
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);                 
  GPIO_SetBits(GPIOA,GPIO_Pin_8);     
	
	



}
