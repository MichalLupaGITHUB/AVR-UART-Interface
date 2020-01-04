#include <avr\io.h>
#include "RS.h"

int rs_put(char znak)
{
	// Oczekiwanie az bufor nadajnika bedzie pusty
	while(!(1<<UDRE0 & UCSR0A)) {} // pusta petla
	// UCSR0A -> rejestr statusowy -> sprawdzenie czy w rejestrze UCSR0A bit UDRE0 (1 gdy rejestr pusty) jest jedynka
	UDR0 = znak; // UDR -> rejestr danych
	return 0;
}

int rs_get(void)
{
	char znak;
	
	// Oczekiwanie na pojawienie sie danej w sieci
	while(!(1<<RXC0 & UCSR0A)) {} // pusta petla
	// UCSR0A -> rejestr statusowy -> sprawdzenie czy w rejestrze UCSR0A bit RXC0 (1 gdy odbieranie zakonczone) jest jedynka
	znak = UDR0; // UDR -> rejestr danych
	return znak;
}