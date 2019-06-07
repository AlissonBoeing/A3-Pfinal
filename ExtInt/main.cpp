#include <avr/interrupt.h>
#include "ExtInt.h"
#include "UART2.h"
#include "GPIO.h"
#include <util/delay.h>

//using namespace ExtInt;

UART2 uart(19200, UART2::DATABITS_8, UART2::NONE, UART2::STOPBIT_1);

void int0_handler(void){
	uart.put('0');
	return;
}

void int1_handler(void){
	uart.put('1');
	return;
}

void int2_handler(void){
	uart.put('2');
	return;
}

void int3_handler(void){
	uart.put('3');
	return;
}

void int4_handler(void){
	uart.put('4');
	return;
}

void int5_handler(void){
	uart.put('5');
	return;
}

void int6_handler(void){
	uart.put('6');
	return;
}

void int7_handler(void){
	uart.put('7');
	return;
}

int main( void ){

	//GPIO p9(9, GPIO::OUTPUT);


	ExtInt int0_obj(ExtInt::INT_0, ExtInt::FALLING, &int0_handler);
	ExtInt int1_obj(ExtInt::INT_1, ExtInt::FALLING, &int1_handler);
	ExtInt int2_obj(ExtInt::INT_2, ExtInt::FALLING, &int2_handler);
	ExtInt int3_obj(ExtInt::INT_3, ExtInt::FALLING, &int3_handler);
	ExtInt int4_obj(ExtInt::INT_4, ExtInt::FALLING, &int4_handler);
	ExtInt int5_obj(ExtInt::INT_5, ExtInt::FALLING, &int5_handler);
	ExtInt int6_obj(ExtInt::INT_6, ExtInt::FALLING, &int6_handler);
	ExtInt int7_obj(ExtInt::INT_7, ExtInt::FALLING, &int7_handler);

	int0_obj.enable();
	int1_obj.enable();
	int2_obj.enable();
	int3_obj.enable();
	int4_obj.enable();
	int5_obj.enable();
	int6_obj.enable();
	int7_obj.enable();

	sei();

	while(1){                                   /* forever */

		//p9.set(1);

		//_delay_ms(500);

		//p9.set(0);



		if (uart.has_data()){
			uart.put(uart.get());                 /* echo the received character */
			uart.put((EICRA));
		}


	}

	return 0;
}
