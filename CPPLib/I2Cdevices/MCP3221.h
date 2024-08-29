/*
 * MCP3221.cpp
 *
 *  Author: Adam Czaga czagaadam@gmail.com
 *
 *  MCP3221 i2c adc class
 *
 */


#ifndef MCP3221_H_
#define MCP3221_H_

#include "MCP3221.h"
#include "I2Cbase.h"

#define MCP3221ADDR 0x9A

extern uint8_t adc_dummy_write[1];
extern uint8_t adc[2];

class MCP3221 {
public:
	MCP3221();
	MCP3221(I2Cbase* i2cbase);
	virtual ~MCP3221();
	void init();
	float read_f();
protected:
	I2Cbase* _i2cbase;
private:
};

#endif /* MCP3221_H_ */
