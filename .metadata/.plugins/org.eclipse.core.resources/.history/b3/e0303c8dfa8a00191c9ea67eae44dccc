/*
 * main.cpp
 *
 *  Created on: 31/05/2019
 *      Author: aluno
 */

#include <avr/interrupt.h>
#include "GPIO.h"
#include "Manager.h"

GPIO led13(13, GPIO::OUTPUT);
GPIO pin1(11, GPIO::INPUT);


Manager controladora;
void handler(void){
	led13.toggle();

}

int main( void ){

	controladora.addPcINT(PcINT::PcINT_5, &handler);

	sei();

	while(1){                                   /* forever */
		controladora.checkEvents();
	}

	return 0;
}



