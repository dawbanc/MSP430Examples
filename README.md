# MSP430Examples Repository
Examples of code to run on MSP430FR2355 LaunchPad boards. These boards can be purchased directly from [Texas Instruments](https://www.ti.com/tool/MSP-EXP430FR2355) (but can also be found at other retailers such as Digikey, Mouser, etc.). Below each example description is the status of that example. As these are added and tested they will be updated. 

## Usage
This repository is to serve as a manual on how to do things on an MSP430FR2355. This includes everything from how to control pins to how modules work. It is designed to teach ANYONE on how to use these microcontrollers, but are good to review (at least for me when I forget on how to do something very specific with communication modules). While more and more examples may be added in the future, each one should have a thorough explanation on what that example teaches both on this page and within the comments of the code. If you are new to this type of thing, it might be a good idea to read through the code, take notes on some of the major things and try to code it yourself.

## Example Descriptions
### 1.) blinkingLED.c (unverified)
This code is created to be used on a LaunchPad board but can be easily modified to work on other hardware. This is a simple start to micro-contoller programming. It will flash LED1 at a rate of 2Hz (or half a second intervals). 

This content can be very dry, especially in the first little bit of learning. However, the knowledge in this first example is crucial for everything in the future. This example shows some bitwise operations that are commonly used on the MSP430 along with the general outline on how C code works on the MSP430 microcontroller. 

To turn on and off pins, the `PxDIR` and `PxOUT` registers will be changed. 
To change those individual bits the OR `|`, AND `&`, and XOR `^` bitwise operations are used. 
Make sure that the watchdog timer is stopped using `WDTCLT = WDTPW | WDTHOLD;` and that the GPIO is turned on using `PM5CTL0 &= ~LOCKLPM5;` as these are commonly forgotten when starting a new project.

- [x] Started
- [x] Coded
- [ ] Verified

### 2.) buttonsLEDPolling.c (unverified)
Very similar to the first bit of code as in we are flashing LEDs however, with this example we are changing the frequency at which they flash by using the two buttons. This method uses polling. More on polling can be found on [Wikipedia](https://en.wikipedia.org/wiki/Polling_(computer_science)).

This introduces a new port register that will be used: `PxIN`.
- [x] Started
- [x] Coded
- [ ] Verified

### 3.) buttonsLED.c (unverified)
This is the exact same as Example 2 : buttonsLEDPolling.c except the method on how it is triggered changed. Now the use of interrupts and globals.
- [x] Started
- [x] Coded
- [ ] Verified

### 4.) timersLED.c (not started)
Very similar to buttonsLED.c. However, instead of using __delay_cycles, timers will be setup and used. This is to serve as an introduction on how to use timers.
- [ ] Started
- [ ] Coded
- [ ] Verified

### 5.) moreTimers.c (not started)
This program goes a bit more in depth into timers and how to use them to their full potential.
- [ ] Started
- [ ] Coded
- [ ] Verified
