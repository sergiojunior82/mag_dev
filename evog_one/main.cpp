/*
 * evog_one.cpp
 */ 

#include "ComHandler.h"
#include "Tcc0.h"
#include "UsartC1.h"
#include "UsartE0.h"

//============//
//=== MAIN ===//
//============//

int main(void)
{
	Utils::setSystemClock(Utils::SC_32M); // 32MHz internal oscillator
	Tcc0 myTimer0(Tcc::CLOCK_DIV1024, Utils::HIGH); // initialize TCC0
	UsartE0 myUsart0(Usart::BAUD_9k6, Utils::MEDIUM, Utils::OFF, Utils::OFF); // initialize USARTE0
	UsartC1 myUsart1(Usart::BAUD_9k6, Utils::MEDIUM, Utils::OFF, Utils::OFF); // initialize USARTC1

	myUsart0.sendString("Hello World! This is USARTE0!\r"); // debug USARTE0
	myUsart1.sendString("Hello World! This is USARTC1!\r"); // debug USARTC1

	ComHandler myComHandler(&myTimer0, &myUsart0);

	Utils::enableInterruptLevel(Utils::HIGH); // enable high-priority interrupts
	Utils::enableInterruptLevel(Utils::MEDIUM); // enable medium-priority interrupts
	Utils::globalInterruptEnable();			 // enable interrupts globally
		
    while (true)
    {
		// echo USARTE0
		if (myUsart0.isRXC())
		{
			unsigned char b = myUsart0.getChar();
			myUsart0.sendString(myComHandler.handle(b)); // handle received command
			myUsart0.setRXC(false);
		}
		
		// echo USARTC1
		if (UsartC1::rxcFlag)
		{
			myUsart1.sendChar(myUsart1.getChar());
			UsartC1::rxcFlag = false;
		}
		
		if (myTimer0.isOVF())
		{
			myComHandler.update();
			myTimer0.setOVF(false);
		}
	}
}

