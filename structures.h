//structures.h

//this file contain data structures

#include "debug.h"

struct Motors{
	unsigned char inputCode;
	unsigned char outputCode;
};

static struct Motors motor[MAXMOTORS];

