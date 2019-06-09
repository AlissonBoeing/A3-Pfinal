/*
 * ExtInt.cpp
 *
 *  Created on: 03/05/2019
 *      Author: aluno
 */

#include <avr/io.h>
#include "ExtInt.h"

ExtInt * ExtInt::_ExtInt_singletons[8];

uint8_t mask;

ExtInt::ExtInt(INT_ID_t id, ISC_t cfg, CALLBACK_t callback){

	_id = id;

	mask = (_id % 4) << 1;
	disable();

	if(_id<4) {
		EICRA = (EICRA&~(3<<mask)) | (cfg << mask);
	} else {
		EICRB = (EICRB&~(3<<mask)) | (cfg << mask);
	}

	_pCallback = callback;

	_ExtInt_singletons[_id] = this;

}

void ExtInt::enable(){
	EIMSK |= (1 << _id);
}

void ExtInt::disable(){
	EIMSK &= ~(1 << _id);
}

ISR(INT0_vect){
	ExtInt::_ExtInt_singletons[0]->callback();
}

ISR(INT1_vect){
	ExtInt::_ExtInt_singletons[1]->callback();
}

ISR(INT2_vect){
	ExtInt::_ExtInt_singletons[2]->callback();
}

ISR(INT3_vect){
	ExtInt::_ExtInt_singletons[2]->callback();
}

ISR(INT4_vect){
	ExtInt::_ExtInt_singletons[4]->callback();
}

ISR(INT5_vect){
	ExtInt::_ExtInt_singletons[5]->callback();
}

ISR(INT6_vect){
	ExtInt::_ExtInt_singletons[6]->callback();
}

ISR(INT7_vect){
	ExtInt::_ExtInt_singletons[7]->callback();
}









