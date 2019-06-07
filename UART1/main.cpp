/*
 * main.cpp
 *
 *  Created on: 17/04/2019
 *      Author: aluno
 */
#include "UART.h";
#include <util/delay.h>

int main() {

	UART uart(9600, UART::DATABITS_8, UART::NONE, UART::STOPBIT_2);


	int i = 0;

	while(true) {
		uart.put(i);

		_delay_ms(500);

		i++;

	}



}
