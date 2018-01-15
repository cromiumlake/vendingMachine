//motorConfig.c

#include <stdint.h>
#include "../tm4c1294ncpdt.h"
#include "structures.h"
#include "debug.h"

void motorInit(void){
	unsigned int i = 0;
	
	
	while(i < MAXMOTORS){
		switch(i){
			case 0:
				motor[i].active = 0;
				motor[i].enable = M0_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 1:
				motor[i].active = 0;
				motor[i].enable = M1_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 2:
				motor[i].active = 0;
				motor[i].enable = M2_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 3:
				motor[i].active = 0;
				motor[i].enable = M3_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 4:
				motor[i].active = 0;
				motor[i].enable = M4_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 5:
				motor[i].active = 0;
				motor[i].enable = M5_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 6:
				motor[i].active = 0;
				motor[i].enable = M6_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 7:
				motor[i].active = 0;
				motor[i].enable = M7_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 8:
				motor[i].active = 0;
				motor[i].enable = M8_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 9:
				motor[i].active = 0;
				motor[i].enable = M9_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 10:
				motor[i].active = 0;
				motor[i].enable = M10_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 11:
				motor[i].active = 0;
				motor[i].enable = M11_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 12:
				motor[i].active = 0;
				motor[i].enable = M12_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 13:
				motor[i].active = 0;
				motor[i].enable = M13_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 14:
				motor[i].active = 0;
				motor[i].enable = M14_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
			case 15:
				motor[i].active = 0;
				motor[i].enable = M15_enable;
				motor[i].nProducts = M0_nProducts;
				motor[i].productCounter = 0;
				break;
		}
		i++;
	}
}

