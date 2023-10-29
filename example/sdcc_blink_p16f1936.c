#include "pic16f1936.h"							//inculde MCU specific headers

#pragma config XINST=OFF							//good old instruction set, don't change this
#pragma config WDTEN = OFF							//we don't need WDT here
#pragma config FOSC = INTOSCIO						//internal oscillator, IO on RA6,7

volatile int i,j;						//declare them volatile, we don't want the compiler to optimize out the delay

void main(void) 
{
	OSCCON = 0x70;									//switch the internal oscillator to 16MHz
    ANSELC = 0;										//make all C IO digital
    TRISC = 0x00;									//and make them IO outputs
    while (1)
    {
        LATB = (LATB << 1) | (LATB >> 7);           // running light on port B
        LATC = ~ LATC;								//flip all C pins to opposite state
        for (i=0;i<20000;i++) j++;					//and burn some time
    }
    
}


