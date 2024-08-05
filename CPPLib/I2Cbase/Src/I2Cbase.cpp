/*
 * I2Cbase.cpp
 *
 *  Author: Adam Czaga czagaadam@gmail.com
 *
 *  I2C base class
 *
 */

#include "I2Cbase.h"

I2Cbase::I2Cbase()
{
	// TODO Auto-generated constructor stub

}


I2Cbase::I2Cbase(I2C_TypeDef *Instance, I2C_HandleTypeDef *hi2c) : _hi2c(hi2c), _Instance(Instance), _it_enabled(false)
{
	// TODO Auto-generated constructor stub

}

I2Cbase::~I2Cbase()
{
	// TODO Auto-generated destructor stub
}

HAL_StatusTypeDef I2Cbase::transfer(uint8_t addr, uint8_t* txData, uint16_t txSize, uint8_t* rxData, uint16_t rxSize,  uint32_t Timeout)
{
	HAL_StatusTypeDef retVal = HAL_ERROR;

	//retVal = this->write(addr, txData, txSize, Timeout);

	if(retVal != HAL_OK)
	{
		return retVal;
	}

	//retVal = this->read(addr, rxData, rxSize, Timeout);

	return retVal;
}

void I2Cbase::bus_wait(void)
{
	while (HAL_I2C_GetState(_hi2c) != HAL_I2C_STATE_READY) {}
}

void I2Cbase::enable_interrupt(void)
{
	_it_enabled = true;
}

void I2Cbase::disable_interrupt(void)
{
	_it_enabled = false;
}





