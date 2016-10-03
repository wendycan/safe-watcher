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
#ifndef __DHT11_H__
#define __DHT11_H__


#include <Arduino.h>

//DHT11 IO设置
#define DHT11_DQ 6

#define DHT11_DQ_0 digitalWrite(DHT11_DQ,LOW)
#define DHT11_DQ_1 digitalWrite(DHT11_DQ,HIGH)

//函数或者变量声明
extern void DHT11_Init();
extern unsigned char DHT11_Read_Byte();
extern void DHT11_Read();

extern unsigned char HUMI_Buffer_Int;
extern unsigned char TEM_Buffer_Int;

#endif
