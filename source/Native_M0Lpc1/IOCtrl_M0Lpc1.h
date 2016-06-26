/***************************************************************************

             IOCtrl��M0 LPCʵ���1�е�ʵ��

***************************************************************************/
#ifndef __IOCTRL_M0_LPC1_H
#define __IOCTRL_M0_LPC1_H

#include "LPC12xx.h"
#include "LPC12xxbit.h"

//-------------------------��LIGHTָʾ�ƿڵ����в���--------------------------
//��ӦӲ����LED1
#define TRIS_LIGHT		TRISA
#define PORT_LIGHT		LATA
#define PIN_LIGHT		PORTA
#define BIT_LIGHT		0x20
//����
#define OutLIGHT()		do{LPC_GPIO2->DIR |= (1 << 0);}while(0)
//���ʱ,�ߵ͵�ƽ
#define SetLIGHT()		do{LPC_GPIO2->SET = (1 << 0);}while(0)
#define ClrLIGHT()		do{LPC_GPIO2->CLR = (1 << 0);}while(0)
//#define IsSetLIGHT()		()
//��ʼ��������Ϊָʾ�Ʋ���
#define CfgLIGHT() do{LPC_IOCON->PIO2_0 = 0x90; SetLIGHT(); OutLIGHT();}while(0)

//-------------------------��TEST���ܿڵĲ���--------------------------
//��ӦӲ����
//����
#define InTEST()		 do{LPC_GPIO2->DIR &= ~(1 << 1);}while(0)
//����ʱ,�Ƿ�Ϊ�ߵ�ƽ
#define IsTEST()		   (LPC_GPIO2->PIN & (1 << 1))
//����ʱ,�Ͻӵ���(ֻ��PORTB�����ֿ���)
#define SetPullUpTEST()		do{}while(0)
//��ʼ��������Ϊ��������״̬
#define CfgTEST() do{LPC_IOCON->PIO2_0 = 0x100; SetPullUpTEST(); InTEST();}while(0)

//-------------------------IO�ڵ�ͳһ���ò���--------------------------
//�˺����ڿ�����ʼ��ʱͳһ����,�������ò����õ���IO��Ϊ��Ҫ��״̬��
//IOCtrl_Init()ΪIOCtrl�Ĺ��캯��,�����κ���ʱ,��ʵ��Ϊ��.
#define IOCtrl_Init()  do{\
  LPC_SYSCON->SYSAHBCLKCTRL |= (GPIO0_ACC | GPIO1_ACC | GPIO2_ACC);\
}while(0)


#endif //#define __IOCTRL_M0_LPC1_H


