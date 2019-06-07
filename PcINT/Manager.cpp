/*
 * Manager.cpp
 *
 *  Created on: 31/05/2019
 *      Author: aluno
 */

#include <stdio.h>
#include <avr/interrupt.h>
#include "Manager.h"
#include <avr/io.h>
#include <util/delay.h>

PcINT Manager::_PcINT_vect[24];


Manager::Manager(){
	UCSR0B = 0;
	PCICR |= 1<<PCIE0;
	PCICR |= 1<<PCIE1;
	PCICR |= 1<<PCIE2;
	for (int i = 0; i < 24; i++){
		PcINT p;
		_PcINT_vect[i] = p;
		_PcINT_vect[i].setEvent(false);

	}
}

void Manager::addPcINT(PcINT::PcINT_ID_t id, CALLBACK_t callback){
	_PcINT_vect[id].setCallback(callback);
	_PcINT_vect[id].enable(id);
}

void Manager::disable(PcINT::PcINT_ID_t id){
	_PcINT_vect[id].disable(id);
}


void Manager::enable(PcINT::PcINT_ID_t id){
	_PcINT_vect[id].enable(id);
}

void Manager::checkEvents(){
	for (int i = 0; i < 24; i++){
		if (_PcINT_vect[i].event()){
			_PcINT_vect[i].callback();
			_PcINT_vect[i].setEvent(false);
		}
	}
}

ISR(PCINT0_vect)
{
	if (Manager::_PcINT_vect[0].isEnabled()){
		if (PINB & (1 << 0)){
			Manager::_PcINT_vect[0].setEvent(true);
		}
	}

	if (Manager::_PcINT_vect[1].isEnabled()){
		if(PINB & (1 << 1)){
			Manager::_PcINT_vect[1].setEvent(true);
		}
	}

	if (Manager::_PcINT_vect[2].isEnabled()){
		if (PINB & (1 << 2)){
			Manager::_PcINT_vect[2].setEvent(true);;
		 }
	}

	if (Manager::_PcINT_vect[3].isEnabled()){
		if (PINB & (1 << 3)){
			Manager::_PcINT_vect[3].setEvent(true);
		}
	}
	if (Manager::_PcINT_vect[4].isEnabled()){
		if (PINB & (1 << 4)){
			Manager::_PcINT_vect[4].setEvent(true);
		}
	}

	if (Manager::_PcINT_vect[5].isEnabled()){
		if (PINB & (1 << 5)){
			Manager::_PcINT_vect[5].setEvent(true);
		}
	}

	if (Manager::_PcINT_vect[6].isEnabled()){
		if (PINB & (1 << 6)){
			Manager::_PcINT_vect[6].setEvent(true);
		}
	}

	if (Manager::_PcINT_vect[7].isEnabled()){
		if (PINB & (1 << 7)){
			Manager::_PcINT_vect[7].setEvent(true);
		}
	}
	_delay_ms(100);
}

ISR(PCINT1_vect)
{
	if(Manager::_PcINT_vect[8].isEnabled()){
		if (PINE & (1 << 0)){
			Manager::_PcINT_vect[8].setEvent(true);
		}
	}

	if (Manager::_PcINT_vect[9].isEnabled()){
		if (PINJ & (1 << 0)){
			Manager::_PcINT_vect[9].setEvent(true);
		}
	}

	if (Manager::_PcINT_vect[10].isEnabled()){
		if (PINJ & (1 << 1)){
			Manager::_PcINT_vect[10].setEvent(true);
		}
	}

	if (Manager::_PcINT_vect[11].isEnabled()){
		if (PINJ & (1 << 2)){
			Manager::_PcINT_vect[11].setEvent(true);
		}
	}

	if(Manager::_PcINT_vect[12].isEnabled()){
		if (PINJ & (1 << 3)){
			Manager::_PcINT_vect[12].setEvent(true);
		}
	}

	if (Manager::_PcINT_vect[13].isEnabled()){
		if (PINJ & (1 << 4)){
			Manager::_PcINT_vect[13].setEvent(true);
		}
	}

	if (Manager::_PcINT_vect[14].isEnabled()){
		if (PINJ & (1 << 5)){
			Manager::_PcINT_vect[14].setEvent(true);
		}
	}

	if(Manager::_PcINT_vect[15].isEnabled()){
		if (PINJ & (1 << 6)){
			Manager::_PcINT_vect[15].setEvent(true);
		}
	}
	_delay_ms(100);
}


ISR(PCINT2_vect)
{
	if(Manager::_PcINT_vect[16].isEnabled()){
		if (PINK & (1 << 0)){
			Manager::_PcINT_vect[16].setEvent(true);
		}
	}

	if(Manager::_PcINT_vect[17].isEnabled()){
		if (PINK & (1 << 1)){
			Manager::_PcINT_vect[17].setEvent(true);
		}
	}

	if(Manager::_PcINT_vect[18].isEnabled()){
		if (PINK & (1 << 2)){
			Manager::_PcINT_vect[18].setEvent(true);
		}
	}

	if(Manager::_PcINT_vect[19].isEnabled()){
		if (PINK & (1 << 3)){
			Manager::_PcINT_vect[19].setEvent(true);
		}
	}

	if(Manager::_PcINT_vect[20].isEnabled()){
		if (PINK & (1 << 4)){
			Manager::_PcINT_vect[20].setEvent(true);
		}
	}

	if(Manager::_PcINT_vect[21].isEnabled()){
		if (PINK & (1 << 5)){
			Manager::_PcINT_vect[21].setEvent(true);
		}
	}

	if(Manager::_PcINT_vect[22].isEnabled()){
		if (PINK & (1 << 6)){
			Manager::_PcINT_vect[22].setEvent(true);
		}
	}

	if(Manager::_PcINT_vect[23].isEnabled()){
		if (PINK & (1 << 7)){
			Manager::_PcINT_vect[23].setEvent(true);
		}
	}
}
