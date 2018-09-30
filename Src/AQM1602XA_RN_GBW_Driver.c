/*
 * LCDDisplayDriver.c
 *
 *  Created on: 2018/02/10
 *      Author: Shuji
 */
#include "AQM1602XA_RN_GBW_Driver.h"

#define DEVICE_ADDRESS 0x7C
#define COMMAND_ADDRESS 0x00
#define TIME_OUT 100

#define DATA_ADDRESS 0x40

void Initialize()
{
	I2C_STATE_t writeResult = I2CRegisterWrite(DEVICE_ADDRESS, COMMAND_ADDRESS, 0x38);

	if(writeResult == I2C_NO_ERROR){
		writeResult = I2CRegisterWrite(DEVICE_ADDRESS, COMMAND_ADDRESS, 0x39);
	}

	if(writeResult == I2C_NO_ERROR){
		writeResult = I2CRegisterWrite(DEVICE_ADDRESS, COMMAND_ADDRESS, 0x14);
	}

	if(writeResult == I2C_NO_ERROR){
		writeResult = I2CRegisterWrite(DEVICE_ADDRESS, COMMAND_ADDRESS, 0x7A);
	}

	if(writeResult == I2C_NO_ERROR){
		writeResult = I2CRegisterWrite(DEVICE_ADDRESS, COMMAND_ADDRESS, 0x54);
	}

	if(writeResult == I2C_NO_ERROR){
		writeResult = I2CRegisterWrite(DEVICE_ADDRESS, COMMAND_ADDRESS, 0x6C);
		Wait_ms(200);
	}

	if(writeResult == I2C_NO_ERROR){
		writeResult = I2CRegisterWrite(DEVICE_ADDRESS, COMMAND_ADDRESS, 0x38);
	}

	if(writeResult == I2C_NO_ERROR){
		writeResult = I2CRegisterWrite(DEVICE_ADDRESS, COMMAND_ADDRESS, 0x0C);
	}

	if(writeResult == I2C_NO_ERROR){
		writeResult = I2CRegisterWrite(DEVICE_ADDRESS, COMMAND_ADDRESS, 0x01);
	}
	Wait_ms(2);

	if(writeResult != I2C_NO_ERROR){
		Initialize_I2C();
	}
}
void SetChar(uint8_t* str, uint8_t length, uint8_t line)
{
	I2C_STATE_t writeResult = I2C_NO_ERROR;

	if(line == 1){
		writeResult = I2CRegisterWrite(DEVICE_ADDRESS, COMMAND_ADDRESS, 0x80);
	}
	else if(line == 2){
		writeResult = I2CRegisterWrite(DEVICE_ADDRESS, COMMAND_ADDRESS, 0x40 | 0x80);
	}

	if(writeResult == I2C_NO_ERROR){
		I2CRegisterWrites(DEVICE_ADDRESS, DATA_ADDRESS, str, length);
	}
	else{
		Initialize_I2C();
		Initialize();
	}

}
void ClearChar()
{

	HAL_StatusTypeDef writeResult = I2CRegisterWrite(DEVICE_ADDRESS, COMMAND_ADDRESS, 0x01);
	Wait_ms(2);

	if(writeResult != I2C_NO_ERROR){
		Initialize_I2C();
		Initialize();
	}
}
__attribute__((weak)) I2C_STATE_t I2CRegisterWrite(uint8_t slaveAddress, uint8_t registerAddress, uint8_t data)
{
	return I2C_ERROR;
}
__attribute__((weak)) void Wait_ms(int msec)
{
	return;
}
__attribute__((weak)) void Initialize_I2C(int msec)
{
	return;
}
