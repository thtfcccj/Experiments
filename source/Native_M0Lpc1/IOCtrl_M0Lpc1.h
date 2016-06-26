/***************************************************************************

             IOCtrl在M0 LPC实验板1中的实现

***************************************************************************/
#ifndef __IOCTRL_M0_LPC1_H
#define __IOCTRL_M0_LPC1_H

#include "LPC12xx.h"
#include "LPC12xxbit.h"

//-------------------------对LIGHT指示灯口的所有操作--------------------------
//假定IO口为GPIO2_0
//方向
#define OutLIGHT()		do{LPC_GPIO2->DIR |= (1 << 0);}while(0)
//输出时,高低电平
#define SetLIGHT()		do{LPC_GPIO2->SET = (1 << 0);}while(0)
#define ClrLIGHT()		do{LPC_GPIO2->CLR = (1 << 0);}while(0)
#define IsSetLIGHT()		(LPC_GPIO2->OUT & (1 << 0))
//初始化及配置为指示灯不亮
#define CfgLIGHT() do{LPC_IOCON->PIO2_0 = 0x90; SetLIGHT(); OutLIGHT();}while(0)

//-------------------------对TEST功能口的操作--------------------------
//假定IO口为GPIO2_1
//方向
#define InTEST()		 do{LPC_GPIO2->DIR &= ~(1 << 1);}while(0)
//输入时,是否为高电平
#define IsTEST()		   (LPC_GPIO2->PIN & (1 << 1))
//输入时,上接电阻(只有PORTB及部分口有)
#define SetPullUpTEST()		do{}while(0)
//初始化及配置为输入上拉状态
#define CfgTEST() do{LPC_IOCON->PIO2_1 = 0x90; SetPullUpTEST(); InTEST();}while(0)

//-------------------------IO口的统一配置操作--------------------------
//此函数在开机初始化时统一调用,可用于置不会用到的IO口为需要的状态等
//IOCtrl_Init()为IOCtrl的构造函数,不做任何事时,请实现为空.
#define IOCtrl_Init()  do{\
  LPC_SYSCON->SYSAHBCLKCTRL |= (GPIO0_ACC | GPIO1_ACC | GPIO2_ACC);\
}while(0)


#endif //#define __IOCTRL_M0_LPC1_H



