//errorControl.c

//this file contains routines that deal with errors

/*!
    \brief 			This function handles events ....
    \param[in]  pNetAppEvent is the event passed to the handler
    \return     PN2, PN3
    \note				error checking should have an interrupt: 
									*so that normal execution stops and corrections are taken
    \warning
*/

#include <stdint.h>
#include "../tm4c1294ncpdt.h"
#include "structures.h"
#include "errorControl.h"


/*!
    \brief 		This function handles events....
    \return         ...
    \note			The return value is a 2-bit number
    \warning
*/
void errorCheckAllMotors(void){
	
	
	for(unsigned char i=0;i<=MAXMOTORS;i++){
		if(motor[i].outputCode == 1){
	
		}
	}
}
