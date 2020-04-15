/*	Author: Bhagpreet Brar bbrar 002
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab # 2 Exercise # 3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0x07;
	DDRB = 0x00; PORTB = 0x0B;
	DDRC = 0x00; PORTC = 0x0A;
	DDRD = 0xFF; PORTD = 0x00;
	
	
	
	unsigned char a = 0x00;
	unsigned char b = 0x00;
	unsigned char c = 0x00;
	unsigned char d = 0x00;
	unsigned char tot = 0x00;
	
    while(1) {
	    a = PINA;
	    b = PINB;
	    c = PINC;
	    tot = a + b + c;

	    if (tot > 0x8C){
		d = 0x0;
	    } 
	    if (abs(a - c) > 0x50){
		d = d | 0x02;
	    }
	    PORTD = tot | d;
	    d = 0;
    }
}
