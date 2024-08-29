/*
 * MCP2308.cpp
 *
 *  Author: Adam Czaga czagaadam@gmail.com
 *
 *  MCP2308 i2c port exp. class
 *
 */


#ifndef MCP2308_H_
#define MCP2308_H_

#include "main.h"
#include "I2Cbase.h"

#define MCP2308ADDR 0x40    //MCP2308 ADDRESS
#define IODIRADDR 	0x00	//I/O DIRECTION (IODIR) REGISTER
#define OLATADDR 	0x0A	//OUTPUT LATCH REGISTER (OLAT)

extern uint8_t ledson[2];
extern uint8_t ledsoff[2];
extern uint8_t iodir[2];

class MCP2308 {
public:
	MCP2308();
	MCP2308(I2Cbase* i2cbase);
	virtual ~MCP2308();
	void init();
	void port_switch(bool leds_status);
protected:
	I2Cbase* _i2cbase;
private:
};

#endif /* MCP2308_H_ */
