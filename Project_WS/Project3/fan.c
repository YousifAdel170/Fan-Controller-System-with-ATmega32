/******************************************************************************
 * File Name: fan.c
 * Description: Source file for the AVR Fan Controller system driver
 * Author:	Yousif Adel
 *******************************************************************************/
#include "lcd.h"
#include "dc_motor.h"
#include "lm35_sensor.h"
#include "adc.h"

/* global variable to store the speed  */
uint8 g_speed = 0;

void adjustTemperatureFan(void)
{

	uint8 temperature = LM35_getTemperature();

	if(temperature < 30)
	{
		g_speed = 0;
		DcMotor_Rotate(OFF,g_speed);
		LCD_moveCursor(0,3);
		LCD_displayString("Fan is OFF");
		LCD_moveCursor(1,3);
		LCD_displayString("Temp is ");
		LCD_integerToString(temperature);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_displayCharacter(' ');
	}
	else if ((temperature >= 30) && (temperature <60))
	{
		g_speed = 25;
		DcMotor_Rotate(ON,g_speed);
		LCD_moveCursor(0,3);
		LCD_displayString("Fan is ON ");
		LCD_moveCursor(1,3);
		LCD_displayString("Temp is ");
		LCD_integerToString(temperature);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_displayCharacter(' ');
	}
	else if ((temperature >= 60) && (temperature <90))
	{
		g_speed = 50;
		DcMotor_Rotate(ON,g_speed);
		LCD_moveCursor(0,3);
		LCD_displayString("Fan is ON");
		LCD_moveCursor(1,3);
		LCD_displayString("Temp is ");
		LCD_integerToString(temperature);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_displayCharacter(' ');
	}
	else if ((temperature >= 90) && (temperature <120))
	{
		g_speed = 75;
		DcMotor_Rotate(ON,g_speed);
		LCD_moveCursor(0,3);
		LCD_displayString("Fan is ON");
		LCD_moveCursor(1,3);
		LCD_displayString("Temp is ");
		LCD_integerToString(temperature);
		if(temperature<100)
		{
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}
	else if ((temperature >= 120))
	{
		g_speed = 100;
		DcMotor_Rotate(ON,g_speed);
		LCD_moveCursor(0,3);
		LCD_displayString("Fan is ON");
		LCD_moveCursor(1,3);
		LCD_displayString("Temp is ");
		LCD_integerToString(temperature);
	}

}

int main(void)
{
	/*  Create configuration structure for ADC driver */
	ADC_ConfigType	ADC_Configurations = {INTERNAL, D_F_8};
	ADC_init(&ADC_Configurations); /* initialize ADC driver */
	DcMotor_init();
	LCD_init(); /* initialize LCD driver */
	while(1)
	{
		adjustTemperatureFan();
	}
}
