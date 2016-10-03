//***************************************************************************
//----------------本例程仅供学习使用，未经作者允许，不得用于其他用途。-----------
//------------------------版权所有，仿冒必究！---------------------------------
//----------------1.开发环境:Arduino IDE or Visual Studio 2010----------------
//----------------2.使用开发板型号：Arduino UNO R3            ----------------
//----------------3.单片机使用晶振：16M		                 ----------------
//----------------4.淘宝网址：Ilovemcu.taobao.com		     ----------------
//----------------			52dpj.taobao.com                 ----------------
//—————————         epic-mcu.taobao.com              ----------------
//----------------5.作者：神秘藏宝室			                 ----------------
//***************************************************************************/
#ifndef __DS18B20_H__
#define __DS18B20_H__


#include <Arduino.h>

//DS18B20 IO设置
#define  DS18B20_DQ 2

#define DS18B20_DQ_0 digitalWrite(DS18B20_DQ,LOW)
#define DS18B20_DQ_1 digitalWrite(DS18B20_DQ,HIGH)


//函数或者变量声明
extern void DS18B20_Write_Byte( unsigned char dat);
extern unsigned char DS18B20_Read_Byte( );
extern bool DS18B20_Init();
extern unsigned int Get_temp(void);

extern unsigned char flag_temper;

#endif
