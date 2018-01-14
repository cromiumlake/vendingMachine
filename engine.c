//engine.c


/*
This file deals with dispensing the products
*/

#include "structures.h"
#include <stdint.h>
#include "../tm4c1294ncpdt.h"

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
			motor[motorNmber].start;
		}
	}
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

