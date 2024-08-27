/*
 * vl53l0x.h
 */

#ifndef SOURCES_VL53L0X_H_
#define SOURCES_VL53L0X_H_

#include <stdint.h>
#include "vl53l0x/vl53l0x_platform.h" //typedef VL53L0X_Dev_t

//adam
//#include "CLS1.h"

//adam
//uint8_t VL53L0X_ParseCommand(const unsigned char* cmd, bool *handled, const CLS1_StdIOType *io);

uint8_t VL53L0X_DirectMeasureSingle(uint16_t *mm);

uint8_t VL53L0X_DirectInit(void);

/*!
 * \brief Performs a single shot measurement and returns the distance in millimeters
 * \return ERR_OK if everything is fine, error code otherwise
 */
uint8_t VL53L0X_MeasureSingle(uint16_t *mm, VL53L0X_Dev_t *MyDevicePtr);

uint8_t VL53L0X_MeasureSingleCustomAddress(uint16_t *mm, VL53L0X_Dev_t *MyDevicePtr);

/*!
 * \brief Initialize the sensor with the default settings.
 * \return ERR_OK if everything is fine, error code otherwise
 */

uint8_t VL53L0X_CustomAddressInit(VL53L0X_Dev_t *MyDevicePtr);

uint8_t VL53L0X_DirectInit(void);

uint8_t VL53L0X_Init(VL53L0X_Dev_t *MyDevicePtr);


//adam
VL53L0X_Dev_t* GetDeviceDescriptor(void);

#endif /* SOURCES_VL53L0X_H_ */
