//engine.c


/*
This file deals with dispensing the products
*/

#include "structures.h"
#include <stdint.h>
#include "../tm4c1294ncpdt.h"
#include "engine.h"


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
		motor[motorNmber].active = 1;
		while(motor[motorNmber].active == 1){
			motorStart(motorNmber);
		}
	}
}

void motorStart(unsigned int motorNumber){
	unsigned int motorN = motorNumber;

	switch(motorNumber){
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

	switch(motorNumber){
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

/*
Notes:
	*the signal to the mottor:
		needs to remain high or the motor will stop
		The stop switch interrupts the power to the motor, but it will continue running after the interruption unless the pin goes low. It only signals the start position. So the nothing/running/jammed logic will briefly glitch to ‘nothing’
		nothing = idle.
		It cuts the power to the motor, and the motor's inertia let's it continue and reconnect itself
		I'm guessing but probably 100-200 mS

*/

