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





#include <stdint.h>
#include "init.h"
#include "../tm4c1294ncpdt.h"

#define TOTALMOTORS 16

struct Motor {
	unsigned char status;
	unsigned char error;
};


struct Motor Motors[TOTALMOTORS];

/*!
\brief This function initializes ports: A C H K L M P Q 
    \param[in]      None
    \return         None
    \note
    \warning
*/
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

//output
void initPort_N(void){
	// activate clock for Port N (PN3, PN2)
  SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12;
	while((SYSCTL_PRGPIO_R&SYSCTL_RCGCGPIO_R12) == 0){};
		
	GPIO_PORTN_DIR_R &= ~0x0C;		//PN3, PN2 IN
	GPIO_PORTN_AFSEL_R &= ~0x0C;	// disable alt funct
	GPIO_PORTN_DEN_R |= 0x0C;			// enable digital I/O
	GPIO_PORTN_PCTL_R &= ~0x0000FF00;		//normal gpio on bits
	GPIO_PORTN_AMSEL_R &= ~0x0C;		// disable analog functionality on bits

}
//note: 
//after every write check/wait for 2-bit value before testing the next one
void testHW(void){

	
	GPIO_PORTA_DATA_R |= 0x80; //PA7
	
	GPIO_PORTC_DATA_R |= 0x40; //PC6
	GPIO_PORTC_DATA_R |= 0x80; //PC7
	
	GPIO_PORTH_DATA_R |= 0x02; //PH1
	GPIO_PORTH_DATA_R |= 0x04; //PH2
	GPIO_PORTH_DATA_R |= 0x08; //PH3
	
	GPIO_PORTK_DATA_R |= 0x40; //PK6
	GPIO_PORTK_DATA_R |= 0x80; //PK7
	
	GPIO_PORTL_DATA_R |= 0x01; //PL0
	GPIO_PORTL_DATA_R |= 0x02; //PL1
	GPIO_PORTL_DATA_R |= 0x04; //PL2
	GPIO_PORTL_DATA_R |= 0x08; //PL3
	
	GPIO_PORTM_DATA_R |= 0x40; //PM6
	
	GPIO_PORTP_DATA_R |= 0x08; //PP3
	GPIO_PORTP_DATA_R |= 0x20; //PP5
	
	GPIO_PORTQ_DATA_R |= 0x02; //PQ1
}

