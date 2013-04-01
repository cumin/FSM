/*==============================================================================================*/
/*==============================================================================================*/
#include "stm32f10x_lib.h"
#include "STM32_I2C.h"
#include "Module_ADXL345.h"
#include "delay.h"
/*==============================================================================================*/
/*==============================================================================================*
**ㄧ计 : ADXL345_Init
** : ﹍てADXL345
**块 : 礚
**块 : 礚
**ㄏノ : ADXL345_Init()
**==============================================================================================*/
/*==============================================================================================*/
void ADXL345_Init( void )
{
	u8 ADXL345_Init_Data[7] = {
			0x0B,	/* ADXL345_DATA_FORMAT	测量范围,正负16g，13位模式				*/
			0x0C,	/* ADXL345_BW_RATE		输出数据速率: 400Hz						*/
			0x08,	/* ADXL345_POWER_CTL	选择电源模式 							*/
			0x80,	/* ADXL345_INT_ENABLE	使能 DATA_READY 中断					*/
			0x0,	/* ADXL345_OFSX			X 偏移量 : -4	3.9*17/15.6 = 4.25					*/
			0x0,	/* ADXL345_OFSX			Y 偏移量 : -1  3.9* 4/15.6 = 1						*/
			0x0		/* ADXL345_OFSZ			Z 偏移量 : +9	(1000-3.9*219)/15.6 = 9.35	*/
		};
	I2C_DMA_WriteReg(ADXL345_Init_Data,   ADXL345_I2C_ADDR, ADXL345_DATA_FORMAT, 1); 
	DelayMs(1);
	I2C_DMA_WriteReg(ADXL345_Init_Data+1, ADXL345_I2C_ADDR, ADXL345_BW_RATE,     1); 
	DelayMs(1);
	I2C_DMA_WriteReg(ADXL345_Init_Data+2, ADXL345_I2C_ADDR, ADXL345_POWER_CTL,   1); 
	DelayMs(1);
	I2C_DMA_WriteReg(ADXL345_Init_Data+3, ADXL345_I2C_ADDR, ADXL345_INT_ENABLE,  1); 
	DelayMs(1);
	I2C_DMA_WriteReg(ADXL345_Init_Data+4, ADXL345_I2C_ADDR, ADXL345_OFSX,        1); 
	DelayMs(1);
	I2C_DMA_WriteReg(ADXL345_Init_Data+5, ADXL345_I2C_ADDR, ADXL345_OFSY,        1); 
	DelayMs(1);
	I2C_DMA_WriteReg(ADXL345_Init_Data+6, ADXL345_I2C_ADDR, ADXL345_OFSZ,        1); 
	DelayMs(1);
}
/*==============================================================================================*/
/*==============================================================================================*
**ㄧ计 : ADXL345_Read_Multiple
** : 硈尿弄ADXL345ず场硉计沮0x32~0x37
**块 : 礚
**块 : 礚
**ㄏノ : ADXL345_Read_Multiple()
**==============================================================================================*/
/*==============================================================================================*/
void ADXL345_Read_Multiple( u8* ReadMultiple )
{
	I2C_DMA_ReadReg(ReadMultiple, ADXL345_I2C_ADDR, ADXL345_MULTIPLE, 6);
}
/*==============================================================================================*/
/*==============================================================================================*/
