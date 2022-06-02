// include statements includes other files. On normal C projects
// we would have to worry about where these C files are located.
// However, since we are programming using Code Composer Studio
// (CCS), we don't have to worry about it as CCS takes care of
// it for us. These header files (.h files) have loads and loads
// of define statements in them. These are just constants that
// the compiler uses during the compiling process to make our
// code that much more readable. We will talk more about these
// down below.
#include <MSP430.h>

// This is a function prototype. It just defines any functions
// other than main here. This allows us to use them anywhere in
// this .c file. It is best practice to use these so we can have
// a nice list of the functions and if you use comments you can
// also have a nice little description.
int delay(void);		// delays the microcontroller for 10 ms.

// The main function is defined in the first line of code after
// comment. This is just telling the compiler where the computer
// should start running this program.
int main(void)
{
`	// DEFINES USAGE:
	//
	// 	P1DIR is a define from the MSP430.h file. This stands for
	// 	Port #1, direction and decides if the port is an input
	// 	or an output. Ports are made up of several pins that are
	// 	changed by changing the value of the register. 
	// 	P1DIR is defined and all it is an address
	// 	of an register that is allocated to the direction of logic
	// 	for Port #1.
	//
	// 	P1OUT and BIT0 are also defined in the header file. 
	// 	P1OUT stands for Port #1 output and if the direction
	// 	is set to output, changing this address changes whether 
	// 	that port gives a logic high (a 1 or 3.3V) or logic low 
	// 	(a 0 or 0V).
	//
	// 	BIT0 signifies the least significant bit or LSB. Most
	// 	registers we interface with on the MSP430 are 8 bits.
	// 	So the BIT0 define shows us:
	//
	// 		0 0 0 0 0 0 0 1
	// 			      ^
	// 		      	      |
	// 			  This bit!
	//
	// 	This allows us to easily read and figure out what pin on
	// 	that port that we are changing. 
	//
	// 	If we wanted to change Port 6, Pin 6 or the other LED on
	// 	the LaunchPad board we would use:
	// 		P6OUT and BIT6
	// 	to change values. 
	//
	// BITWISE OPERATIONS:
	//
	//	Bitwise OR is used to set bits high. You use a pipe | to
	//	signify this. The equals sign allows us to only write the 
	//	register name once, otherwise it would have to be written:
	//
	//		P1DIR = P1DIR | BIT0;
	//
	//	A good way to think about this operation it is by comparing 
	//	two binary 1 bit numbers. The OR operator is looking are replacing
	//	the number if the first number or the second number is a 1. Doing
	//	this to a register just looks at all of the bits in that register.
	//	Since BIT0 represents this number 00000001, we only change that
	//	bit to a 1. 
	//
	//	Bitwise AND & is used in conjunction with the invert ~ operator and the
	//	equals sign again to force that bit in that register to a logic low. 
	//	This one is a little more difficult to imagine. Bitwise and is looking 
	//	at keeping a 1 in that bit only if the register and the operand 
	//	(in this case BIT0) have a 1. So, we first invert the value of BIT0 to get
	//	11111110. Then we and this value with the register, the only 
	P1DIR |= BIT0;		// sets P1.0 to output
	P1OUT &=~BIT0;		// sets P1.0 to logic low

	// The while statement will allow us to loop forever.
	// It will continuously check after every iteration to
	// see if the statement inside the parentheses is true.
	// Because we put a 1 in the parentheses, the statement
	// is always true.
	while (1)
	{
		// To toggle a bit, the XOR operator is uses. This operator uses a 
		// carrot ^. So to toggle the LED on the LaunchPad Board we will
		// use this operator. In most cases a set and a reset is best practice,
		// however, since this is just a simple LED flashing an XOR is perfect.
		P1OUT ^= BIT0;
	}

	// At the end of the program, we return a zero. This
	// signifies that no error occured. If we wanted to show
	// that an error occured, it is best practice to return a
	// -1. This doesn't have to even be the main function but
	// perhaps another function that performs a task on a 
	// pointer but doesn't return anything. (Don't worry
	// if you don't understand pointers quite yet. Although
	// they are EXTREMELY useful, they are also very confusing
	// so I will touch on them later.)
	// Although the computer will never reach this and CCS will
	// complain about it being in there, it is best practice to 
	// leave it in.
	return 0;
}


int delay(void)
{
	// Delay cycles is a fancy delay function. The MSP430FR2355 has a 1MHz clock
	// so 500,000 is half a second of delay. 
	__delay_cycles(500000);
	return 0;
}
