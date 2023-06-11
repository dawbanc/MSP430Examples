# MSP430Examples Repository

Examples of code to run on MSP430 LaunchPad boards. These boards can be purchased directly from [Texas Instruments](https://www.ti.com/microcontrollers-mcus-processors/msp430-microcontrollers/overview.html) (but can also be found at other retailers such as Digikey, Mouser, etc.). Below each example description is the status of that example. As these are added and tested they will be updated. 

## Usage

This repository is to serve as a manual on how to do things on an MSP430FR2355. This includes everything from how to control pins to how modules work. It is designed to teach ANYONE on how to use these microcontrollers, but are good to review (at least for me when I forget on how to do something very specific with communication modules). While more and more examples may be added in the future, each one should have a thorough explanation on what that example teaches both on this page and within the comments of the code. If you are new to this type of thing, it might be a good idea to read through the code, take notes on some of the major things and try to code it yourself.

## Current Devices

- MSP430FR2355 LaunchPad Development Board
- Coming soon: MSP430FR5994 LaunchPad Development Board

# Programming the boards

The boards use a USB to connect to your computer. To program the boards, there are a few different options. If you want to use an IDE and have a built in compiler and programmer as well as a debug feature, I reccommend using [Texas Instruments CCS](https://www.ti.com/tool/CCSTUDIO). This is availible for Windows, macOS, and Linux. If you want something a little more light weight and want to compile with gcc, you can use the open-source [MSP430-GCC](https://www.ti.com/tool/MSP430-GCC-OPENSOURCE) and a programmer of your chose (either on from Texas Instruments ie: MSP430-Flasher, Uniflash, etc or if your on Linux on a weird architecture *such as a M1 Macbook on ARM*, you can use mspdebug).

# MSP430FR2355 LaunchPad Development Board

## Example Descriptions
### 1.) blinkingLED.c (unverified)
This code is created to be used on a LaunchPad board but can be easily modified to work on other hardware. This is a simple start to micro-contoller programming. It will flash LED1 at a rate of 2Hz (or half a second intervals). 

This content can be very dry, especially in the first little bit of learning. However, the knowledge in this first example is crucial for everything in the future. This example shows some bitwise operations that are commonly used on the MSP430 along with the general outline on how C code works on the MSP430 microcontroller. 

To turn on and off pins, the `PxDIR` and `PxOUT` registers will be changed. 
To change those individual bits the OR `|`, AND `&`, and XOR `^` bitwise operations are used. 
Make sure that the watchdog timer is stopped using `WDTCLT = WDTPW | WDTHOLD;` and that the GPIO is turned on using `PM5CTL0 &= ~LOCKLPM5;` as these are commonly forgotten when starting a new project.

- [x] Started
- [x] Coded
- [x] Verified

### 2.) buttonsLEDPolling.c (unverified)
Very similar to the first bit of code as in we are flashing LEDs however, with this example we are changing the frequency at which they flash by using the two buttons. This method uses polling. More on polling can be found on [Wikipedia](https://en.wikipedia.org/wiki/Polling_(computer_science)).

This introduces a new port register that will be used: `PxIN`.
- [x] Started
- [x] Coded
- [x] Verified

### 3.) buttonsLED.c (unverified)
This is the exact same as Example 2 : buttonsLEDPolling.c except the method on how it is triggered changed. Now the use of interrupts and globals.

Globals are variables that can be accessed anywhere. Usually we would use a pointer (which will be explained later, more info can be found on [Wikipedia](https://en.wikipedia.org/wiki/Pointer_(computer_programming))) but for now globals will serve the same purpose and be easier to learn and visualize.

Interrupts are used commonly in embedded projects to avoid polling, and allows that microcontroller to work on other tasks while waiting for another process to be triggered to begin. Embedds wrote a really good article to Introduce MSP430 Interrupts here: [Embedds](https://embedds.com/introduction-to-msp430-interrupts/). The interrupt service routines (ISRs) are unlike regular C functions, where we don't need to define the prototype before our main function. 
- [x] Started
- [x] Coded
- [ ] Verified

### 4.) timersLED.c (not started)
Very similar to Example01 blinkingLED.c. However, instead of using __delay_cycles, timers will be setup and used. This is to serve as an introduction on how to setup and use timers. Several timer configuration registers such as *TODO: Add Config Register Examples* will be used.
- [ ] Started
- [ ] Coded
- [ ] Verified

### 5.) moreTimers.c (not started)
This program goes a bit more in depth into timers and how to use them to their full potential. This is quite similar to the Example03buttonsLED.c. Now, our program will act as a Pulse-Width Modulation signal. This means our LED on and off times will no longer be the exact same. The duty cycle is the percentage of ON time over the whole period. This is what we will be changing with the buttons and will make our darker or brighter.
- [ ] Started
- [ ] Coded
- [ ] Verified
