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
void interrupt(void){
	static unsigned int counter = 0;
	
	counter++;
	if(counter == 3){
			error = GPIO_PORTN_DATA_R & ~0xFFFFF3CC;
	}
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

Questions:
	*for how long the response code is up?
	*does it get reset by itself or at all?

*/