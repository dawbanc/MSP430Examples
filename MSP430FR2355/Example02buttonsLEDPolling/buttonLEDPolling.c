#include <msp430.h>

// DEFINE STATEMENTS
// As stated before, define statements are used for constants. The usual case,
// and the one in this demonstation, is comparisons. We will be using HZ_HI and
// HZ_LO to define our range in which the frequency of our LED can be changed by
// the buttons. HZ_INT will be the interval at which our frequency will change.
#define HZ_HI 1000000
#define HZ_LO 5000
#define HZ_INT 5000

// Function Prototypes
void delay(int n);

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer

	// LED1 Setup
	P1DIR |= BIT0;				// sets P1.0 to output
	P1OUT &=~BIT0;				// sets P1.0 to logic low

	// SWTICHES
	// The switches on the LaunchPad board are tied to ground and the pin on
	// the microcontroller. This means we will want to have a pull-up resistor
	// on the pins of the microcontrollers that goes to these pins. Luckily,
	// the MSP430 has a way to add a pull-up resistor within the microcontroller
	// itself so we don't have to solder a resistor onto the LaunchPad. You may
	// be curious why we are using the OUT registers for the ports. This is odd
	// but because we are putting the pins into input mode, the OUT registers
	// use their secondary purpose.

	// Button S1 (LEFT)
	P4DIR &=~BIT1;				// sets P4.1 to input
	P4REN |= BIT1;				// sets P4.1 resistor to enabled
	P4OUT |= BIT1;				// sets P4.1 resistor to pull-up

	// Button S2 (RIGHT)
	P2DIR &=~BIT3;				// sets P2.3 to input
	P2REN |= BIT3;				// sets P2.3 resistor to enabled
	P2OUT |= BIT3;				// sets P2.3 resistor to pull-up

	PM5CTL0 &= ~LOCKLPM5;			// turn on GPIO
	
	unsigned long hz_cur = 50000; 		// define our frequency that we
						// wait to change the LEDs status

	// Main loop
	// Within our main loop we will be polling to see if the buttons have
	// been pressed. This just means that everytime we iterate thought the
	// loop we will check if the button is pressed. 
	while(1)
	{
		// See if S1 has been pressed
		if(P4IN & BIT1)
		{
			// If S1 has been pressed decrease frequency but
			// first we need to check to see if we are out of 
			// range.
			if(hz_cur - HZ_INT > HZ_LO)
			{
				hz_cur -= HZ_INT;	// Now we will decrease
							// our freqency
			}
		}

		// See if S2 has been pressed
		if(P2IN & BIT3)
		{
			// If S2 has been pressed increase frequency but
			// first we need to check to see if we are out of 
			// range. 
			if (hz_cur + HZ_INT < HZ_HI)
			{
				hz_cur += HZ_INT;	// Now we will increase
							// our frequency
			}
			
		}
		P1OUT |= BIT0;			// Turn on LED1
		delay(hz_cur/2);		// delay for half of our frequency
		P1OUT &=~BIT0;			// Turn off LED1
		delay(hz_cur/2);		// delay for the other half of our frequency
	}

	return 0;	
}

void delay(int n){
	for(int i=0; i<n; i++){}; // delay
}
