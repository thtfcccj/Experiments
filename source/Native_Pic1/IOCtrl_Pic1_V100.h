/***************************************************************************

             IOCtrl在PIC示例板1 V100版中的实现

***************************************************************************/
#ifndef __IOCTRL_PIC1_V100_H
#define __IOCTRL_PIC1_V100_H

#include <pic.h>
#include "PicBit.h"

//-------------------------对LIGHT指示灯口的所有操作--------------------------
//对应硬件的LED1
#define TRIS_LIGHT		TRISA
#define PORT_LIGHT		LATA
#define PIN_LIGHT		PORTA
#define BIT_LIGHT		0x20
//方向
#define OutLIGHT()		do{TRIS_TEST &= ~BIT_TEST;}while(0)
//输出时,高低电平
#define SetLIGHT()		do{PORT_LIGHT |= BIT_LIGHT;}while(0)
#define ClrLIGHT()		do{PORT_LIGHT &= ~BIT_LIGHT;}while(0)
#define IsSetLIGHT()		(PORT_LIGHT & BIT_LIGHT)
//初始化及配置为指示灯不亮
#define CfgLIGHT() do{ANSELA &= ~BIT_LIGHT; SetLIGHT(); OutLIGHT();}while(0)

//-------------------------对TEST功能口的操作--------------------------
//对应硬件的RC0
#define TRIS_TEST		  TRISC
#define PORT_TEST		  LATC
#define PIN_TEST		  PORTC
#define BIT_TEST		  0x01
//方向
#define InTEST()		 do{TRIS_TEST |= BIT_TEST;}while(0)
//输入时,是否为高电平
#define IsTEST()		   (PIN_TEST & BIT_TEST)
//输入时,上接电阻(只有PORTB及部分口有)
#define SetPullUpTEST()		do{WPUB |= BIT_TEST;}while(0)
//初始化及配置为输入上拉状态
#define CfgTEST() do{SetPullUpTEST();InTEST();}while(0)

//-------------------------IO口的统一配置操作--------------------------
//此函数在开机初始化时统一调用,可用于置不会用到的IO口为需要的状态等
//IOCtrl_Init()为IOCtrl的构造函数,不做任何事时,请实现为空.
#define IOCtrl_Init()  do{\
  OPTION_REG &= ~PICB_nWPUEN;\
}while(0)


#endif //#define __IOCTRL_PIC1_V100_H



