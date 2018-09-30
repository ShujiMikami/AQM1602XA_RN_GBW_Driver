/*
 * LCDDisplayDriver.h
 *
 *  Created on: 2018/02/10
 *      Author: Shuji
 */

#ifndef LCDDISPLAYDRIVER_INC_LCDDISPLAYDRIVER_H_
#define LCDDISPLAYDRIVER_INC_LCDDISPLAYDRIVER_H_

typedef unsigned char uint8_t;

typedef enum{
	I2C_NO_ERROR,
	I2C_ERROR
}I2C_STATE_t;

void Initialize();
void SetChar(uint8_t* str, uint8_t length, uint8_t line);
void ClearChar();
I2C_STATE_t I2CRegisterWrite(uint8_t slaveAddress, uint8_t registerAddress, uint8_t data);
void Wait_ms(int msec);
void Initialize_I2C();
#endif /* LCDDISPLAYDRIVER_INC_LCDDISPLAYDRIVER_H_ */
