/* 
* Twie.cpp
*/

#include <avr/interrupt.h>
#include <avr/io.h>
#include "Twie.h"

//==================//
//=== INTERRUPTS ===//
//==================//

volatile bool Twie::riFlag = false;
volatile bool Twie::tiFlag = false;

//===================//
//=== CONSTRUCTOR ===//
//===================//

Twie::Twie(Utils::interruptLevel_e il)
{
	TWIE_MASTER_BAUD = 155; // 100 kHz
	//TWIE_MASTER_CTRLA |= (il << TWI_MASTER_INTLVL_gp)|(TWI_MASTER_RIEN_bm)|(TWI_MASTER_WIEN_bm)|(TWI_MASTER_ENABLE_bm);
	TWIE_MASTER_CTRLA |= TWI_MASTER_ENABLE_bm;
}

char Twie::getChar()
{
	return TWIE_MASTER_DATA;
}

void Twie::sendChar(char c)
{
	TWIE_MASTER_DATA = c;
}

/*
void Twie::sendString(const char* str)
{
}*/

void Twie::setAddr(uint8_t addr)
{
	TWIE_MASTER_ADDR = addr;
}

