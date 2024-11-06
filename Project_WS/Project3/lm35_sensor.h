 /******************************************************************************
 * Module: LM35 Sensor
 * File Name: lm35_sensor.h
 * Description: Header file for the LM35 Sensor driver
 * Author: Yousif Adel
 *******************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define SENSOR_MAX_VOLT_VALUE		1.5
#define SENSOR_MAX_TEMPERATURE		150
#define SENSOR_CHANNEL_ID			2

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);

#endif	/* LM35_SENSOR_H_	*/
