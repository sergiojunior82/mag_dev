/* 
* Tcc.h
*/

#ifndef __TCC_H__
#define __TCC_H__

class Tcc
{
public:
	enum clock_e {
		OFF = 0,
		DIV1 = 1,
		DIV2 = 2,
		DIV4 = 3,
		DIV8 = 4,
		DIV64 = 5,
		DIV256 = 6,
		DIV1024 = 7,
		EVCH0 = 8,
		EVCH1 = 9,
		EVCH2 = 10,
		EVCH3 = 11,
		EVCH4 = 12,
		EVCH5 = 13,
		EVCH6 = 14,
		EVCH7 = 15
	};
	
	
	struct clock_s
	{
		clock_e clock;
		double ti;
	};
	
	static const clock_s CLOCK_OFF;
	static const clock_s CLOCK_DIV1;
	static const clock_s CLOCK_DIV2;
	static const clock_s CLOCK_DIV4;
	static const clock_s CLOCK_DIV8;
	static const clock_s CLOCK_DIV64;
	static const clock_s CLOCK_DIV256;
	static const clock_s CLOCK_DIV1024;
	static const clock_s CLOCK_EVCH0;
	static const clock_s CLOCK_EVCH1;
	static const clock_s CLOCK_EVCH2;
	static const clock_s CLOCK_EVCH3;
	static const clock_s CLOCK_EVCH4;
	static const clock_s CLOCK_EVCH5;
	static const clock_s CLOCK_EVCH6;
	static const clock_s CLOCK_EVCH7;

}; //Tcc

#endif //__TCC_H__
