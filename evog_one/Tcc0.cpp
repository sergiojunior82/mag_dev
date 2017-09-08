/* 
* Tcc0.cpp
*/

#include <avr/interrupt.h>
#include <avr/io.h>
#include "Tcc0.h"

//==================//
//=== INTERRUPTS ===//
//==================//

volatile double Tcc0::time_s = 0;
volatile double Tcc0::timeIncrement_s = 0;
volatile bool Tcc0::ovfFlag = false;

ISR(TCC0_OVF_vect)
{
	Tcc0::time_s += Tcc0::timeIncrement_s;
	Tcc0::ovfFlag = true;
}

//===================//
//=== CONSTRUCTOR ===//
//===================//

Tcc0::Tcc0(Tcc::clock_s c, Utils::interruptLevel_e ovfil)
{
	TCC0_CTRLA = c.clock;
	timeIncrement_s = c.ti;
	TCC0_INTCTRLA |= (ovfil << TC0_OVFINTLVL_gp);
}

