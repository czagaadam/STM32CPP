/*
 * GPIObase.h
 *
 *  Author: Adam Czaga czagaadam@gmail.com
 *
 *  GPIO parent class and Din,Dout inherited classes
 *
 */

#ifndef GPIOBASE_H_
#define GPIOBASE_H_

#include "stm32f4xx_hal.h"
#include "ISRbase.h"


//function pointer for callbacks
typedef void(*gpio_isr_cb)(void);

class GPIObase {
public:
	GPIObase();
	GPIObase(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
	virtual ~GPIObase();
	//GPIObase(const GPIObase& t);
	void Init(void);
	GPIO_PinState read(void);
	uint16_t get_pin(void);


protected:
	GPIO_TypeDef* _GPIOx;
	uint16_t _GPIO_Pin;
private:
	static bool isInit;

};


class Dout : public GPIObase
{
	public:
	Dout();
	//copy constructor but it is not used
	//non-static reference member can't use default assignment operator
	//Dout(Dout& t);
	Dout(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
	Dout(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState state);
	~Dout();
	//Dout(const Dout& t);
	//void set(void);
	//void clear(void);
	void write(GPIO_PinState state);
	void toggle(void);
	protected:
	private:

};


class Din : public GPIObase
{
	public:
	Din();
	Din(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
	Din(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, gpio_isr_cb cb);
	~Din();
	//Din(const Din& t);
	static void trigger_pin(uint16_t PIN);	//find Din object in storage by pin number and call call_isr method of that object
	void set_isr_cb(gpio_isr_cb cb);		//set function pointer
	void call_isr(void);					//call call back function pointed by function pointer
	gpio_isr_cb _cb;						//function pointer
	void enable_interrupt(void);
	void disable_interrupt(void);
	protected:
	static ISRbase<Din> ISR_LIST;
	private:
};











#endif /* GPIOBASE_H_ */
