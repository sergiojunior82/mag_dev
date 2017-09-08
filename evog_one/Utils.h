/* 
* Utils.h
*/

#ifndef __UTILS_H__
#define __UTILS_H__

class Utils
{
public:
	enum systemClock_e
	{
		SC_2M = 0,
		SC_32M = 1,
		SC_32k768 = 2,
		SC_XOSC = 3,
		SC_PLL = 4
	};
	
	enum interruptLevel_e
	{
		OFF = 0,
		LOW = 1,
		MEDIUM = 2,
		HIGH = 3
	};
	
	static void setSystemClock(systemClock_e);
	static void enableInterruptLevel(interruptLevel_e);
	static void globalInterruptEnable();
}; //Utils

#endif //__UTILS_H__
