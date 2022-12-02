#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "MKUART/mkuart.h"

#define VREF 2.56 // zdefiniowane napi�cie referencyjne
#define ADCIN PA1 // zdefiniowane wej�cie ADC, u mnie bedzie PA1


volatile double adc; // zmienna do oblicze� napi�cia
volatile int workint1,
			t,
			s,
			d,
			j;

volatile double workint;
short int pomiar(int kanal);

int main(void) // g��wna funkcja programu
	{

	workint=0;
	adc=0;

	USART_Init( __UBRR );

	sei();

	//wyb�r napi�cia odniesienia i kana�u pomiarowego//
	ADMUX |= (1<<REFS0)|(1<<REFS1)|(1<<MUX0);
	// w��czenie modu�u ADC i ustawieie preskalera na 128
	ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

	OSCCAL=160;

	while(1)
		{

		adc=pomiar(1)*VREF/1024*6,25; // przeliczanie warto�ci na napi�cie, pomiar(1)*1024/Vref
		// funkcja formatuj�ca typ zmiennych float na �a�cuch znakowy

		workint=(adc*1000);

		workint1=(int)((workint))*0.9;

		t=workint1/1000;

		s=((workint1-t*1000)/100);

		d=((workint1-t*1000-s*100)/10);

		j=((workint1-t*1000-s*100-d*10)/1);

		uart_puts("Napiecie[V]: ");
		uart_putint(t, 10);
		uart_puts(".");
		uart_putint(s, 10);
		uart_putint(d, 10);


		uart_puts(" ");
		t=0;
		s=0;
		d=0;
		j=0;
		_delay_ms(2000);
		}
	}


short int pomiar(int kanal)
{
// ustawienie wybranego wej�cia ADC w rejestrze ADMUX
ADMUX = (ADMUX & 0xF8)|kanal;
// rozpocz�cie pomiaru przez ustawienie bitu ADSC w rejestrze ADCSRA
ADCSRA |= (1<<ADSC);
//oczekiwanie na koniec pomiaru
while( ADCSRA & (1<<ADSC) );
// zwr�cenie wyniku z rejestr�w ADCH/ADCL
return ADCW;
}


