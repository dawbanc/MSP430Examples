#include <msp430.h>

#define HZ_HI 1000000
#define HZ_LO 5000
#define HZ_INT 5000

// GLOBALS
// Globals are variables that can be accessed by any function in this program. They are
// easier than using pointers, however they are rarely used in programming due to memory
// allocation and freeing. 
unsigned long hz_cur = 500000;			// define our frequency that we wait to
						// change our LED

int main(void)
{
	WDTCLT = WDTPW | WDTHOLD;		// stop watchdog timer

	// LED1 Setup
	P1DIR |= BIT0;				// sets P1.0 to output
	P1OUT &=~BIT0;				// sets P1.0 to logic low

	// Button S1 (LEFT)
	P4DIR &=~BIT1;				// sets P4.1 to input
	P4REN |= BIT1;				// sets P4.1 resistor to enabled
	P4OUT |= BIT1;				// sets P4.1 resistor to pull-up
	P4IES |= BIT1;				// sets P4.1 trigger sensitivity Hi-to-Lo

	// Button S2 (RIGHT)
	P2DIR &=~BIT3;				// sets P2.3 to input
	P2REN |= BIT3;				// sets P2.3 resistor to enabled
	P2OUT |= BIT3;				// sets P2.3 resistor to pull-up 
	P2IES |= BIT3;				// sets P2.3 trigger sensitivity Hi-to-Lo

	PM5CTL0 &= ~LOCKLPM5;			// turn on GPIO
	
	// Interrupts are used to take control of code temporarily before returning
	// to the rest of the program. This is an alternative to polling and is preferred. 
	// Instead of the program having to constantly check, a logic circuit automatically
	// lets us know when one of the triggers happened and can run a bit of code to 
	// 
	P4IE |= BIT1;				// enable interrupt on pin 4.1
	P2IE |= BIT3;				// enable interrupt on pin 2.3
	__enable_interrupt();			// enable interrupts to take place	

	// Before we begin running the program, we want to ensure that the flag is cleared.
	// This is just one of the few safety precautions we take. 
	P4IFG &=~BIT1;				// clear P4.1 IRQ Flag
	P2IFG &=~BIT3;				// clear P2.3 IRQ Flag

	// Main Loop
	while(1)
	{
		// Besides just changing the LED from turning off and on, the program will
		// just wait for the interrupts to interrupt the program.
		P1OUT |= BIT0;			// turn on LED1
		__delay_cycles(hz_cur/2);	// delay for half of our frequency
		P1OUT &=~BIT0;			// Turn off LED1
		__delay_cycles(hz_cur/2);	// delay for the other half of our frequency
	}

	return 0;	
}

// INTERRUPT SERVICE ROUTINES (ISRs)
//
#pragma vector = PORT4_VECTOR
__interrupt void ISR_Port4_S1(void)
{
	if(hz_cur - HZ_INT > HZ_LO)
	{
		hz_cur -= HZ_INT;		// Now we will decrease our frequency
	}
	P4IFG &=~BIT1;				// clear the P4.1 IRQ Flag
}

#pragma vector = PORT2_VECTOR
__interrupt void ISR_Port2_S2(void)
{
	if(hz_cur + HZ_INT < HZ_HI)
	{
		hz_cur += HZ_INT;		// Now we will increase our frequency
	}
	P2IFG &=~BIT3;				// clear the P2.3 IRQ Flag
}
