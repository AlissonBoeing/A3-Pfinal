/*
 * Manager.h
 *
 *  Created on: 31/05/2019
 *      Author: aluno
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "PcINT.h"


class Manager{
public:
	Manager();
	void addPcINT(PcINT::PcINT_ID_t id, CALLBACK_t callback); //adiciona pcint
	void checkEvents(); 				//chega se há eventos
	void disable(PcINT::PcINT_ID_t id); //desabilita pcint
	void enable(PcINT::PcINT_ID_t id); //habilita pcint
	static PcINT _PcINT_vect[24]; 		// vetor de pcints
private:

};




#endif /* MANAGER_H_ */
