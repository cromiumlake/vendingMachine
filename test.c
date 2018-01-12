//test.c

#include <stdint.h>
#include "../tm4c1294ncpdt.h"
#include "test.h"

/*
-please not that "moving motor xx" will be replaced by the 
righ motor number
*/
void testHW(void){
	
	//moving motor_xx
	GPIO_PORTA_DATA_R |= 0x80; //PA7
	//moving motor_xx
	GPIO_PORTC_DATA_R |= 0x40; //PC6
	//moving motor_xx
	GPIO_PORTC_DATA_R |= 0x80; //PC7
	//moving motor_xx
	GPIO_PORTH_DATA_R |= 0x02; //PH1
	//moving motor_xx	
	GPIO_PORTH_DATA_R |= 0x04; //PH2
	//moving motor_xx	
	GPIO_PORTH_DATA_R |= 0x08; //PH3
	//moving motor_xx	
	GPIO_PORTK_DATA_R |= 0x40; //PK6
	//moving motor_xx
	GPIO_PORTK_DATA_R |= 0x80; //PK7
	//moving motor_xx	
	GPIO_PORTL_DATA_R |= 0x01; //PL0
	//moving motor_xx	
	GPIO_PORTL_DATA_R |= 0x02; //PL1
	//moving motor_xx	
	GPIO_PORTL_DATA_R |= 0x04; //PL2
	//moving motor_xx	
	GPIO_PORTL_DATA_R |= 0x08; //PL3
	//moving motor_xx	
	GPIO_PORTM_DATA_R |= 0x40; //PM6
	//moving motor_xx	
	GPIO_PORTP_DATA_R |= 0x08; //PP3
	//moving motor_xx	
	GPIO_PORTP_DATA_R |= 0x20; //PP5
	//moving motor_xx	
	GPIO_PORTQ_DATA_R |= 0x02; //PQ1
}


/*
Notes: 
*Testing routine will not require money
*This section aims to check:
	-Motors working conditions
	-check interrupt times are at tyhe right frequency
	-All vending conditions are met

*/
