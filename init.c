//init.c


//Gate ports: A C H K L M P Q 
//D2-4	PA7
//A1-8	PC7
//A1-5	PC6
//D1-4	PH3
//D1-3	PH2
//C2-8	PH1
//C2-10	PK7
//C2-9	PK6
//C1-10	PL3
//C1-9	PL2
//C1-8	PL1
//C1-7	PL0
//D2-10	PM6
//D2-8	PP3
//D2-3	PP5
//D2-9	PQ1

//response codes:
//D1-9	PN3
//D1-10 	PN2

//switches:
//PJ0
//PJ1


#include "../tm4c1294ncpdt.h"
#include <stdint.h>
#include "init.h"
#include  "structures.h"
#include "debug.h"


/*!
\brief This file initializes ports: A C H K L M P Q 
    \param[in]      None
    \return         None
    \note		Port J: used only for switches during testing
    \warning
*/

//hardware initialization
void initHw(void){
	//output pins
	initPort_A();
	initPort_C();
	initPort_H();
	initPort_K();
	initPort_L();
	initPort_M();
	initPort_P();
	initPort_Q();
	
	//input pins
	initPort_N();
	//switches used for testing
#if SWITCH
	initPort_J();
#endif	
}

void initPort_A(void){
	// activate clock for Port A (PA7)
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
	while((SYSCTL_PRGPIO_R&SYSCTL_RCGCGPIO_R0) == 0){};
		
	GPIO_PORTA_DIR_R |= 0x80;	//PA7 out
	GPIO_PORTA_AFSEL_R &= ~0x80;	// disable alt funct
	GPIO_PORTA_DEN_R |= 0x80;		// enable digital I/O
	GPIO_PORTA_PCTL_R &= ~0xF0000000;		//normal gpio on bits
	GPIO_PORTA_AMSEL_R &= ~0x80;
}

void initPort_C(void){
	// activate clock for Port C (PC7, PC6)
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;
	while((SYSCTL_PRGPIO_R&SYSCTL_RCGCGPIO_R2) == 0){};	
		
	GPIO_PORTC_DIR_R |= 0xC0;	//PC7, PC6 out
	GPIO_PORTC_AFSEL_R &= ~0xC0;	// disable alt funct
	GPIO_PORTC_DEN_R |= 0xC0;		// enable digital I/O
	GPIO_PORTC_PCTL_R &= ~0xFF000000;		//normal gpio on bits
	GPIO_PORTC_AMSEL_R &= ~0xC0;		// disable analog functionality on bits
}

void initPort_H(void){
	// activate clock for Port H (PH3, PH2, PH1)
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R7;
	while((SYSCTL_PRGPIO_R&SYSCTL_RCGCGPIO_R7) == 0){};	
		
	GPIO_PORTH_DIR_R |= 0x0E;	// PH3, PH2, PH1 out
	GPIO_PORTH_AFSEL_R &= ~0x0E;	// disable alt funct
	GPIO_PORTH_DEN_R |= 0x0E;		// enable digital I/O
	GPIO_PORTH_PCTL_R &= ~0x0000FFF0;		//normal gpio on bits
	GPIO_PORTH_AMSEL_R &= ~0x0E;		// disable analog functionality on bits
}

void initPort_K(void){
	// activate clock for Port K (PK7, PK6)
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R9;
	while((SYSCTL_PRGPIO_R&SYSCTL_RCGCGPIO_R9) == 0){};	
		
	GPIO_PORTK_DIR_R |= 0xC0;	//PK7, PK6 out
	GPIO_PORTK_AFSEL_R &= ~0xC0;	// disable alt funct
	GPIO_PORTK_DEN_R |= 0xC0;		// enable digital I/O
	GPIO_PORTK_PCTL_R &= ~0xFF000000;		//normal gpio on bits
	GPIO_PORTK_AMSEL_R &= ~0xC0;		// disable analog functionality on bits
}

void initPort_L(void){
	// activate clock for Port L (PL3, PL2, PL1, PL0)
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R10;
	while((SYSCTL_PRGPIO_R&SYSCTL_RCGCGPIO_R10) == 0){};	
		
	GPIO_PORTL_DIR_R |= 0x0F;		// PL3, PL2, PL1, PL0 out
	GPIO_PORTL_AFSEL_R &= ~0x0F;	// disable alt funct
	GPIO_PORTL_DEN_R |= 0x0F;		// enable digital I/O
	GPIO_PORTL_PCTL_R &= ~0x0000FFFF;		//normal gpio on bits
	GPIO_PORTL_AMSEL_R &= ~0x0F;		// disable analog functionality on bits
}

