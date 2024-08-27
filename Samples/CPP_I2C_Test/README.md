# HOW TO USE GPIO/I2C LIBRARY

🌟 About the Project



👀 Usage

# GPIObase class

Include headers
```javascript
#include "GPIObase.h"
```

Define GPIO objects outside main function
```javascript
Dout Led1;
Din Btn1;
```

Define callback functions
```javascript
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	Btn1.trigger_pin(GPIO_Pin);
}

void Btn1_call_back(void) {
	Led1.write(GPIO_PIN_SET);
}
```


Call constructors and assign callback to object in main
```javascript
Led1 = Dout(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
Btn1 = Din(GPIOD, GPIO_PIN_10);
Btn1.set_isr_cb(Btn1_call_back);
```

# I2Cbase class

Include headers
```javascript
#include "GPIObase.h"
#include "I2Cbase.h"
#include "MCP9800.h"
#include "MCP2308.h"
#include "MCP3221.h
```

Define GPIO objects outside main function
```javascript
Dout Led1;
Din Btn1;
I2Cbase I2C_3;
MCP9800 I2CTsensor;
MCP2308 I2CPortExp;
MCP3221 I2CADC;
```

Define interrupt handlers
```javascript
void I2C3_EV_IRQHandler(void)
{
	HAL_I2C_EV_IRQHandler(&hi2c3);
}

void HAL_I2C_EV_IRQHandler()
{

}

void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	char ConvertBuffer2[30] = "";
	if(hi2c->Devaddress == 0x92)
	{
		sprintf(ConvertBuffer2, "Tenp sensor callback");
		UART_SendString(ConvertBuffer2);
	}
	else if(hi2c->Devaddress == 0x40)
	{
		sprintf(ConvertBuffer2, "Port exp. callback");
		UART_SendString(ConvertBuffer2);
	}
	else if(hi2c->Devaddress == 0x9A)
	{
		sprintf(ConvertBuffer2, "ADC callback");
		UART_SendString(ConvertBuffer2);
	}
	else
	{
		sprintf(ConvertBuffer2, "Unknown dev. callback");
		UART_SendString(ConvertBuffer2);
	}
}
```


Reading MCP9800 temp. sensor  
![temp](https://github.com/user-attachments/assets/7af84153-15ee-4322-9660-dc6660208a99)

Reading MCP9800 temp. sensor and MCP3221 ADC sensor
![temp_and_adc](https://github.com/user-attachments/assets/6aef2aad-bae2-44d6-a07f-189dbf27e9ed)
