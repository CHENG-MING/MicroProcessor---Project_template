#include"led.h"
#include"stm32f10x.h"


//LEDʹ�ø�ʽ��

//����ͷ�ļ� #include"led.h"
//���ʼ������
//ͨ�� ͨ��LED0��LED1��PAout(8),PDout(2)������led����



void LED_Init(void)

{ GPIO_InitTypeDef GPIO_InitStructure;     	//����GPIO��ʼ���ṹ��
	
	
	
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);  //ʹ�ܶ˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;               //����GPIO�˿�
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;        //�������롢���ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; 	//����IO���ٶ�
	
	GPIO_Init(GPIOD,&GPIO_InitStructure);                 //�����趨������ʼ��GPIO
  GPIO_SetBits(GPIOD,GPIO_Pin_2);                       //����GPIOĬ������ߵ�ƽ
	
	
	
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);  
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;               
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;        
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);                 
  GPIO_SetBits(GPIOA,GPIO_Pin_8);     
	
	



}
