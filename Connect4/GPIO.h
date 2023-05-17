#ifndef GPIO_H
#define GPIO_H

#include <stdbool.h>

#include <stdint.h>
#define SYSCTL_RCGCGPIO_R   (*((volatile uint32_t *)0x400FE608))

#define GPIO_PORT_BASE      0x40025000
#define GPIO_PORT_LOCK_R    (*((volatile uint32_t *)(GPIO_PORT_BASE + 0x520)))
#define GPIO_PORT_CR_R      (*((volatile uint32_t *)(GPIO_PORT_BASE + 0x524)))

#define SYSCTL_RCGC2_R (*((volatile uint32_t *)0x400FE108))

#define GPIO_PORTA_DIR_R    (*((volatile uint32_t *)0x40004400))
#define GPIO_PORTB_DIR_R    (*((volatile uint32_t *)0x40005400))
#define GPIO_PORTF_DIR_R    (*((volatile uint32_t *)0x40025400))

#define GPIO_PORTA_PUR_R    (*((volatile uint32_t *)0x40004510))
#define GPIO_PORTB_PUR_R    (*((volatile uint32_t *)0x40005510))
#define GPIO_PORTF_PUR_R    (*((volatile uint32_t *)0x40025510))

#define GPIO_PORTA_PDR_R    (*((volatile uint32_t *)0x40004514))
#define GPIO_PORTB_PDR_R    (*((volatile uint32_t *)0x40005514))
#define GPIO_PORTF_PDR_R    (*((volatile uint32_t *)0x40025514))
	

#define GPIO_PORTF_DATA_R       (*((volatile uint32_t *)0x400253FC))

#define GPIO_PORTF_AFSEL_R      (*((volatile uint32_t *)0x40025420))

#define GPIO_PORTF_DEN_R        (*((volatile uint32_t *)0x4002551C))
#define GPIO_PORTF_AMSEL_R      (*((volatile uint32_t *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile uint32_t *)0x4002552C))


#define GPIO_PORTA_ICR_R    (*((volatile uint32_t *)(GPIO_PORT_BASE + 0x41C)))
#define GPIO_PORTB_ICR_R    (*((volatile uint32_t *)(GPIO_PORT_BASE + 0x51C)))
#define GPIO_PORTF_ICR_R    (*((volatile uint32_t *)(GPIO_PORT_BASE + 0x41C)))


#define GPIO_PORTF_IBE_R            (*((volatile uint32_t *)(GPIO_PORT_BASE + 0x408)))  // GPIO Interrupt Both Edges Register
#define GPIO_PORTF_IEV_R            (*((volatile uint32_t *)(GPIO_PORT_BASE + 0x40C)))  // GPIO Interrupt Event Register
#define GPIO_PORTF_IM_R             (*((volatile uint32_t *)(GPIO_PORT_BASE + 0x410)))  // GPIO Interrupt Mask Register
#define GPIO_PORTF_IS_R             (*((volatile uint32_t *)(GPIO_PORT_BASE + 0x404)))  // GPIO Interrupt Sense Register



#define GPIO_PORTF_RIS_R           (*((volatile uint32_t *)(GPIO_PORT_BASE + 0x414)))
#define GPIO_PORTF_MIS_R           (*((volatile uint32_t *)(GPIO_PORT_BASE + 0x418)))



#define NVIC_EN0_R       (*((volatile uint32_t *)0xE000E100))  // Interrupt 0-31 Set Enable Register
#define NVIC_PRI7_R      (*((volatile uint32_t *)0xE000E41C))  // Interrupt 28-31 Priority Register
	

#define GPIO_PORTA_BASE 0x40004000  // Base address of GPIO Port A
#define GPIO_PORTB_BASE 0x40005000  // Base address of GPIO Port B
#define GPIO_PORTC_BASE 0x40006000  // Base address of GPIO Port C
#define GPIO_PORTD_BASE 0x40007000  // Base address of GPIO Port D
#define GPIO_PORTE_BASE 0x40024000  // Base address of GPIO Port E

// GPIO Port A registers
#define GPIO_PORTA_IS_R      (*((volatile uint32_t *)(GPIO_PORTA_BASE + 0x404)))
#define GPIO_PORTA_IBE_R     (*((volatile uint32_t *)(GPIO_PORTA_BASE + 0x408)))
#define GPIO_PORTA_IEV_R     (*((volatile uint32_t *)(GPIO_PORTA_BASE + 0x40C)))
#define GPIO_PORTA_IM_R      (*((volatile uint32_t *)(GPIO_PORTA_BASE + 0x410)))
#define GPIO_PORTA_RIS_R     (*((volatile uint32_t *)(GPIO_PORTA_BASE + 0x414)))


// GPIO Port B registers
#define GPIO_PORTB_IS_R      (*((volatile uint32_t *)(GPIO_PORTB_BASE + 0x404)))
#define GPIO_PORTB_IBE_R     (*((volatile uint32_t *)(GPIO_PORTB_BASE + 0x408)))
#define GPIO_PORTB_IEV_R     (*((volatile uint32_t *)(GPIO_PORTB_BASE + 0x40C)))
#define GPIO_PORTB_IM_R      (*((volatile uint32_t *)(GPIO_PORTB_BASE + 0x410)))
#define GPIO_PORTB_RIS_R     (*((volatile uint32_t *)(GPIO_PORTB_BASE + 0x414)))

