//engine.c


/*
This file deals with dispensing the products
*/


/*
@stage1: 
	in: ID number. The ID number is the motor number
	out: responseCode
*/
#include "structures.h"
#include <stdint.h>
#include "../tm4c1294ncpdt.h"



//this interrupt is going to be executed @3xCPS
//used for detecting the reply codes
unsigned int errorDetect(unsigned int motorN){
	static volatile unsigned int error;
	static unsigned int idleCounter = 0;
	static unsigned int previousState;
	volatile unsigned int currentState = GPIO_PORTN_DATA_R & ~0xFFFFF3CC; //clears all except b2, b3
	unsigned int MotorN = motorN;
	
	
	if(previousState == IDLE){
		switch(currentState){
			case VENDING:
				currentState = IDLE;
				return VENDING;
				break;
			case IDLE:
				idleCounter++;
				return IDLE;
				break;
			case JAMMED:
				return JAMMED;
				break;
		}
	}

	previousState = currentState;
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
	*once the motor is active we need a separate thread to
		keep track of the responce code
	*the signal to the mottor:
		needs to remain high or the motor will stop
		The stop switch interrupts the power to the motor, but it will continue running after the interruption unless the pin goes low. It only signals the start position. So the nothing/running/jammed logic will briefly glitch to ‘nothing’
		nothing = idle.
		It cuts the power to the motor, and the motor's inertia let's it continue and reconnect itself
		I'm guessing but probably 100-200 mS


note2:
*make a table that considers different scenarios and tranlate it to code
*/

