/*
 * External_Interrupt Test.c
 *
 * Created: 9/17/2022 11:40:29 AM
 * Author : A S U S
 */ 


/* Utiles Lib */
#include "STDIN_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "EXTI_interface.h"
#include "DIO_interface.h"
#include "GI_interface.h"

void INT0_func(void);

int main(void)
{
    /* Replace with your application code */
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	GI_enable();
	EXTI_INT0setCallBack(&INT0_func);
	EXTI_enable(EXTI_INT0,EXTI_RISING_EDGE);
    while (1) 
    {
    }
}

void INT0_func(void)     //n-call el action fl main
{
	DIO_togglePinValue(DIO_PORTC,DIO_PIN2);
}
void print (void)
{ 
}
