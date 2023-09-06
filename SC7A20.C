/*
 * @Author: Chen 2603148225@qq.com
 * @Date: 2023-03-31 16:23:59
 * @LastEditors: Chen 2603148225@qq.com
 * @LastEditTime: 2023-09-06 21:35:15
 * @FilePath: \Project\SC7A20.C
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "STC8G1K08.H"
#include "SC7A20Reg.H"
#include "I2C.H"
#include "Uart.h"

#define SC7A20_ADDRESS		0X30



/**
 * @brief I2C通信写入寄存器
 * @param Address 寄存器地址
 * @param Data 写入的数据
 */
void SC7A20_WriteReg(unsigned char Address, unsigned char Data)
{
	I2C_Start();
	I2C_SendByte(SC7A20_ADDRESS);
	I2C_ReceiveACK();
	I2C_SendByte(Address);
	I2C_ReceiveACK();
	I2C_SendByte(Data);
	I2C_ReceiveACK();
	I2C_Stop();
}

/**
 * @brief I2C通信读取SC7A20寄存器的值
 * @param Address 寄存器的地址
 * @return 寄存器里面的数据
 */
unsigned char SC7A20_ReadReg(unsigned char Address)
{
	unsigned char Data;

	I2C_Start();
	I2C_SendByte(SC7A20_ADDRESS);
	I2C_ReceiveACK();
	I2C_SendByte(Address);
	I2C_ReceiveACK();

	I2C_Start();
	I2C_SendByte(SC7A20_ADDRESS | 0X01);
	I2C_ReceiveACK();
	Data = I2C_ReceiveByte();
	I2C_SendACK(1);
	I2C_Stop();
	return Data;
}


/**
 * @brief SC7A20初始化配置(这里只使能Z轴, 可根据手册配置RCTRL_REG1的值)
 * @param 无
 */
void SC7A20_Init(void)
{
	I2C_GPIOInit();
	SC7A20_WriteReg(CTRL_REG1, 0X44);
	SC7A20_WriteReg(CTRL_REG2, 0X9C);
	SC7A20_WriteReg(CTRL_REG3, 0X00);
	SC7A20_WriteReg(CTRL_REG4, 0X08);
	SC7A20_WriteReg(CTRL_REG5, 0x00);
}




/**
 * @brief 获取三轴的加速度
 * @param AccX X轴的加速度的地址
 * @param AccY Y轴的加速度的地址
 * @param AccZ Z轴的加速度的地址
 */
void SC7A20_GetAcce(int *AccX, int *AccY, int *AccZ)
{
	unsigned char State;
	unsigned char ACCH = 0, ACCL = 0;

	while((State | 0X7F) == 0XFF)
	{
		State = SC7A20_ReadReg(STATUS_REG);
	}
	ACCL = SC7A20_ReadReg(OUT_X_L);
	ACCH = SC7A20_ReadReg(OUT_X_H);
	*AccX = (ACCH << 8) | ACCL;

	ACCL = SC7A20_ReadReg(OUT_Y_L);
	ACCH = SC7A20_ReadReg(OUT_Y_H);
	*AccY = (ACCH << 8) | ACCL;

	ACCL = SC7A20_ReadReg(OUT_Z_L);
	ACCH = SC7A20_ReadReg(OUT_Z_H);
	*AccZ = (ACCH << 8) | ACCL;
}



/**
 * @brief 只获取Z轴的加速度
 * @param AccZ Z轴的加速度的地址
 */
void SC7A20_GetAccZ(int *AccZ)
{
	unsigned char State = 0;
	unsigned char ACCH = 0, ACCL = 0;
	int Value;

	while((State | 0XBF) == 0XFF)
	{
		State = SC7A20_ReadReg(STATUS_REG);
	}


	ACCL = SC7A20_ReadReg(OUT_Z_L);
	ACCH = SC7A20_ReadReg(OUT_Z_H);

	Value = (ACCH << 8) | ACCL;
	if(Value < 0)
	{
		*AccZ = Value | 0XF000;
	}
	else
	{
		*AccZ = Value & 0X0FFF;
	}
}

