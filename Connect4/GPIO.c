#include "GPIO.h"


//function to determine the pin mode input or output, pull up or pull down ,digital enable 
void Pin_Mode(GPIO_Port port, GPIO_Pin pin, GPIO_PinMode dir)
{
    // Check if the port is valid
    if (port != GPIO_PortF) {
        // Handle other ports if needed
        return;
    }

    // Configure the pin based on the desired mode
    switch (dir) {
        case GPIO_PIN_INPUT:
            // Set the pin as input
            GPIO_PORTF_DIR_R &= ~(1 << pin);

            // Disable alternate function, enable digital function, disable analog function
            GPIO_PORTF_AFSEL_R &= ~(1 << pin);
            GPIO_PORTF_DEN_R |= (1 << pin);
            GPIO_PORTF_AMSEL_R &= ~(1 << pin);

            // Clear the pin's PCTL bits
            GPIO_PORTF_PCTL_R &= ~(0xF << (pin * 4));
            break;

        case GPIO_PIN_OUTPUT:
            // Set the pin as output
            GPIO_PORTF_DIR_R |= (1 << pin);

            // Disable alternate function, enable digital function, disable analog function
            GPIO_PORTF_AFSEL_R &= ~(1 << pin);
            GPIO_PORTF_DEN_R |= (1 << pin);
            GPIO_PORTF_AMSEL_R &= ~(1 << pin);

            // Clear the pin's PCTL bits
            GPIO_PORTF_PCTL_R &= ~(0xF << (pin * 4));
            break;

        case GPIO_PIN_INPUT_PULLUP:
            // Set the pin as input
            GPIO_PORTF_DIR_R &= ~(1 << pin);

            // Disable alternate function, enable digital function, disable analog function
            GPIO_PORTF_AFSEL_R &= ~(1 << pin);
            GPIO_PORTF_DEN_R |= (1 << pin);
            GPIO_PORTF_AMSEL_R &= ~(1 << pin);

            // Enable the pull-up resistor for the pin
            GPIO_PORTF_PUR_R |= (1 << pin);

            // Clear the pin's PCTL bits
            GPIO_PORTF_PCTL_R &= ~(0xF << (pin * 4));
            break;

        case GPIO_PIN_INPUT_PULLDOWN:
            // Set the pin as input
            GPIO_PORTF_DIR_R &= ~(1 << pin);

            // Disable alternate function, enable digital function, disable analog function
            GPIO_PORTF_AFSEL_R &= ~(1 << pin);
            GPIO_PORTF_DEN_R |= (1 << pin);
            GPIO_PORTF_AMSEL_R &= ~(1 << pin);

            // Enable the pull-down resistor for the pin
            GPIO_PORTF_PDR_R |= (1 << pin);

            // Clear the pin's PCTL bits
            GPIO_PORTF_PCTL_R &= ~(0xF << (pin * 4));
            break;

        default:
            // Invalid pin mode
            break;
    }
}


//connet specific port to clock 
GPIO_Status GPIO_EnablePortClock(GPIO_Port port)
{
    volatile unsigned long delay;
    
    // Check if the port is valid
    if (port > 7) {
        return GPIO_ERROR_INVALID_PORT;
    }

    SYSCTL_RCGCGPIO_R |= (1 << port);  // Enable the clock for the specified port

    delay = SYSCTL_RCGCGPIO_R;  // Delay for a few cycles to allow the clock to stabilize

    SYSCTL_RCGC2_R |= (1 << port);  // Enable the port in RCGC2 to provide full functionality

    delay = SYSCTL_RCGC2_R;  // Delay

    // Wait for 4 cycles
    for (delay = 0; delay < 4; delay++)
        ;
    return GPIO_SUCCESS;
}


//unlock using magic number
GPIO_Status GPIO_UnlockPort(GPIO_Port port)
{
	volatile uint32_t* portLockReg;
	volatile uint32_t* portCRReg;
    // Check if the port is valid
    if (port < 0 || port > 7) {
        return GPIO_ERROR_INVALID_PORT;
    }

    // Calculate the port-specific register addresses
     portLockReg = (volatile uint32_t *)(GPIO_PORT_BASE + (port << 12) + 0x520);
     portCRReg = (volatile uint32_t *)(GPIO_PORT_BASE + (port << 12) + 0x524);

    // Unlock the specified port
    *portLockReg = 0x4C4F434B;
    *portCRReg = 0x1F;

    return GPIO_SUCCESS;
}




