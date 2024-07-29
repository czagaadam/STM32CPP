/*
 * I2Cbase.cpp
 *
 *  Created on: Jun 20, 2024
 *      Author: acer1
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

HAL_StatusTypeDef I2Cbase::write(uint8_t addr, uint8_t* txData, uint16_t txSize, uint32_t Timeout)
{
	if(txSize == 0)
	{
		return HAL_ERROR;
	}
	if(txData == NULL)
	{
		return HAL_ERROR;
	}
	if(_it_enabled) return HAL_I2C_Master_Transmit_IT(_hi2c, addr, txData, txSize);
	else			return HAL_I2C_Master_Transmit(_hi2c, addr, txData, txSize, Timeout);
}

HAL_StatusTypeDef I2Cbase::read(uint8_t addr, uint8_t* rxData, uint16_t rxSize, uint32_t Timeout)
{
	if(rxSize == 0)
	{
		return HAL_ERROR;
	}
	if(rxData == NULL)
	{
		return HAL_ERROR;
	}
	if(_it_enabled) return HAL_I2C_Master_Receive_IT(_hi2c, addr, rxData, rxSize);
	else			return HAL_I2C_Master_Receive(_hi2c, addr, rxData, rxSize, Timeout);
}

HAL_StatusTypeDef I2Cbase::transfer(uint8_t addr, uint8_t* txData, uint16_t txSize, uint8_t* rxData, uint16_t rxSize,  uint32_t Timeout)
{
	HAL_StatusTypeDef retVal = HAL_ERROR;

	retVal = this->write(addr, txData, txSize, Timeout);

	if(retVal != HAL_OK)
	{
		return retVal;
	}

	retVal = this->read(addr, rxData, rxSize, Timeout);

	return retVal;
}

void I2Cbase::enable_interrupt(void)
{
	_it_enabled = true;
}

void I2Cbase::disable_interrupt(void)
{
	_it_enabled = false;
}

