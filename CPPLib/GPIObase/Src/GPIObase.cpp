/*
 * GPIObase.cpp
 *
 *  Author: Adam Czaga czagaadam@gmail.com
 *
 *  GPIO parent class and Din,Dout inherited classes
 *
 */

#include "GPIObase.h"
#include "ISRbase.h"

extern void MX_GPIO_Init(void);
ISRbase<Din> Din::ISR_LIST;
bool GPIObase::isInit;

GPIObase::GPIObase()
{
	Init();
}

GPIObase::GPIObase(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) : _GPIOx(GPIOx), _GPIO_Pin(GPIO_Pin)
{
	// TODO Auto-generated constructor stub
	Init();
}

GPIObase::~GPIObase() {
	// TODO Auto-generated destructor stub
}

/*GPIObase::GPIObase(const GPIObase& t) // copy constructor
{
	_GPIOx = t._GPIOx;
	_GPIO_Pin = t._GPIO_Pin;
}*/

void GPIObase::Init(void)
{

	if(!GPIObase::isInit)
	{
		return;
	}
	//MX_GPIO_Init();
	GPIObase::isInit = true;
}

// #todo: const correctness
GPIO_PinState GPIObase::read(void)
{
	return HAL_GPIO_ReadPin(_GPIOx, _GPIO_Pin);
}
// #todo: const correctness
uint16_t GPIObase::get_pin(void)
{
	return _GPIO_Pin;
}






Dout::Dout()
{

}
Dout::~Dout()
{
	//#todo:
}

/*Dout::Dout(const Dout& t) : GPIObase(t)
{

}*/

Dout::Dout(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) : GPIObase(GPIOx, GPIO_Pin)
{
	Dout::write(GPIO_PIN_RESET);
}
Dout::Dout(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState state = GPIO_PIN_SET) : GPIObase(GPIOx, GPIO_Pin)
{

}

void Dout::write(GPIO_PinState state)
{
	HAL_GPIO_WritePin(_GPIOx, _GPIO_Pin, state);
}

void Dout::toggle(void){
	HAL_GPIO_TogglePin(_GPIOx, _GPIO_Pin);
}





Din::Din()
{

}
Din::~Din()
{
	Din::ISR_LIST.remove(this);
}

/*Din::Din(const Dout& t) : GPIObase(t)
{

}*/

Din::Din(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) : GPIObase(GPIOx, GPIO_Pin)
{

}

Din::Din(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, gpio_isr_cb cb) : GPIObase(GPIOx, GPIO_Pin)
{

	Din::set_isr_cb(cb);
}

void Din::set_isr_cb(gpio_isr_cb cb)
{
	_cb = cb;	//store (callback) function pointer
	Din::ISR_LIST.add(this);
}
void Din::call_isr(void)
{
	if(_cb == NULL)
	{
		return;
	}
	_cb();
}
void Din::trigger_pin(uint16_t gpio_pin)
{
	for(uint16_t i = 0; i < Din::ISR_LIST.size(); i++)
	{
		uint16_t pin = Din::ISR_LIST.get(i)->get_pin();
		if(pin == gpio_pin)
		{
			Din::ISR_LIST.get(i)->call_isr();
		}
	}
}

void Din::enable_interrupt(void)
{
	//#todo:
}

void Din::disable_interrupt(void)
{
	//#todo:
}






