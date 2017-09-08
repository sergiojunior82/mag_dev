/* 
* UsartE0.cpp
*/

#include <avr/interrupt.h>
#include <avr/io.h>
#include "UsartE0.h"

//==================//
//=== INTERRUPTS ===//
//==================//

volatile bool UsartE0::rxcFlag = false;
volatile bool UsartE0::txcFlag = false;
volatile bool UsartE0::dreFlag = false;

ISR(USARTE0_RXC_vect) {UsartE0::rxcFlag = true;}
ISR(USARTE0_TXC_vect) {UsartE0::txcFlag = true;}
ISR(USARTE0_DRE_vect) {UsartE0::dreFlag = true;}

//===================//
//=== CONSTRUCTOR ===//
//===================//

UsartE0::UsartE0(	Usart::baudrate_s baudrate,
					Utils::interruptLevel_e rxcil,
					Utils::interruptLevel_e txcil,
					Utils::interruptLevel_e dreil)
{
	USARTE0_BAUDCTRLA = baudrate.bsel << USART_BSEL_gp;
	USARTE0_BAUDCTRLB = baudrate.bscale << USART_BSCALE_gp;
	if (baudrate.clk2x) USARTE0_CTRLB |= USART_CLK2X_bm;
	USARTE0_CTRLB |= USART_RXEN_bm|USART_TXEN_bm;
	USARTE0_CTRLA = (rxcil << USART_RXCINTLVL_gp)|(txcil << USART_TXCINTLVL_gp)|(dreil << USART_DREINTLVL_gp);
	PORTE_DIRSET = PIN3_bm;
}

//=================//
//=== FUNCTIONS ===//
//=================//

char UsartE0::getChar()
{
	return USARTE0_DATA;
}

void UsartE0::sendChar(char c)
{
	while (!(USARTE0_STATUS & USART_DREIF_bm)) ;
	USARTE0_DATA = c;
}

void UsartE0::sendString(const char* str)
{
	int i = 0;
	while (str[i] != '\0') sendChar(str[i++]);
}