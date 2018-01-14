//structures.h
//this file contain data structures

#include "debug.h"

struct Motors{
	unsigned char active;
	unsigned char enable;
	unsigned char nProducts;
	unsigned char productCounter;
	volatile unsigned char start;
	volatile unsigned char stop;
};

static struct Motors motor[MAXMOTORS];

