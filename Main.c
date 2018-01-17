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


//function prototypes
void EnableInterrupts(void);

volatile unsigned char SysTickFlag = 0;

#if TEST
volatile static unsigned int motorN = 0;
#endif

#if (SWITCH && TEST)
void SysTick_Handler(void){
	static unsigned int task = COIN_HANDLER; //waiting for coins will be default
	static unsigned int credit = 0;
	
	//represents £1
	//Use any motor 0-7
	if(Switch_B1()){
		credit = 100;
	}
	
	//represents £0.50
	//Use any motor 8-16
	if(Switch_B2()){
		credit = 50;
	}

	SysTickFlag = 1;
}

#elif(TEST)
void SysTick_Handler(void){
	static unsigned int task = COIN_HANDLER; //waiting for coins will be default
	static unsigned int idleCount = 0;
	static unsigned int previousCode;
	
	switch(task){
		case COIN_HANDLER:
			//credit function NA
			task = ERROR_HANDLER;
			SysTickFlag = 1;
			break;
		case ERROR_HANDLER:{
			volatile unsigned int currentCode = (GPIO_PORTN_DATA_R & ~0xFFFFF3CC); //clears all except b2, b3
			switch(currentCode){
				case IDLE:
					if(previousCode == VENDING){
						//item sold
						motorStop(motorN);
						itemSold(motorN);
						motorN++;
						idleCount = 0;
						task = COIN_HANDLER;
						SysTickFlag = 1;
					}
					else{
						idleCount++;
						if(idleCount > MAXIDLING){
							motorStop(motorN);
							motorDisable(motorN);
							idleCount = 0;
							task = COIN_HANDLER;
							SysTickFlag = 1;
						}
					}
					break;
//				case VENDING:
//					//no idea
//					break;
				case JAMMED:
					motorStop(motorN);
					motorDisable(motorN);
					idleCount = 0;
					task = COIN_HANDLER;
					SysTickFlag = 1;
					break;
			}
			previousCode = currentCode;
			break;
		}
	}
}
#else
//here we suppose to place the "real code"
void SysTick_Handler(void){

	SysTickFlag = 1;
}
#endif


int main(void){
	initHw();
	motorInit();
	EnableInterrupts();
#if TEST
	Systick_Init(2666666);	//initialized @30Hz (if clock works at 80 MHz)

	while(1){
		while(SysTickFlag == 0){};
		//we action the motor	here
		unsigned int active = isMotorActive(motorN);

		if(~active){
			sell(motorN);
		}
		
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

-Next step:
	merge errorDetect into handler
*/

