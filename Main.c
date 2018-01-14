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
#include "random.h"
#include "buttons.h"
#include "engine.h"

volatile unsigned char SysTickFlag = 0;
volatile unsigned char vending = 0;

#if SWITCH
void SysTick_Handler(void){
	volatile static unsigned char clickCounter1 = 0;			//keeps track of clicks
	volatile static unsigned char clickCounter2 = 0;			//keeps track of clicks
	
	//represents £1
	//Use any motor 0-7
	if(Switch_B1()){
		unsigned int m = Random32()%7;
		sell(m);
		clickCounter1 = 0;
	}
	
	//represents £0.50
	//Use any motor 8-16
	if(Switch_B2()){
		unsigned int m = 7 + Random32()%7;
		sell(m);
		clickCounter2 = 0;
	}

	SysTickFlag = 1;
}

#else
void SysTick_Handler(void){

	SysTickFlag = 1;
}
#endif


int main(void){
	initHw();
#if TEST
//	testHW();
	Random_Init(5000);
	while(1){
		while(SysTickFlag == 0){};
		//we action the motor	here
		do{
		}while(vending == 1);
		
		SysTickFlag = 0;
	}
#else
	while(1){


	}
#endif	
}
