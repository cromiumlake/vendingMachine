//engine.c


/*
This file deals with dispensing the products
*/

#include <stdint.h>
#include "../tm4c1294ncpdt.h"
#include "debug.h"
#include "engine.h"


//---------------------------------------------------------------------

struct Motors{
	unsigned char active;
	unsigned char enable;
	unsigned char nProducts;
};

struct Motors motor[MAXMOTORS];

void motorInit(void){
#if M0_enable
	motor[0].active = 0;
	motor[0].enable = M0_enable;
	motor[0].nProducts = M0_nProducts;
#endif
	
#if M1_enable
	motor[1].active = 0;
	motor[1].enable = M1_enable;
	motor[1].nProducts = M1_nProducts;
#endif
	
#if M2_enable
	motor[2].active = 0;
	motor[2].enable = M2_enable;
	motor[2].nProducts = M2_nProducts;
#endif
	
#if M3_enable
	motor[3].active = 0;
	motor[3].enable = M3_enable;
	motor[3].nProducts = M3_nProducts;
#endif

#if M4_enable
	motor[4].active = 0;
	motor[4].enable = M4_enable;
	motor[4].nProducts = M4_nProducts;
#endif

#if M5_enable
	motor[5].active = 0;
	motor[5].enable = M5_enable;
	motor[5].nProducts = M5_nProducts;
#endif

#if M6_enable
	motor[6].active = 0;
	motor[6].enable = M6_enable;
	motor[6].nProducts = M6_nProducts;
#endif

#if M7_enable
	motor[7].active = 0;
	motor[7].enable = M7_enable;
	motor[7].nProducts = M7_nProducts;
#endif

#if M8_enable
	motor[8].active = 0;
	motor[8].enable = M8_enable;
	motor[8].nProducts = M8_nProducts;
#endif

#if M9_enable
	motor[9].active = 0;
	motor[9].enable = M9_enable;
	motor[9].nProducts = M9_nProducts;
#endif

#if M10_enable
	motor[10].active = 0;
	motor[10].enable = M10_enable;
	motor[10].nProducts = M10_nProducts;
#endif

#if M11_enable
	motor[11].active = 0;
	motor[11].enable = M11_enable;
	motor[11].nProducts = M11_nProducts;
#endif

#if M12_enable
	motor[12].active = 0;
	motor[12].enable = M12_enable;
	motor[12].nProducts = M12_nProducts;
#endif

#if M13_enable
	motor[13].active = 0;
	motor[13].enable = M13_enable;
	motor[13].nProducts = M13_nProducts;
#endif

#if M14_enable
	motor[14].active = 0;
	motor[14].enable = M14_enable;
	motor[14].nProducts = M14_nProducts;
#endif

#if M15_enable
	motor[15].active = 0;
	motor[15].enable = M15_enable;
	motor[15].nProducts = M15_nProducts;
#endif
}
//-----------------------------------------------------------------------
void sell(unsigned int id){
	
	if(motor[id].enable &&	motor[id].nProducts){
		//move motor
		motorStart(id);
	}
}

void motorStart(unsigned int id){

	switch(id){
		case 0:
			GPIO_PORTA_DATA_R |= 0x80; //PA7
			break;
		case 1:
			GPIO_PORTC_DATA_R |= 0x40; //PC6
			break;
		case 2:
			GPIO_PORTC_DATA_R |= 0x80; //PC7
			break;
		case 3:
			GPIO_PORTH_DATA_R |= 0x02; //PH1
			break;
		case 4:
			GPIO_PORTH_DATA_R |= 0x04; //PH2
			break;
		case 5:
			GPIO_PORTH_DATA_R |= 0x08; //PH3
			break;
		case 6:
			GPIO_PORTK_DATA_R |= 0x40; //PK6
			break;
		case 7:
			GPIO_PORTK_DATA_R |= 0x80; //PK7
			break;
		case 8:
			GPIO_PORTL_DATA_R |= 0x01; //PL0
			break;
		case 9:
			GPIO_PORTL_DATA_R |= 0x02; //PL1
			break;
		case 10:
			GPIO_PORTL_DATA_R |= 0x04; //PL2
			break;
		case 11:
			GPIO_PORTL_DATA_R |= 0x08; //PL3
			break;
		case 12:
			GPIO_PORTM_DATA_R |= 0x40; //PM6
			break;
		case 13:
			GPIO_PORTP_DATA_R |= 0x08; //PP3
			break;
		case 14:
			GPIO_PORTP_DATA_R |= 0x20; //PP5
			break;
		case 15:
			GPIO_PORTQ_DATA_R |= 0x02; //PQ1
			break;
	}
	
	motor[id].active = 1;
}
void motorStop(unsigned int id){

	switch(id){
		case 0:
			GPIO_PORTA_DATA_R &= ~0x80; //PA7
			break;
		case 1:
			GPIO_PORTC_DATA_R &= ~0x40; //PC6
			break;
		case 2:
			GPIO_PORTC_DATA_R &= ~0x80; //PC7
			break;
		case 3:
			GPIO_PORTH_DATA_R &= ~0x02; //PH1
			break;
		case 4:
			GPIO_PORTH_DATA_R &= ~0x04; //PH2
			break;
		case 5:
			GPIO_PORTH_DATA_R &= ~0x08; //PH3
			break;
		case 6:
			GPIO_PORTK_DATA_R &= ~0x40; //PK6
			break;
		case 7:
			GPIO_PORTK_DATA_R &= ~0x80; //PK7
			break;
		case 8:
			GPIO_PORTL_DATA_R &= ~0x01; //PL0
			break;
		case 9:
			GPIO_PORTL_DATA_R &= ~0x02; //PL1
			break;
		case 10:
			GPIO_PORTL_DATA_R &= ~0x04; //PL2
			break;
		case 11:
			GPIO_PORTL_DATA_R &= ~0x08; //PL3
			break;
		case 12:
			GPIO_PORTM_DATA_R &= ~0x40; //PM6
			break;
		case 13:
			GPIO_PORTP_DATA_R &= ~0x08; //PP3
			break;
		case 14:
			GPIO_PORTP_DATA_R &= ~0x20; //PP5
			break;
		case 15:
			GPIO_PORTQ_DATA_R &= ~0x02; //PQ1
			break;
	}
		
	motor[id].active = 0;
}


void motorDisable(unsigned int id){
	motor[id].enable = 0;
}


unsigned int isMotorActive(unsigned int id){
	return motor[id].active;
}

void itemSold(unsigned int id){
	motor[id].nProducts--;
}

/*
Notes:
	*the signal to the mottor:
		needs to remain high or the motor will stop
		The stop switch interrupts the power to the motor, but it will continue running after the interruption unless the pin goes low. It only signals the start position. So the nothing/running/jammed logic will briefly glitch to ‘nothing’
		nothing = idle.
		It cuts the power to the motor, and the motor's inertia let's it continue and reconnect itself
		I'm guessing but probably 100-200 mS

*/

