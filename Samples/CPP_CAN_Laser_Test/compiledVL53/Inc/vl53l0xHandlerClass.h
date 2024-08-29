/*
 * vl53l0xHandlerClass.h
 *
 *  Created on: 2019. szept. 21.
 *      Author: czagaa
 */

#ifndef VL53L0XHANDLERCLASS_H_
#define VL53L0XHANDLERCLASS_H_

void VL53L0X_InitHandlerClass(uint8_t numofDevices);

VL53L0X_Dev_t VL53L0X_APPSGetDevice(uint8_t Indexer);

VL53L0X_Dev_t VL53L0X_APPSGetLastDevice();

uint8_t VL53L0X_APPSGetDeviceIndexer();

void VL53L0X_APPSConfigDevice(I2C_HandleTypeDef* hi2c, GPIO_TypeDef* port, uint16_t gpioDxshutpin, uint8_t type, uint8_t speed, uint8_t address);

void VL53L0X_APPSDeleteDevice();

void VL53L0X_APPStart(void);

void VL53L0X_APPStartWithCustomAddress(uint8_t Indexer);

void VL53L0X_APPStartLastDevice();

void VL53L0X_APPSResetNodes();

void VL53L0X_APPSSetAddress(uint8_t Indexer);

void VL53L0X_APPSetLastDeviceAddress();

uint16_t VL53L0X_APPSNodeMeasure(uint8_t Indexer);

uint16_t VL53L0X_APPSLastNodeMeasure();
#endif /* VL53L0XHANDLERCLASS_H_ */
