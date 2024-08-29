/*
 * MCP9800.cpp
 *
 *  Author: Adam Czaga czagaadam@gmail.com
 *
 *  MCP9800 i2c temp sensor class
 *
 */

#ifndef SRC_MCP9800_H_
#define SRC_MCP9800_H_

#include "main.h"
#include "I2Cbase.h"

#define MCP9800ADDR 	0x92    //MCP9800 addr
#define ACCESS_CONFIG 	0x01    //CONFIG config register
#define READ_TEMP 		0x00	//TEMP register
#define MCP9800ARES 	0x60

extern uint8_t configtemp[2];
extern uint8_t readtemp[1];
extern uint8_t temp[2];

class MCP9800 {
public:
	MCP9800();
	MCP9800(I2Cbase* i2cbase);
	virtual ~MCP9800();
	void init();
	uint16_t get_temp(void);
	float get_temp_f(void);
protected:
	I2Cbase* _i2cbase;
private:
};

#endif /* SRC_MCP9800_H_ */
