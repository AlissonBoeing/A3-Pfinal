/*
 * PcINT.cpp
 *
 *  Created on: 29/05/2019
 *      Author: aluno
 */

#include  <avr/interrupt.h>
#include  "PcINT.h"

PcINT::PcINT(){
	_pCallback = NULL;
	_event = false;
	_enabled = false;
}

void PcINT::enable(PcINT_ID_t id){
	if (id < 8){
		PCMSK0 |= (1 << id);
	}
	else if (id >=8 and id < 16){
		PCMSK1 |= (1 << (id - 8));
	}
	else if (id >= 16 and id < 24){
		PCMSK2 |= (1 << (id - 16));
	}
	_enabled = true;
}

bool PcINT::isEnabled(){
	return _enabled;
}
void PcINT::disable(PcINT_ID_t id){

	if (id < 8){
		PCMSK0 &= ~(1 << id);
	}
	else if (id >=8 and id < 16){
		PCMSK1 &= ~(1 << (id - 8));
	}
	else if (id >= 16 and id < 24){
		PCMSK2 &= ~(1 << (id - 16));
	}
	_enabled = false;

}

void PcINT::setCallback(CALLBACK_t callback){
	_pCallback = callback;
}
void PcINT::setEvent(bool event){
	_event = event;
}

bool PcINT::event(){
	return _event;
}


