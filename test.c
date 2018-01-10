//test.c

#include <stdint.h>
#include "../tm4c1294ncpdt.h"
#include "test.h"

void testHW(void){
	
	GPIO_PORTA_DATA_R |= 0x80; //PA7
	
	GPIO_PORTC_DATA_R |= 0x40; //PC6
	GPIO_PORTC_DATA_R |= 0x80; //PC7
	
	GPIO_PORTH_DATA_R |= 0x02; //PH1
	GPIO_PORTH_DATA_R |= 0x04; //PH2
	GPIO_PORTH_DATA_R |= 0x08; //PH3
	
	GPIO_PORTK_DATA_R |= 0x40; //PK6
	GPIO_PORTK_DATA_R |= 0x80; //PK7
	
	GPIO_PORTL_DATA_R |= 0x01; //PL0
	GPIO_PORTL_DATA_R |= 0x02; //PL1
	GPIO_PORTL_DATA_R |= 0x04; //PL2
	GPIO_PORTL_DATA_R |= 0x08; //PL3
	
	GPIO_PORTM_DATA_R |= 0x40; //PM6
	
	GPIO_PORTP_DATA_R |= 0x08; //PP3
	GPIO_PORTP_DATA_R |= 0x20; //PP5
	
	GPIO_PORTQ_DATA_R |= 0x02; //PQ1
}

