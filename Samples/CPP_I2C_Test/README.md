# HOW TO USE GPIO/I2C LIBRARY

🌟 About the Project



👀 Usage

# GPIObase class
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
Reading MCP9800 temp. sensor  
![temp](https://github.com/user-attachments/assets/7af84153-15ee-4322-9660-dc6660208a99)

Reading MCP9800 temp. sensor and MCP3221 ADC sensor
![temp_and_adc](https://github.com/user-attachments/assets/6aef2aad-bae2-44d6-a07f-189dbf27e9ed)
