// author: DawsonXBancroft
// MSP430FR2355 Launchpad Button Testing

#include <msp430.h>

int main(void){
	
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer

	// LED1 Setup
	P1DIR |= BIT0;				// sets P1.0 to output
	P1OUT &=~BIT0;				// sets P1.0 to logic low

	// Button S1 (LEFT)
	P4DIR &=~BIT1;				// sets P4.1 to input
	P4REN |= BIT1;				// sets P4.1 resistor to enabled
	P4OUT |= BIT1;				// sets P4.1 resistor to pull-up

	// Button S2 (RIGHT)
	P2DIR &=~BIT3;				// sets P2.3 to input
	P2REN |= BIT3;				// sets P2.3 resistor to enabled
	P2OUT |= BIT3;				// sets P2.3 resistor to pull-up

	PM5CTL0 &= ~LOCKLPM5;			// turn on GPIO
	
	while(1){
		if(P4IN & BIT1){
			// turn on LED1
		} else {
			// turn off LED1
		}

		// See if S2 has been pressed
		if(P2IN & BIT3)
		{
			// turn on LED2	
		} else {
			// turn off LED2
		}
	}

	return 0;	
}

