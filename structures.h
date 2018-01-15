//structures.h
//this file contain data structures

#include "debug.h"

struct Motors{
	unsigned char active;
	unsigned char enable;
	unsigned char nProducts;
	unsigned char productCounter;
};

static struct Motors motor[MAXMOTORS];

