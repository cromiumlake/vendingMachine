//test.c

#include <stdint.h>
#include "../tm4c1294ncpdt.h"
#include "test.h"

/*
-please not that "moving motor xx" will be replaced by the 
righ motor number
*/
void testHW(void){
	static unsigned int i = 0;
	
	switch(i){
		case 0:
			//moving motor_xx
			GPIO_PORTA_DATA_R |= 0x80; //PA7
			break;
		case 1:
			//moving motor_xx
			GPIO_PORTC_DATA_R |= 0x40; //PC6
			break;
		case 2:
			//moving motor_xx
			GPIO_PORTC_DATA_R |= 0x80; //PC7
			break;
		case 3:
			//moving motor_xx
			GPIO_PORTH_DATA_R |= 0x02; //PH1			
			break;
		case 4:
			//moving motor_xx	
			GPIO_PORTH_DATA_R |= 0x04; //PH2
			break;
		case 5:
			//moving motor_xx	
			GPIO_PORTH_DATA_R |= 0x08; //PH3
			break;
		case 6:
			//moving motor_xx	
			GPIO_PORTK_DATA_R |= 0x40; //PK6
			break;
		case 7:
			//moving motor_xx
			GPIO_PORTK_DATA_R |= 0x80; //PK7
			break;
		case 8:
			//moving motor_xx	
			GPIO_PORTL_DATA_R |= 0x01; //PL0
			break;
		case 9:
			//moving motor_xx	
			GPIO_PORTL_DATA_R |= 0x02; //PL1
			break;
		case 10:
			//moving motor_xx	
			GPIO_PORTL_DATA_R |= 0x04; //PL2			
			break;
		case 11:
			//moving motor_xx	
			GPIO_PORTL_DATA_R |= 0x08; //PL3
			break;
		case 12:
			//moving motor_xx	
			GPIO_PORTM_DATA_R |= 0x40; //PM6
			break;
		case 13:
			//moving motor_xx	
			GPIO_PORTP_DATA_R |= 0x08; //PP3
			break;
		case 14:
			//moving motor_xx	
			GPIO_PORTP_DATA_R |= 0x20; //PP5
			break;
		case 15:
			//moving motor_xx	
			GPIO_PORTQ_DATA_R |= 0x02; //PQ1
			break;
	}
}


/*
Notes: 
*Testing routine will not require money
*This section aims to check:
	-Motors working conditions
	-check interrupt times are at tyhe right frequency
	-All vending conditions are met

*/
