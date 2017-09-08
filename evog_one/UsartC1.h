/* 
* UsartC1.h
*/

#ifndef __USARTC1_H__
#define __USARTC1_H__

#include "Usart.h"
#include "Utils.h"

class UsartC1
{
public:
	UsartC1(Usart::baudrate_s,
			Utils::interruptLevel_e,
			Utils::interruptLevel_e,
			Utils::interruptLevel_e);
			
	char getChar();
	void sendChar(char);
	void sendString(const char* str);
	
	static volatile bool rxcFlag;
	static volatile bool txcFlag;
	static volatile bool dreFlag;
};

#endif //__USARTC1_H__
