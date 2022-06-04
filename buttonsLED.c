#include <msp430.h>

int main(void)
{
	WDTCLT = WDTPW | WDTHOLD;		// stop watchdog timer

	// LED1 Setup
	P1DIR |= BIT0;				// sets P1.0 to output
	P1OUT &=~BIT0;				// sets P1.0 to logic low

	// Button S1 (LEFT)
	P4DIR &=~BIT1;				// sets P4.1 to input
	P4REN |= BIT1;				// sets P4.1 resistor to enabled
	P4OUT &=~BIT1;				// sets P4.1 resistor to pull-up

	// Button S2 (RIGHT)
	P2DIR &=~BIT3;				// sets P2.3 to input
	P2REN |= BIT3;				// sets P2.3 resistor to enabled
	P2OUT &=~BIT3;				// sets P2.3 resistor to pull-up

	PM5CTL0 &= ~LOCKLPM5;			// turn on GPIO
	
	// Interrupts are used to take control of code temporarily before returning
	// to the rest of the program. This is an altera
	P4IE |= BIT1;				// enable interrupt on pin 4.1
	P2IE |= BIT3;				// enable interrupt on pin 2.3
	__enable_interrupt();			// enable interrupts to take place	

	return 0;	
}
