# MSP430Examples
Examples of code to run on MSP430FR2355 LaunchPad boards.

## 1.) blinkingLED.c (unverified)
This code is created to be used on a LaunchPad board but can be easily modified to work on other hardware. This is a simple start to micro-contoller programming. It will flash LED1 at a rate of 2Hz (or half a second intervals).
- [x] Started
- [x] Coded
- [ ] Verified

## 2.) buttonsLEDPolling.c (unverified)
Very similar to the first bit of code as in we are flashing LEDs however, with this example we are changing the frequency at which they flash by using the two buttons. This method uses polling.
- [x] Started
- [x] Coded
- [ ] Verified

## 3.) buttonsLED.c (unverified)
This is the exact same as Example 2 : buttonsLEDPolling.c except the method on how it is triggered changed. Now the use of interrupts and globals.
- [x] Started
- [x] Coded
- [ ] Verified

## 4.) timersLED.c (not started)
Very similar to buttonsLED.c. However, instead of using __delay_cycles, timers will be setup and used. This is to serve as an introduction on how to use timers.
- [ ] Started
- [ ] Coded
- [ ] Verified

## 5.) moreTimers.c (not started)
This program goes a bit more in depth into timers and how to use them to their full potential.
- [ ] Started
- [ ] Coded
- [ ] Verified
