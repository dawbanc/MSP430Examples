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
						
	

	return 0;	
}
