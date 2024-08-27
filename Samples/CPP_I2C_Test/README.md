# HOW TO USE I2C LIBRARY

👀 Usage
```javascript
	Led1 = Dout(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
	Btn1 = Din(GPIOD, GPIO_PIN_10);
	Btn1.set_isr_cb(Btn1_call_back);
```

Reading MCP9800 temp. sensor  
![temp](https://github.com/user-attachments/assets/7af84153-15ee-4322-9660-dc6660208a99)

Reading MCP9800 temp. sensor and MCP3221 ADC sensor
![temp_and_adc](https://github.com/user-attachments/assets/6aef2aad-bae2-44d6-a07f-189dbf27e9ed)
