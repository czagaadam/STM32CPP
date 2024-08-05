/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "gpio.h"
#include "usart.h"
#include "GPIObase.h"
#include "I2Cbase.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "MCP9800.h"
#include "MCP2308.h"
#include "MCP3221.h"

Dout Led1;
Din Btn1;
I2Cbase I2C_3;
MCP9800 I2CTsensor;
MCP2308 I2CPortExp;
MCP3221 I2CADC;

void UART_SendString(char sdata[]) {
	HAL_UART_Transmit(&huart5, (uint8_t*) (sdata), strlen(sdata), 10);
	HAL_UART_Transmit(&huart5, (uint8_t*) "\r\n", 2, 10);
}

void UART_SendInt(int num) {
	char sdata[10] = "";
	sprintf(sdata, "%d", num);
	HAL_UART_Transmit(&huart5, (uint8_t*) (sdata), strlen(sdata), 10);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	Btn1.trigger_pin(GPIO_Pin);
}

void Btn1_call_back(void) {
	Led1.write(GPIO_PIN_SET);
}

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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */


int main(void) {

	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_I2C3_Init();
	MX_TIM1_Init();
	MX_UART5_Init();
	/* USER CODE BEGIN 2 */

	Led1 = Dout(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
	Btn1 = Din(GPIOD, GPIO_PIN_10);
	Btn1.set_isr_cb(Btn1_call_back);
	I2C_3 = I2Cbase(I2C3, &hi2c3);
	I2C_3.enable_interrupt();
	I2CTsensor = MCP9800(&I2C_3);
	I2CPortExp = MCP2308(&I2C_3);
	I2CADC = MCP3221(&I2C_3);

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */

	I2CPortExp.init();	//config port expander, all i/o output

	HAL_Delay(500);
	HAL_Delay(500);

	//I2C_3.write(MCP9800ADDR, configtemp, sizeof(configtemp), 0);	//call directly I2C base class functions
	I2CTsensor.init(); //Writing to the CONFIG Register to change the resolution to 0.0625°C <0110 0000>b.

	HAL_Delay(500);
	HAL_Delay(500);

	while (1) {
		/* USER CODE END WHILE */
		Led1.toggle();

		/*****************TEMP Sensor*****************/
		//I2C_3.write(MCP9800ADDR, readtemp, sizeof(readtemp), 0);	//call directly I2C base class functions
		//I2C_3.bus_wait();											//call directly I2C base class functions
		//I2C_3.read(MCP9800ADDR, temp, sizeof(temp), 0);			//call directly I2C base class functions
		//uint16_t i16_temp = I2CADC1.get_temp();
		float f_tempC;
		f_tempC = I2CTsensor.get_temp_f();
		char ConvertBuffer[30] = "";
		sprintf(ConvertBuffer, "temp: %.6f C", f_tempC); // MCU settings float printf enabled
		//printf("Result is: %d.%d", i/10, i%10);
		UART_SendString(ConvertBuffer);
		HAL_Delay(500);
		/*********************************************/

		/*****************Port Expander***************/
		I2CPortExp.port_switch(true);
		HAL_Delay(500);
		I2CPortExp.port_switch(false);
		HAL_Delay(500);
		/*********************************************/

		/**********************ADC********************/
		float f_adc = I2CADC.read_f();
		char ConvertBuffer2[30] = "";
		sprintf(ConvertBuffer2, "adc: %.6f V", f_adc); // MCU settings float printf enabled
		UART_SendString(ConvertBuffer2);
		HAL_Delay(500);
		HAL_Delay(500);
		/*********************************************/
		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 4;
	RCC_OscInitStruct.PLL.PLLN = 72;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 3;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  Period elapsed callback in non blocking mode
 * @note   This function is called  when TIM6 interrupt took place, inside
 * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
 * a global variable "uwTick" used as application time base.
 * @param  htim : TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	/* USER CODE BEGIN Callback 0 */

	/* USER CODE END Callback 0 */
	if (htim->Instance == TIM6) {
		HAL_IncTick();
	}
	/* USER CODE BEGIN Callback 1 */

	/* USER CODE END Callback 1 */
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
