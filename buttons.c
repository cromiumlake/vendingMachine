//buttons.c

#include "buttons.h"


bool Switch_B1(void){
	static bool switch_Bool,Prev_switch;
	
	if((GPIO_PORTJ_DATA_R&0x00) && (Prev_switch == 0)){ // just pressed
		switch_Bool = true;
	}
	else{
		switch_Bool = false;
	}
	Prev_switch = (bool)(GPIO_PORTJ_DATA_R&0x00);
	return switch_Bool;
}


bool Switch_B2(void){
	static bool switch_Bool_2,Prev_switch_2;
	
	if((GPIO_PORTJ_DATA_R&0x01) && (Prev_switch_2 == 0)){ // just pressed
		switch_Bool_2 = true;
	}
	else{
			switch_Bool_2 = false;
	}
	Prev_switch_2 = (bool)(GPIO_PORTJ_DATA_R&0x01);
	return switch_Bool_2;
}
