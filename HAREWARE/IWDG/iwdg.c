#include "iwdg.h"
#include "led.h"

//独立看门狗_使用格式：

//需调用头文件 #include "iwdg.h"	

//IWDG_Init(u8 prer,u16 rlr)  独立看门狗初始化，设置预分频数prep,重装载值rlr
// Tout(溢出时间) = ((4*2^prer)*rlr)/40  单位ms
//例  IWDG_Init(4,625); 溢出时间为1s

//IWDG_Feed();  在主程序内部喂狗，若在没有在溢出时间内及时喂狗，则程序复位。




void IWDG_Init(u8 prer,u16 rlr) 
{	
 	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);  //使能对寄存器IWDG_PR和IWDG_RLR的写操作
	
	IWDG_SetPrescaler(prer);  //设置IWDG预分频值:设置IWDG预分频值为64
	
	IWDG_SetReload(rlr);  //设置IWDG重装载值
	
	IWDG_ReloadCounter();  //按照IWDG重装载寄存器的值重装载IWDG计数器
	
	IWDG_Enable();  //使能IWDG
}
//喂独立看门狗
void IWDG_Feed(void)
{   
 	IWDG_ReloadCounter();										   
}


 

