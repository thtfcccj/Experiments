/***************************************************************************

             Ƕ��ʽϵͳͨ����������ӿڼ���ʵ��-IOͨ�ýӿ�

1. �˽ӿ�Ϊ������Ŀ: ���������������(IO)�Ĳ���,�ṩͳһ�ӿڡ�ʵ���˵��ò�
   ��Ӳ����������еķ��롣
***************************************************************************/
#ifndef __IOCTRL_H
#define __IOCTRL_H

//���д��������Ӧ���йأ������޸�:

#ifdef SUPPORT_PIC1_V100
  #include "IOCtrl_Pic1_V100.h" //PICʾ����1 V100��
#endif 

#ifdef SUPPORT_AVR1_V010
  #include "IOCtrl_Avr1_V010.h" //AVR ʵ���
#endif 

#ifdef SUPPORT_M0_LPC_V010
  #include "IOCtrl_M0Lpc1.h" //M0Lpcʵ���1
#endif 

#endif //#define __IOCTRL_H