void initPort_M(void){
	// activate clock for Port M (PM6)
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R11;
	while((SYSCTL_PRGPIO_R&SYSCTL_RCGCGPIO_R11) == 0){};	
		
	GPIO_PORTM_DIR_R |= 0x40;		//PM6 out
	GPIO_PORTM_AFSEL_R &= ~0x40;	// disable alt funct
	GPIO_PORTM_DEN_R |= 0x40;		// enable digital I/O
	GPIO_PORTM_PCTL_R &= ~0x0F000000;		//normal gpio on bits
	GPIO_PORTM_AMSEL_R &= ~0x40;		// disable analog functionality on bits
}
void initPort_N(void){
	// activate clock for Port N (PN3, PN2)
	//this ones return an error from the motors after activation
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12;
	while((SYSCTL_PRGPIO_R&SYSCTL_RCGCGPIO_R12) == 0){};
		
	GPIO_PORTN_DIR_R &= ~0x0C;		//PN3, PN2 IN
	GPIO_PORTN_AFSEL_R &= ~0x0C;	// disable alt funct
	GPIO_PORTN_DEN_R |= 0x0C;			// enable digital I/O
	GPIO_PORTN_PCTL_R &= ~0x0000FF00;		//normal gpio on bits
	GPIO_PORTN_AMSEL_R &= ~0x0C;		// disable analog functionality on bits

}
void initPort_P(void){
	// activate clock for Port P (PP5, PP3)
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R13;
	while((SYSCTL_PRGPIO_R&SYSCTL_RCGCGPIO_R13) == 0){};	
		
	GPIO_PORTP_DIR_R |= 0x40;		//PM6, PP5, PP3 out
	GPIO_PORTP_AFSEL_R &= ~0x40;	// disable alt funct
	GPIO_PORTP_DEN_R |= 0x40;		// enable digital I/O
	GPIO_PORTP_PCTL_R &= ~0x00F0F000;		//normal gpio on bits
	GPIO_PORTP_AMSEL_R &= ~0x40;		// disable analog functionality on bits
}

void initPort_Q(void){
	// activate clock for Port Q (PQ1)
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R14;
	while((SYSCTL_PRGPIO_R&SYSCTL_RCGCGPIO_R14) == 0){};
		
	GPIO_PORTQ_DIR_R |= 0x02;		//PQ1 out
	GPIO_PORTQ_AFSEL_R &= ~0x02;	// disable alt funct
	GPIO_PORTQ_DEN_R |= 0x02;			// enable digital I/O
	GPIO_PORTQ_PCTL_R &= ~0x000000F0;		//normal gpio on bits
	GPIO_PORTQ_AMSEL_R &= ~0x02;		// disable analog functionality on bits
}

//switches
#if SWITCH
void initPort_J(void){
	// activate clock for Port J (PJ0, PJ1)
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R8;
	while((SYSCTL_PRGPIO_R&SYSCTL_RCGCGPIO_R8) == 0){};
		
	GPIO_PORTJ_DIR_R &= ~0x03;		//PJ0, PJ1 in
	GPIO_PORTJ_AFSEL_R &= ~0x03;	// disable alt funct
	GPIO_PORTJ_DEN_R |= 0x03;			// enable digital I/O
	GPIO_PORTJ_PCTL_R &= ~0x000000FF;		//normal gpio on bits
	GPIO_PORTJ_AMSEL_R &= ~0x03;		// disable analog functionality on bits
}
#endif	
//********Systick*****************
//Clock used: 
//Port: NA
//Mode: Digital
void Systick_Init(unsigned long periodSystick){
  NVIC_ST_CTRL_R = 0;         						// disable SysTick during setup
  NVIC_ST_RELOAD_R = periodSystick;						// reload value
  NVIC_ST_CURRENT_R = 0;      						// any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x20000000; // priority 1
  NVIC_ST_CTRL_R = 0x0007; 								// enable,core clock, and interrupts
																					//CLK_SRC, INTEN, ENABLE
}

/*
Todo:
*asociate pins to motor number
*Verify the clock speed
*Configure RSCLKCFG
	check the PLL configurations of example files

Development stages:
stage 0:
	code name: buggery
	does: press button1 to represent "insert coin"
stage 1:
	code name: lucky deep
	does: sells a ramdom product from the shelf
	re stocking: recompilation required to specify "nProducts"
stage 2:
	code name: interface
	does: human interaction with dial pad and screen
stage 3:
	code name: LAN
	does: implements network and stock tracking
stage 4:
	code name: made something up 1
	does: what ever we want, ie: paypal selling/confirmation by oyster
*/

