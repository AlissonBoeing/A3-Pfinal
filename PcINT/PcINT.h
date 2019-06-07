/*
 * PcInt.h
 *
 *  Created on: 29/05/2019
 *      Author: aluno
 */

#ifndef PCINT_H_
#define PCINT_H_
#include <stdio.h>

typedef void (*CALLBACK_t)(void);

class PcINT{

public:
	enum PcINT_ID_t{ //enum das pcints do mega2560

		PcINT_0 = 0,
		PcINT_1 = 1,
		PcINT_2 = 2,
		PcINT_3 = 3,
		PcINT_4 = 4,
		PcINT_5 = 5,
		PcINT_6 = 6,
		PcINT_7 = 7,
		PcINT_8 = 8,
		PcINT_9 = 9,
		PcINT_10 = 10,
		PcINT_11 = 11,
		PcINT_12 = 12,
		PcINT_13 = 13,
		PcINT_14 = 14,
		PcINT_15 = 15,
		PcINT_16 = 16,
		PcINT_17 = 17,
		PcINT_18 = 18,
		PcINT_19 = 19,
		PcINT_20 = 20,
		PcINT_21 = 21,
		PcINT_22 = 22,
		PcINT_23 = 23
	};
	PcINT();
	void enable(PcINT_ID_t id); //habilita pcint
	void disable(PcINT_ID_t id); //desabilita pcint
	void callback(){(*_pCallback)();} //similar ao extint
	void setEvent(bool event); 		//
	bool event();
	bool isEnabled();
	void setCallback(CALLBACK_t callback); //
private:
	CALLBACK_t _pCallback;
	bool _event;
	bool _enabled;
};



#endif /* PCINT_H_ */