// GPIO Port C registers
#define GPIO_PORTC_IS_R      (*((volatile uint32_t *)(GPIO_PORTC_BASE + 0x404)))
#define GPIO_PORTC_IBE_R     (*((volatile uint32_t *)(GPIO_PORTC_BASE + 0x408)))
#define GPIO_PORTC_IEV_R     (*((volatile uint32_t *)(GPIO_PORTC_BASE + 0x40C)))
#define GPIO_PORTC_IM_R      (*((volatile uint32_t *)(GPIO_PORTC_BASE + 0x410)))
#define GPIO_PORTC_RIS_R     (*((volatile uint32_t *)(GPIO_PORTC_BASE + 0x414)))
#define GPIO_PORTC_ICR_R     (*((volatile uint32_t *)(GPIO_PORTC_BASE + 0x41C)))

// GPIO Port D registers
#define GPIO_PORTD_IS_R      (*((volatile uint32_t *)(GPIO_PORTD_BASE + 0x404)))
#define GPIO_PORTD_IBE_R     (*((volatile uint32_t *)(GPIO_PORTD_BASE + 0x408)))
#define GPIO_PORTD_IEV_R     (*((volatile uint32_t *)(GPIO_PORTD_BASE + 0x40C)))
#define GPIO_PORTD_IM_R      (*((volatile uint32_t *)(GPIO_PORTD_BASE + 0x410)))
#define GPIO_PORTD_RIS_R     (*((volatile uint32_t *)(GPIO_PORTD_BASE + 0x414)))
#define GPIO_PORTD_ICR_R     (*((volatile uint32_t *)(GPIO_PORTD_BASE + 0x41C)))

// GPIO Port E registers
#define GPIO_PORTE_IS_R      (*((volatile uint32_t *)(GPIO_PORTE_BASE + 0x404)))
#define GPIO_PORTE_IBE_R     (*((volatile uint32_t *)(GPIO_PORTE_BASE + 0x408)))
#define GPIO_PORTE_IEV_R     (*((volatile uint32_t *)(GPIO_PORTE_BASE + 0x40C)))
#define GPIO_PORTE_IM_R      (*((volatile uint32_t *)(GPIO_PORTE_BASE + 0x410)))
#define GPIO_PORTE_RIS_R     (*((volatile uint32_t *)(GPIO_PORTE_BASE + 0x414)))
#define GPIO_PORTE_ICR_R     (*((volatile uint32_t *)(GPIO_PORTE_BASE + 0x41C)))
#define NVIC_PRI0_R (*((volatile uint32_t *)0xE000E400))

typedef unsigned int uint32_t;

typedef unsigned char uint8_t;

typedef unsigned short uint16_t;

typedef enum
{
    GPIO_PortA,
    GPIO_PortB,
    GPIO_PortC,
    GPIO_PortD,
    GPIO_PortE,
    GPIO_PortF
} GPIO_Port;



typedef enum {
    GPIO_SUCCESS,
    GPIO_ERROR_INVALID_PORT,
    GPIO_ERROR_INVALID_PIN,
    GPIO_ERROR_INVALID_DIRECTION
} GPIO_Status;

typedef enum {
    GPIO_DIRECTION_INPUT,
    GPIO_DIRECTION_OUTPUT
} GPIO_Direction;




typedef enum {
    GPIO_PIN_INPUT,
    GPIO_PIN_OUTPUT,
    GPIO_PIN_INPUT_PULLUP,
    GPIO_PIN_INPUT_PULLDOWN,
} GPIO_PinMode;

typedef enum {
    GPIO_INTERRUPT_TRIGGER_NONE,
    GPIO_INTERRUPT_TRIGGER_RISING_EDGE,
    GPIO_INTERRUPT_TRIGGER_FALLING_EDGE,
    GPIO_INTERRUPT_TRIGGER_BOTH_EDGES
} GPIO_InterruptTrigger;


typedef enum {
    GPIO_PIN_0  = 0x01,
    GPIO_PIN_1  = 0x02,
    GPIO_PIN_2  = 0x04,
    GPIO_PIN_3  = 0x08,
    GPIO_PIN_4  = 0x10,
    GPIO_PIN_5  = 0x20,
    GPIO_PIN_6  = 0x40,
    GPIO_PIN_7  = 0x80
} GPIO_Pin;


void Pin_Mode(GPIO_Port port, GPIO_Pin pin, GPIO_PinMode dir);
GPIO_Status GPIO_EnablePortClock(GPIO_Port port);
GPIO_Status GPIO_UnlockPort(GPIO_Port port);

uint8_t GetInterruptNumber(GPIO_Port port, GPIO_Pin pin);
void GPIO_EnableInterrupt(GPIO_Port port, GPIO_Pin pin);
void GPIO_EnableFallingEdgeEvent(GPIO_Port port, GPIO_Pin pin);
void GPIO_EnableBothEdgesTrigger(GPIO_Port port, GPIO_Pin pin) ;
void GPIO_EnableEdgeSensitive(GPIO_Port port, GPIO_Pin pin);
void GPIO_ConfigureInterrupts(GPIO_Port port, GPIO_Pin pin, bool edgeSensitive, bool bothEdgesTrigger, bool fallingEdgeEvent, uint8_t priority) ;
void GPIO_ClearInterruptFlags(GPIO_Port port, GPIO_Pin pin) ;
void GPIO_EnableInterruptNVIC(uint8_t interruptNumber, uint8_t priority);
void configureGPIOInterrupts();
//void PortF_Init(void);

#endif