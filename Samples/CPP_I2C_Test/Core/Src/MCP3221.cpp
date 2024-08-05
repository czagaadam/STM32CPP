/*
 * MCP3221.cpp
 *
 *  Author: Adam Czaga czagaadam@gmail.com
 *
 *  MCP9800 i2c adc class
 *
 */

#include "MCP3221.h"
#include "I2Cbase.h"

uint8_t adc_dummy_write[1] = { 0x00 };
uint8_t adc[2];

MCP3221::MCP3221()
{
	// TODO Auto-generated constructor stub

}


MCP3221::MCP3221(I2Cbase* i2cbase) : _i2cbase(i2cbase)
{
	// TODO Auto-generated constructor stub

}

MCP3221::~MCP3221()
{
	// TODO Auto-generated destructor stub
}

void MCP3221::init()
{
	//#todo: error handling
}

float MCP3221::read_f()
{
	_i2cbase->write(MCP3221ADDR, adc_dummy_write, sizeof(adc_dummy_write), 0);
	//_i2cbase->bus_wait();
	_i2cbase->read(MCP3221ADDR, adc, sizeof(adc), 0);
	//#todo: error handling

	int totalVal = 0;
	totalVal = adc[0] << 8;
	totalVal = totalVal + adc[1];
	float AnalogIn = 0;
	AnalogIn = totalVal * 0.000732421875; // vdd/4096
	return AnalogIn;

}
