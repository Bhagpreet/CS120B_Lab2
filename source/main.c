/*	Author: Bhagpreet Brar bbrar 002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab # 2 Exercise # 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char cntavail = 0x00;
	unsigned char spot1 = 0x00;
	unsigned char spot2 = 0x00;
	unsigned char spot3 = 0x00;
	unsigned char spot4 = 0x00;
	
    while(1)
    {
		spot1 = PINA & 0x01;
		spot2 = (PINA & 0x02) >> 1;
		spot3 = (PINA & 0x04) >> 2;
		spot4 = (PINA & 0x08) >> 3;
		
		cntavail = spot1 + spot2 + spot3 + spot4; // counts the spots that are occupied	
		cntavail = 0x04 - cntavail; // subtract to get number of spots available	
		PORTC = cntavail;
    }
}
