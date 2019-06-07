/*
 * main.cpp
 *
 *  Created on: 17/04/2019
 *      Author: aluno
 */
#include "UART2.h"
#include <util/delay.h>

int main() {

	UART2 uart(9600, UART2::DATABITS_8, UART2::NONE, UART2::STOPBIT_2);

	sei();

	int i = 0;

	while(true) {
		if(uart.has_data()) {
			uart.put(uart.get());
		}
		_delay_ms(500);
		i++;

	}



}
