/*
 * UART.h
 *
 *  Created on: 17/04/2019
 *      Author: aluno
 */
#include <avr/io.h>
#ifndef UART_H_
#define UART_H_


class UART {
public:

	enum DATABITS_t {
		DATABITS_5 = 0,
		DATABITS_6 = 2,
		DATABITS_7 = 4,
		DATABITS_8 = 6
	};

	enum PARITY_t {
			NONE = 0,
			EVEN = 32,
			ODD = 48
		};

	enum STOPBITS_t {
			STOPBIT_1 = 0,
			STOPBIT_2 = 8
		};

	UART(uint32_t baud, UART::DATABITS_t db, UART::PARITY_t parity, UART::STOPBITS_t sb);
	~UART();
	void put(uint8_t data);
	void puts(const char * data);
	uint8_t get();



private:


};


#endif /* UART_H_ */
