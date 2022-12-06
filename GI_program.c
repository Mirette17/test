/*
 * GI_program.c
 *
 * Created: 9/23/2022 9:38:04 AM
 *  Author: A S U S
 */ 

/* Utiles Lib */
#include "STDIN_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "GI_interface.h"

void GI_enable(void)
{
	//Enable Global Interrupt
	SET_BIT(SREG,7); 
}

void GI_disable(void)
{
	//Disable Global Interrupt
	CLR_BIT(SREG,7); 
}
