/***************************************************************************

             IOCtrl��PICʾ����1 V010���е�ʵ��

***************************************************************************/
#ifndef __IOCTRL_AVR1_V010_H
#define __IOCTRL_AVR1_V010_H

#include <ioavr.h>

//-------------------------��LIGHTָʾ�ƿڵ����в���--------------------------
//��ӦӲ����lIGHT_G
#define DDR_LIGHT		  DDRD
#define PORT_LIGHT		PORTD
#define PIN_LIGHT			PIND
#define BIT_LIGHT			0x10

//����
#define OutLIGHT()		do{DDR_LIGHT |= BIT_LIGHT;}while(0)
//���ʱ,�ߵ͵�ƽ
#define SetLIGHT()		do{PORT_LIGHT |= BIT_LIGHT;}while(0)
#define ClrLIGHT()		do{PORT_LIGHT &= ~BIT_LIGHT;}while(0)
#define IsSetLIGHT()		(PORT_LIGHT & BIT_LIGHT)

//��ʼ��������Ϊָʾ�Ʋ���
#define CfgLIGHT() do{SetLIGHT(); OutLIGHT();}while(0)
//-------------------------��TEST���ܿڵĲ���--------------------------
//��ӦӲ����KEY1
#define DDR_TEST		DDRC
#define PORT_TEST		PORTC
#define PIN_TEST		PINC
#define BIT_TEST		0x80

//����
#define InTEST()			do{DDR_TEST &= ~BIT_TEST;}while(0)
//����ʱ,�Ƿ�Ϊ�ߵ�ƽ
#define IsTEST()		   (PIN_TEST & BIT_TEST)
//����ʱ,�Ͻӵ���(������״̬,AVR��PORT�˸������������蹦��)
#define SetPullUpTEST()		do{PORT_TEST |= BIT_TEST;}while(0)

//��ʼ��������Ϊ��������״̬
#define CfgTEST() do{SetPullUpTEST();InTEST();}while(0)

//-------------------------IO�ڵ�ͳһ���ò���--------------------------
//�˺����ڿ�����ʼ��ʱͳһ����,�������ò����õ���IO��Ϊ��Ҫ��״̬��
//IOCtrl_Init()ΪIOCtrl�Ĺ��캯��,�����κ���ʱ,��ʵ��Ϊ��.
#define IOCtrl_Init()  do{\
}while(0)


#endif //#define __IOCTRL_AVR1_V010_H



