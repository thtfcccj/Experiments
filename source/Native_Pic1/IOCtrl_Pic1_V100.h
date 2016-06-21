/***************************************************************************

             IOCtrl��PICʾ����1 V100���е�ʵ��

***************************************************************************/
#ifndef __IOCTRL_PIC1_V100_H
#define __IOCTRL_PIC1_V100_H

#include <pic.h>
#include "PicBit.h"

//-------------------------��LIGHTָʾ�ƿڵ����в���--------------------------
//��ӦӲ����LED1
#define TRIS_LIGHT		TRISA
#define PORT_LIGHT		LATA
#define PIN_LIGHT		PORTA
#define BIT_LIGHT		0x20
//����
#define OutLIGHT()		do{TRIS_TEST &= ~BIT_TEST;}while(0)
//���ʱ,�ߵ͵�ƽ
#define SetLIGHT()		do{PORT_LIGHT |= BIT_LIGHT;}while(0)
#define ClrLIGHT()		do{PORT_LIGHT &= ~BIT_LIGHT;}while(0)
#define IsSetLIGHT()		(PORT_LIGHT & BIT_LIGHT)
//��ʼ��������Ϊָʾ�Ʋ���
#define CfgLIGHT() do{ANSELA &= ~BIT_LIGHT; SetLIGHT(); OutLIGHT();}while(0)

//-------------------------��TEST���ܿڵĲ���--------------------------
//��ӦӲ����RC0
#define TRIS_TEST		  TRISC
#define PORT_TEST		  LATC
#define PIN_TEST		  PORTC
#define BIT_TEST		  0x01
//����
#define InTEST()		 do{TRIS_TEST |= BIT_TEST;}while(0)
//����ʱ,�Ƿ�Ϊ�ߵ�ƽ
#define IsTEST()		   (PIN_TEST & BIT_TEST)
//����ʱ,�Ͻӵ���(ֻ��PORTB�����ֿ���)
#define SetPullUpTEST()		do{WPUB |= BIT_TEST;}while(0)
//��ʼ��������Ϊ��������״̬
#define CfgTEST() do{SetPullUpTEST();InTEST();}while(0)

//-------------------------IO�ڵ�ͳһ���ò���--------------------------
//�˺����ڿ�����ʼ��ʱͳһ����,�������ò����õ���IO��Ϊ��Ҫ��״̬��
//IOCtrl_Init()ΪIOCtrl�Ĺ��캯��,�����κ���ʱ,��ʵ��Ϊ��.
#define IOCtrl_Init()  do{\
  OPTION_REG &= ~PICB_nWPUEN;\
}while(0)


#endif //#define __IOCTRL_PIC1_V100_H



