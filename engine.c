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

static volatile unsigned int error;

//this interrupt is going to be executed @3xCPS
//used for detecting the reply codes
void interrupt1(void){
	static unsigned int counter = 0;
	static unsigned int previousError;
	unsigned int currentError = GPIO_PORTN_DATA_R & ~0xFFFFF3CC; //clears all except b2, b3
	
	if(previousError != currentError){
		error = currentError;
		counter = 0;		
		return;
	}
	
	counter++;
	if(counter == 3){
		if(previousError == currentError && previousError == IDLE){
			error = IDLE;
			counter = 0;
			return;
		}
	}
	
	previousError = currentError;
}


void sell(unsigned int id){
	unsigned int motorNmber = id;
	unsigned int productGO = motor[motorNmber].nProducts - motor[motorNmber].productCounter;
	
	if(motor[motorNmber].disable &&	productGO > 0){
		//move motor
		motor[motorNmber].active = 1;
		while(motor[motorNmber].active == 1){
			
		}
		//initiate timer/ interrupt
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

