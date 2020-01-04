#include <avr\io.h>
#include <stdio.h>
#include <avr\pgmspace.h>
#include "RS.h"
#include "Harddef.h"

int main(void)
{
	int a = 1234;
	int b = 0xFF;
	
	RS_SET_BAUD(DEF_BAUD); // okreslenie predkosci transmisji
	UCSR0C = 1<<URSEL0 | 1<<UCSZ01 | 1<<UCSZ00; // okreslenie formatu danych (8 bitow) i z ktorego rejestru sie korzysta
	UCSR0B = 1<<RXEN0 | 1<<TXEN0; // ustawienie zapisu i odczytu
	UCSR0A = 0; // wyzerowanie rejestru
	
	fdevopen(rs_put, rs_get); // przekazanie do funkcji biblioteki stdio funkcji odczytujacych i zapisujacych
	
	printf_P(PSTR("a(%%d)=%d\r\n"
			"a(%%x)=%x\r\n"
			"a(%%X)=%X\r\n"
			"b(%%#x)=%#x\r\n"
			"b(%%o)=%o\r\n"),
			a, a, a, b, b);
}