/*
 * DTMF.cpp
 *
 *  Created on: 1 de jul de 2019
 *      Author: yan
 */

#include "DTMF.h"
#include "GPIO.h"
#include <util/delay.h>

DTMF::DTMF(GPIO * c1, GPIO * c2, GPIO * c3, GPIO * c4, GPIO * l1, GPIO * l2, GPIO * l3, GPIO * l4){
	this->c1 = c1;
	this->c2 = c2;
	this->c3 = c3;
	this->c4 = c4;

	this->l1 = l1;
	this->l2 = l2;
	this->l3 = l3;
	this->l4 = l4;

	this->c1->set(true);
	this->c2->set(true);
	this->c3->set(true);
	this->c4->set(true);

	this->l1->set(true);
	this->l2->set(true);
	this->l3->set(true);
	this->l4->set(true);
}

void DTMF::send(uint8_t digito){
	int delay = 25;
	switch(digito){

		case 0:
			l4->toggle();
			l2->toggle();
			_delay_ms(delay);
			l4->toggle();
			l2->toggle();
			break;

		case 1:
			l1->toggle();
			c1->toggle();
			_delay_ms(delay);
			l1->toggle();
			c1->toggle();
			break;

		case 2:
			l1->toggle();
			c2->toggle();
			_delay_ms(delay);
			l1->toggle();
			c2->toggle();
			break;

		case 3:
			l1->toggle();
			c3->toggle();
			_delay_ms(delay);
			l1->toggle();
			c3->toggle();
			break;

		case 4:
			l2->toggle();
			c1->toggle();
			_delay_ms(delay);
			l2->toggle();
			c1->toggle();
			break;

		case 5:
			l2->toggle();
			c2->toggle();
			_delay_ms(delay);
			l2->toggle();
			c2->toggle();
			break;

		case 6:
			l2->toggle();
			c3->toggle();
			_delay_ms(delay);
			l2->toggle();
			c3->toggle();
			break;

		case 7:
			l3->toggle();
			c1->toggle();
			_delay_ms(delay);
			l3->toggle();
			c1->toggle();
			break;

		case 8:
			l3->toggle();
			c2->toggle();
			_delay_ms(delay);
			l3->toggle();
			c2->toggle();
			break;

		case 9:
			l3->toggle();
			c3->toggle();
			_delay_ms(delay);
			l3->toggle();
			c3->toggle();
			break;

		case '*':
			l4->toggle();
			c1->toggle();
			_delay_ms(delay);
			l4->toggle();
			c1->toggle();
			break;

		case '#':
			l4->toggle();
			c3->toggle();
			_delay_ms(delay);
			l4->toggle();
			c3->toggle();
	}
}


///*
// * DTMF.cpp
// *
// *  Created on: 25 de jun de 2019
// *      Author: paulosell
// */
//
//#include "DTMF.h"
//#include "GPIO.h"
//#include <util/delay.h>
//
//DTMF::DTMF(GPIO * c1, GPIO * c2, GPIO * c3, GPIO * c4, GPIO *l1,
//		GPIO * l2, GPIO * l3, GPIO * l4){
//	colunas[0] = c1;
//	colunas[1] = c2;
//	colunas[2] = c3;
//	colunas[3] = c4;
//
//	linhas[0] = l1;
//	linhas[1] = l2;
//	linhas[2] = l3;
//	linhas[3] = l4;
//
//	for (int i = 0; i < 4; i++){
//		linhas[i]->set(true);
//		colunas[i]->set(true);
//	}
//}
//
//void DTMF::send_dtmf(uint8_t digito){
//	int delay = 25;
//	switch(digito){
//	case 0:
//		linhas[3]->toggle();
//		colunas[1]->toggle();
//		_delay_ms(delay);
//		linhas[3]->toggle();
//		colunas[1]->toggle();
//		break;
//
//	case 1:
//		linhas[0]->toggle();
//		colunas[0]->toggle();
//		_delay_ms(delay);
//		linhas[0]->toggle();
//		colunas[0]->toggle();
//		break;
//
//	case 2:
//		linhas[0]->toggle();
//		colunas[1]->toggle();
//		_delay_ms(delay);
//		linhas[0]->toggle();
//		colunas[1]->toggle();
//		break;
//
//	case 3:
//		linhas[0]->toggle();
//		colunas[2]->toggle();
//		_delay_ms(delay);
//		linhas[0]->toggle();
//		colunas[2]->toggle();
//		break;
//
//	case 4:
//		linhas[1]->toggle();
//		colunas[0]->toggle();
//		_delay_ms(delay);
//		linhas[1]->toggle();
//		colunas[0]->toggle();
//		break;
//	case 5:
//		linhas[1]->toggle();
//		colunas[1]->toggle();
//		_delay_ms(delay);
//		linhas[1]->toggle();
//		colunas[1]->toggle();
//		break;
//
//	case 6:
//		linhas[1]->toggle();
//		colunas[2]->toggle();
//		_delay_ms(delay);
//		linhas[1]->toggle();
//		colunas[2]->toggle();
//		break;
//
//	case 7:
//		linhas[2]->toggle();
//		colunas[0]->toggle();
//		_delay_ms(delay);
//		linhas[2]->toggle();
//		colunas[0]->toggle();
//		break;
//
//	case 8:
//		linhas[2]->toggle();
//		colunas[1]->toggle();
//		_delay_ms(delay);
//		linhas[2]->toggle();
//		colunas[1]->toggle();
//		break;
//
//	case 9:
//		linhas[2]->toggle();
//		colunas[2]->toggle();
//		_delay_ms(delay);
//		linhas[2]->toggle();
//		colunas[2]->toggle();
//		break;
//
//	case 10:
//		linhas[3]->toggle();
//		colunas[0]->toggle();
//		_delay_ms(delay);
//		linhas[3]->toggle();
//		colunas[0]->toggle();
//		break;
//
//	case 11:
//		linhas[3]->toggle();
//		colunas[2]->toggle();
//		_delay_ms(delay);
//		linhas[3]->toggle();
//		colunas[2]->toggle();
//		break;
//	}
//
//
//
//}


