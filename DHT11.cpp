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
#include "DHT11.h"

//定义变量
unsigned char HUMI_Buffer_Int = 0;
unsigned char TEM_Buffer_Int = 0;
 
//****************************************************
//初始化DHT11
//****************************************************
void DHT11_Init()
{
	pinMode(DHT11_DQ,OUTPUT);

	DHT11_DQ_0;  //拉低总线，发开始信号；
	delay(30);  //延时要大于 18ms，以便 DHT11 能检测到开始信号；
	DHT11_DQ_1;
	delayMicroseconds(40);  //等待 DHT11 响应；
	pinMode(DHT11_DQ,INPUT);
	while(digitalRead(DHT11_DQ) == HIGH);
	delayMicroseconds(80);   //DHT11 发出响应，拉低总线 80us；
	if(digitalRead(DHT11_DQ) == LOW);
	delayMicroseconds(80);   //DHT11 拉高总线 80us 后开始发送数据；
}

//****************************************************
//读一个字节DHT11数据
//****************************************************
unsigned char DHT11_Read_Byte()
{
	unsigned char i,dat = 0;
	unsigned int j;

	pinMode(DHT11_DQ,INPUT);

	for( i=0; i<8; i++)
	{
		if(digitalRead(DHT11_DQ) == LOW)
		{
			while(digitalRead(DHT11_DQ) == LOW);   //等待 50us；
			delayMicroseconds(30);   //判断高电平的持续时间，以判定数据是‘0’还是‘1’；
			if(digitalRead(DHT11_DQ) == HIGH)
				dat |= (1<<(7-i));   //高位在前，低位在后；
			while(digitalRead(DHT11_DQ) == HIGH);   //数据‘1’，等待下一位的接收；
		}
	}
	return dat;
}

//****************************************************
//读取温湿度值，存放在TEM_Buffer和HUMI_Buffer
//****************************************************
void DHT11_Read()
{
	DHT11_Init();

	HUMI_Buffer_Int = DHT11_Read_Byte();   		//读取湿度的整数值
	DHT11_Read_Byte();							//读取湿度的小数值
	TEM_Buffer_Int = DHT11_Read_Byte();			//读取温度的整数值
	DHT11_Read_Byte();							//读取温度的小数值
	DHT11_Read_Byte();							//读取校验和
	delayMicroseconds(50);						//DHT11拉低总线50us

	pinMode(DHT11_DQ,OUTPUT);
	DHT11_DQ_1;					//释放总线	


}



