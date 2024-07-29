/*
 * I2Cbase.h
 *
 *  Created on: Jun 20, 2024
 *      Author: acer1
 */

#ifndef I2CBASE_H_
#define I2CBASE_H_

#include "stm32f4xx_hal.h"

#define I2C_COUNT 2
#define I2C_BUFFER_RX_SIZE 64

class I2Cbase {
public:
	I2Cbase();
	I2Cbase(I2C_TypeDef *Instance, I2C_HandleTypeDef *hi2c);
	virtual ~I2Cbase();

	void init(void);

	HAL_StatusTypeDef write(uint8_t addr, uint8_t* txData, uint16_t txSize, uint32_t Timeout);

	HAL_StatusTypeDef read(uint8_t addr, uint8_t* rxData, uint16_t rxSize, uint32_t Timeout);

	HAL_StatusTypeDef transfer(uint8_t addr, uint8_t* txData, uint16_t txSize, uint8_t* rxData, uint16_t rxSize,  uint32_t Timeout);

	void enable_interrupt(void);

	void disable_interrupt(void);


	void I2CStart(void);
	void I2CStop(void);



protected:
	I2C_HandleTypeDef *_hi2c;
private:
	I2C_TypeDef *_Instance;
	bool _it_enabled;

};

#endif /* I2CBASE_H_ */
