/***************************************************************************

             IOCtrl在PIC示例板1 V010版中的实现

***************************************************************************/
#ifndef __IOCTRL_AVR1_V010_H
#define __IOCTRL_AVR1_V010_H

#include <ioavr.h>

//-------------------------对LIGHT指示灯口的所有操作--------------------------
//对应硬件的lIGHT_G
#define DDR_LIGHT		  DDRD
#define PORT_LIGHT		PORTD
#define PIN_LIGHT			PIND
#define BIT_LIGHT			0x10

//方向
#define OutLIGHT()		do{DDR_LIGHT |= BIT_LIGHT;}while(0)
//输出时,高低电平
#define SetLIGHT()		do{PORT_LIGHT |= BIT_LIGHT;}while(0)
#define ClrLIGHT()		do{PORT_LIGHT &= ~BIT_LIGHT;}while(0)
#define IsSetLIGHT()		(PORT_LIGHT & BIT_LIGHT)

//初始化及配置为指示灯不亮
#define CfgLIGHT() do{SetLIGHT(); OutLIGHT();}while(0)
//-------------------------对TEST功能口的操作--------------------------
//对应硬件的KEY1
#define DDR_TEST		DDRC
#define PORT_TEST		PORTC
#define PIN_TEST		PINC
#define BIT_TEST		0x80

//方向
#define InTEST()			do{DDR_TEST &= ~BIT_TEST;}while(0)
//输入时,是否为高电平
#define IsTEST()		   (PIN_TEST & BIT_TEST)
//输入时,上接电阻(在输入状态,AVR的PORT端复用作上拉电阻功能)
#define SetPullUpTEST()		do{PORT_TEST |= BIT_TEST;}while(0)

//初始化及配置为输入上拉状态
#define CfgTEST() do{SetPullUpTEST();InTEST();}while(0)

//-------------------------IO口的统一配置操作--------------------------
//此函数在开机初始化时统一调用,可用于置不会用到的IO口为需要的状态等
//IOCtrl_Init()为IOCtrl的构造函数,不做任何事时,请实现为空.
#define IOCtrl_Init()  do{\
}while(0)


#endif //#define __IOCTRL_AVR1_V010_H



