/*
 * GccApplication1.c
 *
 * Created: 2/11/2022 11:02:51 PM
 * Author : Jared
 */ 
#define F_CPU 16000000UL
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
//#include "uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>





void ini(){
	cli();  // Disable Global Interrupts


	DDRB |= (1<<DDB1); // output pin
	DDRB |= (1<<DDB2); // output pin
	
	DDRB |=(1<<DDB5);
	
	DDRB &= ~(1<<DDB0); // input pin

	TCCR1B |= (1<<CS10); //SETTING THE TIMER
	TCCR1B &= ~(1<<CS11);
	TCCR1B &= ~(1<<CS12);

	TCCR1A &= ~(1<<WGM10);
	TCCR1A &= ~(1<<WGM11);
	TCCR1B &= ~(1<<WGM12);
	TCCR1B &= ~(1<<WGM13);


	//LOOKING FOR RISING EDGE
	TCCR1B |= (1<<ICES1);


	//CLEAR INTERUPT FLAG
	TIFR1 |= (1<<ICF1);

	//ENABLE INPUT CAPTURE

	TIMSK1 |= (1<<ICIE1);
	TIMSK1 |= (1<<TOIE1);

	

	sei(); // Enable Global Interrupts

	
}



ISR(TIMER1_CAPT_vect){

}

ISR(TIMER1_OVF_vect){ 
	TCNT1 = 47354;
	
	
	PORTB ^= (1<<PORTB1);}


int main (void)
{
	ini();

	while(1){

	}
	

}
