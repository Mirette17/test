/*
 * External_Interrupt.c
 *
 * Created: 9/17/2022 11:41:19 AM
 *  Author: A S U S
 */ 

/* Utiles Lib */
#include "STDIN_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "EXTI_interface.h"


static void (*INT0pCallBack) (void) = NULL;
static void (*INT1pCallBack) (void) = NULL;
static void (*INT2pCallBack) (void) = NULL;


void EXTI_enable(u8 interruptSource, u8 interruptTriggerEdge)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		if(EXTI_RISING_EDGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
		else if(EXTI_FALLING_EDGE == interruptTriggerEdge)
		{
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
		else if(EXTI_LOW_LEVEL == interruptTriggerEdge)
		{
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		}
		else if(EXTI_ANY_LOGICAL_CHANGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		}
		
		SET_BIT(GICR,6); //enable INT0
		break;
		
		case EXTI_INT1:
		if(EXTI_RISING_EDGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else if(EXTI_FALLING_EDGE == interruptTriggerEdge)
		{
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else if(EXTI_LOW_LEVEL == interruptTriggerEdge)
		{
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		}
		else if(EXTI_ANY_LOGICAL_CHANGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		}
		
		SET_BIT(GICR,7); //enable INT1
		break;
		
		case EXTI_INT2:
		if(EXTI_RISING_EDGE == interruptTriggerEdge)
		{
			SET_BIT(MCUCSR,6);
		}
		else if(EXTI_FALLING_EDGE == interruptTriggerEdge)
		{
			CLR_BIT(MCUCSR,6);
		}
		
		SET_BIT(GICR,5); //enable INT2
		break;
	}
}

void EXTI_disable(u8 interruptSource)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		CLR_BIT(GICR,6); //disable INT0
		break;
		
		case EXTI_INT1:
		CLR_BIT(GICR,7); //disable INT1
		break;
		
		case EXTI_INT2:
		CLR_BIT(GICR,5); //disable INT2
		break;
	}
}

void EXTI_INT0setCallBack(void *(ptr) (void))
{
	if (ptr != NULL)
	{
		INT0pCallBack = ptr;
	}
};


void EXTI_INT1setCallBack(void *(ptr) (void))
{
	if (ptr != NULL)
	{
		INT1pCallBack = ptr;
	}
};

void EXTI_INT2setCallBack(void *(ptr) (void))
{
	if (ptr != NULL)
	{
		INT2pCallBack = ptr;
	}
};


//ISR Function Prototype EXTI0
void __vector_1(void) __attribute__ ((signal));    //btmna3 el optimization
void __vector_1(void)
{
	//call action
	if(INT0pCallBack != NULL)
	{
		INT0pCallBack();
	}
}

//ISR Function Prototype EXTI1
void __vector_2(void) __attribute__ ((signal));    //btmna3 el optimization
void __vector_2(void)
{
	//call action
	if(INT1pCallBack != NULL)
	{
		INT1pCallBack();
	}
}

//ISR Function Prototype EXTI2
void __vector_3(void) __attribute__ ((signal));    //btmna3 el optimization
void __vector_3(void)
{
	//call action
	if(INT2pCallBack != NULL)
	{
		INT2pCallBack();
	}
}
