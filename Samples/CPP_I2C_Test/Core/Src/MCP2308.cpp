/*
 * MCP2308.cpp
 *
 *  Author: Adam Czaga czagaadam@gmail.com
 *
 *  MCP9800 i2c port exp. class
 *
 */

#include "MCP2308.h"
#include "I2Cbase.h"

uint8_t ledson[2] = {OLATADDR , 0xFF};
uint8_t ledsoff[2] = {OLATADDR , 0x00};
uint8_t iodir[2] = {IODIRADDR, 0x00};


MCP2308::MCP2308()
{
	// TODO Auto-generated constructor stub

}


MCP2308::MCP2308(I2Cbase* i2cbase) : _i2cbase(i2cbase)
{
	// TODO Auto-generated constructor stub

}

MCP2308::~MCP2308()
{
	// TODO Auto-generated destructor stub
}

void MCP2308::init()
{
	_i2cbase->write(MCP2308ADDR, iodir, sizeof(iodir), 0);
	//#todo: error handling
}

void MCP2308::port_switch(bool leds_status)
{
	if(leds_status)
	{
		_i2cbase->write(MCP2308ADDR, ledson, sizeof(ledson), 0);
	}else
	{
		_i2cbase->write(MCP2308ADDR, ledsoff, sizeof(ledsoff), 0);
	}
	//#todo: error handling
}
