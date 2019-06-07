
#include <avr/io.h>
#include <avr/interrupt.h>
#ifndef UART2_H_
#define UART2_H_


class UART2 {
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

	UART2(uint32_t baud, UART2::DATABITS_t db, UART2::PARITY_t parity, UART2::STOPBITS_t sb);
	~UART2();
	void put(uint8_t data);
	void puts(const char * data);
	uint8_t get();
	bool has_data();
	static void rxc_isr_handler();
	static void tx_isr_handler();

private:

	static bool _has_data;
	static uint8_t _rx_buffer;
	static uint8_t _tx_buffer;

};


#endif /* UART2_H_ */
