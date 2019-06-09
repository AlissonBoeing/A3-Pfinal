#include <avr/io.h>
#include <avr/interrupt.h>
#include "GPIO.h"
#include "Timer.h"


GPIO p13(13, GPIO::OUTPUT);
GPIO p5(5, GPIO::OUTPUT);
GPIO p11(11, GPIO::OUTPUT);
void timeout_handler(void){
	p13.toggle();
}

void timeout2_handler(void){
	p5.toggle();
}

void timeout3_handler(void){
	p11.toggle();
}

Timeout timeout(1000, &timeout_handler);
Timeout timeout2(2000, &timeout2_handler);
Timeout timeout3(1000, &timeout3_handler);

Timer t = Timer(1000);



int main(){

	sei();

	timeout2.enableTimeout();
	timeout3.enableTimeout();
	t.addTimeout(&timeout);
	t.addTimeout(&timeout2);
	t.addTimeout(&timeout3);
	timeout.disableTimeout();
	timeout.enableTimeout();
	while(true){
		t.timeoutManager();

}
}
