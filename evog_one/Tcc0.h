/* 
* Tcc0.h
*/

#ifndef __TCC0_H__
#define __TCC0_H__

#include "Tcc.h"
#include "Utils.h"

class Tcc0
{		
public:
	static volatile double time_s;
	static volatile double timeIncrement_s;
	static volatile bool ovfFlag;
	
	Tcc0(Tcc::clock_s, Utils::interruptLevel_e);
	double getTime_s(){return time_s;};
	bool isOVF(){return ovfFlag;};
	void setOVF(bool b){ovfFlag = b;};
	
}; //Tcc0

#endif //__TCC0_H__
