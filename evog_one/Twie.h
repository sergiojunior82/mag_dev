/* 
* Twie.h
*/

#ifndef __TWIE_H__
#define __TWIE_H__

#include "Utils.h"

class Twie
{
public:
	Twie(Utils::interruptLevel_e);
	
	static volatile bool riFlag;
	static volatile bool tiFlag;
	
	char getChar();
	void sendChar(char);
	//void sendString(const char* str);
	void setAddr(uint8_t addr);
};

#endif //__TWIE_H__
