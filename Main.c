// LEDTestMain.c
// Runs on TM4C1294

/*
The system starts setting hardware and providing initial values
*After the setup is done it will run a test: 
	1) it will make sure there are not errors before the test begins
	2) Move motor0
	3) wait for error code from motor0
	4) repeat 2 and 3 until each motor has been tested
*/

#include <stdint.h>
#include "../tm4c1294ncpdt.h"
#include "init.h"
#include "debug.h"
#include "test.h"

int main(void){
	initHw();
#if TEST
	testHW();
#else
	while(1){


	}
#endif	
}
