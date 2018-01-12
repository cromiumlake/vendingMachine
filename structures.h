//structures.h

//this file contain data structures

#include "debug.h"


/*

icID: assuming that the motors are not in order, eg. we are trying to move motor1 while moving motor5. Meaning there is a mismatch between what we are moving trying to move
Then we should have a way to place them in the right order
*/
struct Motors{
	unsigned char active;
	unsigned char outputCode;
	unsigned char disable;
	unsigned char icID;
	unsigned char nProducts;
	unsigned char productCounter;
};

static struct Motors motor[MAXMOTORS];


