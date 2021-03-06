/*==============================================================================================*/
/*==============================================================================================*/
#include "STM32_SYSTEM.h"
#include "STM32_I2C.h"
#include "Module_LSM303.h"
/*==============================================================================================*/
/*==============================================================================================*
**函數 : LSM303A_Init
**功能 : 初始化LSM303 加速度
**輸入 : 無
**輸出 : 無
**使用 : LSM303A_Init()
**==============================================================================================*/
/*==============================================================================================*/
void LSM303A_Init( void )
{
	u8 LSM303A_Init_Data[2] = {
			0x37,	/* LSM303A_CTRL_REG1	NormalMode, ODR:400Hz, XYZEnable */
			0x10	/* LSM303A_CTRL_REG4	Range:+-4g                       */
		};

	I2C_DMA_WriteReg(LSM303A_Init_Data,   LSM303A_I2C_ADDR, LSM303A_CTRL_REG1, 1);Delay_1ms(1);
	I2C_DMA_WriteReg(LSM303A_Init_Data+1, LSM303A_I2C_ADDR, LSM303A_CTRL_REG4, 1);Delay_1ms(1);
}
/*==============================================================================================*/
/*==============================================================================================*
**函數 : LSM303M_Init
**功能 : 初始化LSM303 電子羅盤
**輸入 : 無
**輸出 : 無
**使用 : LSM303M_Init()
**==============================================================================================*/
/*==============================================================================================*/
void LSM303M_Init( void )
{
	u8 LSM303M_Init_Data[2] = {
			0x20,	/* LSM303M_CRB_REG	Range:+-1.3Gauss           */
			0x00	/* LSM303M_MR_REG		Continuous-conversion mode */
		};
	I2C_DMA_WriteReg(LSM303M_Init_Data,   LSM303M_I2C_ADDR, LSM303M_CRB_REG, 1);Delay_1ms(1);
	I2C_DMA_WriteReg(LSM303M_Init_Data+1, LSM303M_I2C_ADDR, LSM303M_MR_REG,  1);Delay_1ms(1);
}
/*==============================================================================================*/
/*==============================================================================================*
**函數 : LSM30A_Read_Multiple
**功能 : 
**輸入 : 無
**輸出 : 無
**使用 : LSM303A_Read_Multiple()
**==============================================================================================*/
/*==============================================================================================*/
void LSM303A_Read_Multiple( u8* ReadMultiple )
{
	I2C_DMA_ReadReg(ReadMultiple, LSM303A_I2C_ADDR, LSM303A_MULTIPLE, 6);
}
/*==============================================================================================*/
/*==============================================================================================*
**函數 : LSM303M_Read_Multiple
**功能 : 
**輸入 : 無
**輸出 : 無
**使用 : LSM303M_Read_Multiple()
**==============================================================================================*/
/*==============================================================================================*/
void LSM303M_Read_Multiple( u8* ReadMultiple  )
{
	I2C_DMA_ReadReg(ReadMultiple, LSM303M_I2C_ADDR, LSM303M_OUT_X_H, 6);
}
/*==============================================================================================*/
/*==============================================================================================*/
