/* 
* UsartE0.h
*/

#ifndef __USARTE0_H__
#define __USARTE0_H__

#include "Usart.h"
#include "Utils.h"

class UsartE0
{	
public:	
	UsartE0(Usart::baudrate_s,
			Utils::interruptLevel_e,
			Utils::interruptLevel_e,
			Utils::interruptLevel_e);
			
	char getChar();
	void sendChar(char);
	void sendString(const char* str);
	
	static volatile bool rxcFlag;
	static volatile bool txcFlag;
	static volatile bool dreFlag;
	
	bool isRXC(){return rxcFlag;};
	bool isTXC(){return txcFlag;};
	bool isDRE(){return dreFlag;};
	
	void setRXC(bool b){rxcFlag = b;};
	void setTXC(bool b){txcFlag = b;};
	void setDRE(bool b){dreFlag = b;};
};

#endif //__USARTE0_H__
