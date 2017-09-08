/* 
* Utils.cpp
*/

#include <avr/io.h>
#include "Utils.h"

// enable oscillators and select system clock
void Utils::setSystemClock(systemClock_e sc)
{
	OSC_CTRL |= 1 << sc; // enable oscillator
	while (!(OSC_STATUS & (1 << sc))) ; // wait until oscillator is ready
	CCP = CCP_IOREG_gc; // trigger protection mechanism
	CLK_CTRL = sc << CLK_SCLKSEL_gp; // select system clock
}

void Utils::enableInterruptLevel(interruptLevel_e il)
{
	PMIC_CTRL |= (1 << (il-1));
}

void Utils::globalInterruptEnable()
{
	CPU_SREG |= CPU_I_bm;
}