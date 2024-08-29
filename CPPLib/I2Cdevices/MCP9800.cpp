/*
 * MCP9800.cpp
 *
 *  Author: Adam Czaga czagaadam@gmail.com
 *
 *  MCP9800 i2c temp sensor class
 *
 */

#include "MCP9800.h"
#include "I2Cbase.h"

uint8_t configtemp[2] = {ACCESS_CONFIG , MCP9800ARES};
uint8_t readtemp[1] = {READ_TEMP};
uint8_t temp[2];

MCP9800::MCP9800()
{
	// TODO Auto-generated constructor stub

}


MCP9800::MCP9800(I2Cbase* i2cbase) : _i2cbase(i2cbase)
{
	// TODO Auto-generated constructor stub

}

MCP9800::~MCP9800()
{
	// TODO Auto-generated destructor stub
}

void MCP9800::init() {
	_i2cbase->write(MCP9800ADDR, configtemp, sizeof(configtemp), 0);
	//#todo: error handling
}

uint16_t MCP9800::get_temp(void) {
	_i2cbase->write(MCP9800ADDR, readtemp, sizeof(readtemp), 0);
	//_i2cbase->bus_wait();
	_i2cbase->read(MCP9800ADDR, temp, sizeof(temp), 0);
	return ((temp[0]<<8)|temp[1]);
}

float MCP9800::get_temp_f(void) {
	float f_tempC, f_tempF;
	_i2cbase->write(MCP9800ADDR, readtemp, sizeof(readtemp), 0);
	//_i2cbase->bus_wait();
	_i2cbase->read(MCP9800ADDR, temp, sizeof(temp), 0);
	f_tempC = ((temp[0]<<8)|temp[1]);       //int to float
	f_tempC = f_tempC / 256;        		//convert to Cersius
	f_tempF = f_tempC * 9 / 5 + 32;
	return f_tempC;
}




