/*
 * External_Interrupt_interface.h
 *
 * Created: 9/17/2022 11:41:43 AM
 *  Author: A S U S
 */ 


#ifndef EXTERNAL_INTERRUPT_INTERFACE_H_
#define EXTERNAL_INTERRUPT_INTERFACE_H_

/* MACROS For Interrupt Sources */
#define EXTI_INT0                   0		   //PORT D PIN 2
#define	EXTI_INT1                   1		   //PORT D PIN 3
#define	EXTI_INT2                   2		   //PORT B PIN 2
											   
/* MACROS For Interrupt Trigger Edge */
#define EXTI_RISING_EDGE            0
#define EXTI_FALLING_EDGE           1
#define EXTI_LOW_LEVEL              2
#define EXTI_ANY_LOGICAL_CHANGE     3


                       /********************  APIS PROTOTYPES ******************/
void EXTI_enable(u8 interruptSource, u8 interruptTriggerEdge);
void EXTI_disable(u8 interruptSource);
void EXTI_INT0setCallBack(void *(ptr) (void));
void EXTI_INT1setCallBack(void *(ptr) (void));
void EXTI_INT2setCallBack(void *(ptr) (void));


#endif /* EXTERNAL_INTERRUPT_INTERFACE_H_ */