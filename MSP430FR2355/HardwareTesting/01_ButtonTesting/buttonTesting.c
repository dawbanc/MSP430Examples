// author: DawsonXBancroft
// MSP430FR2355 Launchpad Button Testing

#include <msp430.h>

int main(void){
	
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer

	// LED1 Setup
	P1DIR |= BIT0;				// sets P1.0 to output
	P1OUT &=~BIT0;				// sets P1.0 to logic low

	// LED2 Setup
	P6DIR |= BIT6;				// sets P6.6 to output
	P6OUT &=~BIT6;				// sets P6.6 to logic low

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
		if(P4IN & BIT1){ // if button 1 is not pressed
			// turn off LED1
			P1OUT &=~BIT0;
		} else {
			// turn on LED1
			P1OUT |= BIT0;
		}

		// See if S2 has been pressed
		if(P2IN & BIT3) // if button 2 has not been pressed
		{
			// turn off LED2	
			P6OUT &=~BIT6;
		} else {
			// turn on LED2
			P6OUT |= BIT6;
		}
	}

	return 0;	
}

