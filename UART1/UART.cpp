/*
 *UART GENÉRICA
 */
#include "UART.h"

#define FOSC 16000000

UART::UART(uint32_t baud, UART::DATABITS_t db, UART::PARITY_t parity, UART::STOPBITS_t sb) {

	unsigned int ubrr = (FOSC/16/baud-1);

	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;

	UCSR0B = (1<<RXEN0)|(1<<TXEN0);

	UCSR0C = db | parity | sb;

}
UART::~UART() {}
void UART::put(uint8_t data) {

	//while (!( UCSR0A & (1<<UDRE0))) ;

	UDR0 = data;

}

void UART::puts(const char * data) {

	int i = 0;

	while(data[i] != 0){
		put(data[i]);
		i++;
	}

}

uint8_t UART::get() {

	//while ( !(UCSR0A & (1<<RXC0)));

	return UDR0;
}



