/*
 * UART COM INTERRUPÇÃO INTERNA
 */
#include "UART2.h"

#define FOSC 16000000

bool UART2::_has_data = false;
uint8_t UART2::_rx_buffer = 0;
uint8_t UART2::_tx_buffer = 0;

UART2::UART2(uint32_t baud, UART2::DATABITS_t db, UART2::PARITY_t parity, UART2::STOPBITS_t sb) {

	unsigned int ubrr = (FOSC/16/baud-1);

	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;

	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	UCSR0A = (1<<RXC0);

	UCSR0C = db | parity | sb;



}

void UART2::put(uint8_t data) {
	_tx_buffer = data;
	UCSR0B |= (1<<UDRIE0);
}

void UART2::puts(const char * data) {

	int i = 0;

	while(data[i] != 0){
		put(data[i]);
		i++;
	}

}

uint8_t UART2::get() {
	_has_data = false;
	return _rx_buffer;
}

bool UART2::has_data(){

	return _has_data == true;

}

UART2::~UART2(){}

void UART2::rxc_isr_handler() {
	_rx_buffer = UDR0;
	_has_data = true;
	//reti();
}
void UART2::tx_isr_handler() {
	UDR0 = _tx_buffer;
	UCSR0B &= ~(1<<UDRIE0);
	//reti();
}

ISR(USART0_RX_vect) {
	UART2::rxc_isr_handler();
}

ISR(USART0_UDRE_vect) {
	UART2::tx_isr_handler();
}



