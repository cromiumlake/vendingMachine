// Main.c
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
#include "random.h"
#include "buttons.h"
#include "engine.h"

volatile unsigned char SysTickFlag = 0;
volatile unsigned char vending = 0;

#if TEST
	static unsigned int motorN = 0;
#endif

#if (SWITCH && TEST)
void SysTick_Handler(void){
	volatile static unsigned char clickCounter1 = 0;			//keeps track of clicks
	volatile static unsigned char clickCounter2 = 0;			//keeps track of clicks
	
	//represents £1
	//Use any motor 0-7
	if(Switch_B1()){
		Random_Init(NVIC_CURRENT_R);
		unsigned int m = Random32()%7;
		sell(m);
		clickCounter1 = 0;
	}
	
	//represents £0.50
	//Use any motor 8-16
	if(Switch_B2()){
		Random_Init(NVIC_CURRENT_R);
		unsigned int m = 7 + Random32()%7;
		sell(m);
		clickCounter2 = 0;
	}

	SysTickFlag = 1;
}

#elif(TEST)
void SysTick_Handler(void){
	static unsigned int task = COIN_W; //waiting for coins will be default
	switch(task){
		case COIN_W:
			//credit function NA
			task = ERROR_W;
			vending = 1;
			break;
		case ERROR_W:{
			unsigned int error = errorDetect(motorN);
			switch(error){
				case VENDING:
					vending = 0;
					break;
				case JAMMED:
					break;
			}
			break;
		}
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
	Systick_Init(2666666);	//initialized @30Hz (if clock works at 80 MHz)

	while(1){
		while(SysTickFlag == 0){};
		//we action the motor	here
				do{
					sell(motorN);
				}while(vending == 1);
			
			motorN++;
			SysTickFlag = 0;
	}
#else
	while(1){


	}
#endif	
}



/*
Notes:
-There is one interrupt, it has to deal with two actions:
	look for errors
	look for coins


*/

