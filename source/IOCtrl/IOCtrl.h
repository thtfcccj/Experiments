/***************************************************************************

             嵌入式系统通用驱动程序接口及其实现-IO通用接口

1. 此接口为具体项目: 所有输入输出引脚(IO)的操作,提供统一接口。实现了调用层
   与硬件输入输出中的分离。
***************************************************************************/
#ifndef __IOCTRL_H
#define __IOCTRL_H

//下列代码与具体应用有关，接需修改:

#ifdef SUPPORT_PIC1_V100
  #include "IOCtrl_Pic1_V100.h" //PIC示例板1 V100版
#endif 

#ifdef SUPPORT_AVR1_V010
  #include "IOCtrl_Avr1_V010.h" //AVR 实验板
#endif 

#ifdef SUPPORT_M0_LPC_V010
  #include "IOCtrl_M0Lpc1.h" //M0Lpc实验板1
#endif 

#endif //#define __IOCTRL_H
