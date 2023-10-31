#define F_CPU 16000000

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "Pontos.h"

int i=0, Min=130;

ISR(TIMER0_OVF_vect){							//Interrupção quando há um estouro do timer0.

	TCNT0   = Min;								//Reinicia o timer0.

	PORTD = pgm_read_byte_near(pontos + i);		//Manda o valor da posição i do vetor com o audio para o PORTD.
	
	if(i>30998){				 				//incrementa a posição do vetor com o audio.
		i =  0;
	}
	else{
		i += 1;
	}
}

void main (void){
	SREG |= (1<<7);								//Habilita interruoções globais.
	
	TCCR0A  = 0;								//Configura o timer0 para operação normal, não conectada.
	TCCR0B  = 0;
	
	TCCR0B |= ((1 << CS01)+(1 << CS00));		//Define o prescale como sendo 1/64.

	TCNT0   = Min;								//Inicia o timer0.

	TIMSK0 |= (1<<TOIE0);						//Habilita interrupção por estouro do timer 0.
	
	DDRD = 0xFF;								//Configura o PORTD (pinos 0 ao 7), como saídas.

	while (1){	
	}
}
