#include "iwdg.h"
#include "led.h"

//�������Ź�_ʹ�ø�ʽ��

//�����ͷ�ļ� #include "iwdg.h"	

//IWDG_Init(u8 prer,u16 rlr)  �������Ź���ʼ��������Ԥ��Ƶ��prep,��װ��ֵrlr
// Tout(���ʱ��) = ((4*2^prer)*rlr)/40  ��λms
//��  IWDG_Init(4,625); ���ʱ��Ϊ1s

//IWDG_Feed();  ���������ڲ�ι��������û�������ʱ���ڼ�ʱι���������λ��




void IWDG_Init(u8 prer,u16 rlr) 
{	
 	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);  //ʹ�ܶԼĴ���IWDG_PR��IWDG_RLR��д����
	
	IWDG_SetPrescaler(prer);  //����IWDGԤ��Ƶֵ:����IWDGԤ��ƵֵΪ64
	
	IWDG_SetReload(rlr);  //����IWDG��װ��ֵ
	
	IWDG_ReloadCounter();  //����IWDG��װ�ؼĴ�����ֵ��װ��IWDG������
	
	IWDG_Enable();  //ʹ��IWDG
}
//ι�������Ź�
void IWDG_Feed(void)
{   
 	IWDG_ReloadCounter();										   
}


 

