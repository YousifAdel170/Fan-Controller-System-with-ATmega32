 /******************************************************************************
 * Module: ADC
 * File Name: adc.h
 * Description: Header file for the ADC driver
 * Author: Yousif Adel
 *******************************************************************************/
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL
}ADC_ReferenceVoltage;

typedef enum
{
	D_F_0, D_F_2, D_F_4, D_F_8, D_F_16, D_F_32, D_F_64, D_F_128
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_MAXIMUM_VALUE	1023
#define ADC_REF_VOLT_VALUE	2.56



/***************** ADC Registers type structure declarations *******************/
typedef union
{
	uint8 Byte;
	struct
	{
		uint8 MUX0_Bit:1;
		uint8 MUX1_Bit:1;
		uint8 MUX2_Bit:1;
		uint8 MUX3_Bit:1;
		uint8 MUX4_Bit:1;
		uint8 ADLAR_Bit:1;
		uint8 REFS0_Bit:1;
		uint8 REFS1_Bit:1;

	}Bits;
}ADC_ADMUX_Type;

typedef union
{
	uint8 Byte;
	struct
	{
		uint8 ADPS0_Bit:1;
		uint8 ADPS1_Bit:1;
		uint8 ADPS2_Bit:1;
		uint8 ADIE_Bit:1;
		uint8 ADIF_Bit:1;
		uint8 ADATE_Bit:1;
		uint8 ADSC_Bit:1;
		uint8 ADEN_Bit:1;
	}Bits;
}ADC_ADCSRA_Type;

/******************************************************************************/
typedef union {
	uint8 Byte;
	struct{
		uint8 C_Bit:1;
		uint8 Z_Bit:1;
		uint8 N_Bit:1;
		uint8 V_Bit:1;
		uint8 S_Bit:1;
		uint8 H_Bit:1;
		uint8 T_Bit:1;
		uint8 I_Bit:1;
	}Bits;
}SREG_Type;
/******************************************************************************/

/**************************** ADC Registers Definitions ***********************/
#define ADC_ADMUX_REG			(*(volatile ADC_ADMUX_Type*)0x27)
#define ADC_ADCSRA_REG			(*(volatile ADC_ADCSRA_Type*)0x26)
#define ADC_REG      			(*(volatile uint16 *)(0x24))
/*******************************************************************************/
#define SREG_REG      			(*(volatile SREG_Type*)0x5F)
/*******************************************************************************/

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);
/*OLD way*/
	//void ADC_init(void);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */

uint16 ADC_readChannel(uint8 channel_num);


#endif /* ADC_H_ */
