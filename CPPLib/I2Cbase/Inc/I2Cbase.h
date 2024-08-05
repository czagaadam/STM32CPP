/*
 * I2Cbase.h
 *
 *  Author: Adam Czaga czagaadam@gmail.com
 *
 *  I2C base class
 *
 */

#ifndef I2CBASE_H_
#define I2CBASE_H_

#include "stm32f4xx_hal.h"

#define I2C_COUNT 2
#define I2C_BUFFER_RX_SIZE 64

#define MCP9800ADDR 	0x92    //MCP9800 addr
#define ACCESS_CONFIG 	0x01    //CONFIG config register
#define READ_TEMP 		0x00	//TEMP register
#define MCP9800_TIMEOUT 100
#define MCP9800ARES 	0x60

class I2Cbase {
public:
	I2Cbase();
	I2Cbase(I2C_TypeDef *Instance, I2C_HandleTypeDef *hi2c);
	virtual ~I2Cbase();

	void init(void);

	template <size_t N> HAL_StatusTypeDef write(uint8_t addr, uint8_t (&txData)[N], uint16_t txSize, uint32_t Timeout)
	{
		HAL_StatusTypeDef status = HAL_ERROR;
		if(txSize == 0)
		{
			return status;
		}
		if(txData == NULL)
		{
			return status;
		}
		while (status != HAL_OK)
		{
			if(_it_enabled)
			{
				status = HAL_I2C_Master_Transmit_IT(_hi2c, addr, txData, txSize);
				//while (HAL_I2C_GetState(_hi2c) != HAL_I2C_STATE_READY) {}
			}
			else
			{
				status = HAL_I2C_Master_Transmit(_hi2c, addr, txData, txSize, Timeout);
			}
			/*if (HAL_I2C_GetError(_hi2c) != HAL_I2C_ERROR_AF) {
				status = HAL_ERROR;
			}*/
		}
		return status;
	}

	template <size_t N> HAL_StatusTypeDef read(uint8_t addr, uint8_t (&rxData)[N], uint16_t rxSize, uint32_t Timeout)
	{
		HAL_StatusTypeDef status = HAL_ERROR;
		if(rxSize == 0)
		{
			return status;
		}
		if(rxData == NULL)
		{
			return status;
		}
		while (status != HAL_OK)
		{
			if(_it_enabled)
			{
				status = HAL_I2C_Master_Receive_IT(_hi2c, addr, rxData, rxSize);
			}
			else
			{
				status = HAL_I2C_Master_Receive(_hi2c, addr, rxData, rxSize, Timeout);
			}
			/*if (HAL_I2C_GetError(_hi2c) != HAL_I2C_ERROR_AF) {
				status = HAL_ERROR;
			}*/
		}
		return status;
	}
	HAL_StatusTypeDef transfer(uint8_t addr, uint8_t* txData, uint16_t txSize, uint8_t* rxData, uint16_t rxSize,  uint32_t Timeout);

	void bus_wait(void);

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
