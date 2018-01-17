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
	unsigned char productCounter;
};

struct Motors motor[MAXMOTORS];

void motorInit(void){
#if M0_enable
	motor[0].active = 0;
	motor[0].enable = M0_enable;
	motor[0].nProducts = M0_nProducts;
	motor[0].productCounter = 0;
#endif
	
#if M1_enable
	motor[1].active = 0;
	motor[1].enable = M1_enable;
	motor[1].nProducts = M1_nProducts;
	motor[1].productCounter = 0;
#endif
	
#if M2_enable
	motor[2].active = 0;
	motor[2].enable = M2_enable;
	motor[2].nProducts = M2_nProducts;
	motor[2].productCounter = 0;
#endif
	
#if M3_enable
	motor[3].active = 0;
	motor[3].enable = M3_enable;
	motor[3].nProducts = M3_nProducts;
	motor[3].productCounter = 0;
#endif

#if M4_enable
	motor[4].active = 0;
	motor[4].enable = M4_enable;
	motor[4].nProducts = M4_nProducts;
	motor[4].productCounter = 0;
#endif

#if M5_enable
	motor[5].active = 0;
	motor[5].enable = M5_enable;
	motor[5].nProducts = M5_nProducts;
	motor[5].productCounter = 0;
#endif

#if M6_enable
	motor[6].active = 0;
	motor[6].enable = M6_enable;
	motor[6].nProducts = M6_nProducts;
	motor[6].productCounter = 0;
#endif

#if M7_enable
	motor[7].active = 0;
	motor[7].enable = M7_enable;
	motor[7].nProducts = M7_nProducts;
	motor[7].productCounter = 0;
#endif

#if M8_enable
	motor[8].active = 0;
	motor[8].enable = M8_enable;
	motor[8].nProducts = M8_nProducts;
	motor[8].productCounter = 0;
#endif

#if M9_enable
	motor[9].active = 0;
	motor[9].enable = M9_enable;
	motor[9].nProducts = M9_nProducts;
	motor[9].productCounter = 0;
#endif

#if M10_enable
	motor[10].active = 0;
	motor[10].enable = M10_enable;
	motor[10].nProducts = M10_nProducts;
	motor[10].productCounter = 0;
#endif

#if M11_enable
	motor[11].active = 0;
	motor[11].enable = M11_enable;
	motor[11].nProducts = M11_nProducts;
	motor[11].productCounter = 0;
#endif

#if M12_enable
	motor[12].active = 0;
	motor[12].enable = M12_enable;
	motor[12].nProducts = M12_nProducts;
	motor[12].productCounter = 0;
#endif

#if M13_enable
	motor[13].active = 0;
	motor[13].enable = M13_enable;
	motor[13].nProducts = M13_nProducts;
	motor[13].productCounter = 0;
#endif

#if M14_enable
	motor[14].active = 0;
	motor[14].enable = M14_enable;
	motor[14].nProducts = M14_nProducts;
	motor[14].productCounter = 0;
#endif

#if M15_enable
	motor[15].active = 0;
	motor[15].enable = M15_enable;
	motor[15].nProducts = M15_nProducts;
	motor[15].productCounter = 0;
#endif
}
//-----------------------------------------------------------------------
//this interrupt is going to be executed @3xCPS
//used for detecting the reply codes
unsigned int errorDetect(void){
	static volatile unsigned int error;
	static unsigned int idleCounter = 0;
	static unsigned int previousState;
	volatile unsigned int currentState = GPIO_PORTN_DATA_R & ~0xFFFFF3CC; //clears all except b2, b3
	
	if(previousState == IDLE){
		switch(currentState){
			case VENDING:
				currentState = IDLE;
				error = VENDING;
				break;
			case IDLE:
				idleCounter++;
				if(idleCounter > MAXIDLING){
					error =  IDLE;
					idleCounter = 0;
				}
				break;
			case JAMMED:
				error =  JAMMED;
				break;
		}
	}

	previousState = currentState;
	return error;
}


void sell(unsigned int id){
	unsigned int motorNmber = id;
	unsigned int productAvailable = motor[motorNmber].nProducts - motor[motorNmber].productCounter;
	
	if(motor[motorNmber].enable &&	productAvailable){
		//move motor
			motorStart(motorNmber);
	}
}

void motorStart(unsigned int motorNumber){
	unsigned int motorN = motorNumber;

	switch(motorN){
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
	
	motor[motorNumber].active = 1;
}
void motorStop(unsigned int motorNumber){
	unsigned int motorN = motorNumber;

	switch(motorN){
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
		
	motor[motorNumber].active = 0;
}


void motorDisable(unsigned int motorN){
	motor[motorN].enable = 0;
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

