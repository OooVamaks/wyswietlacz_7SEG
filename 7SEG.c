//Sterownie wyświetlaczem

#include <reg52.h>
#include <intrins.h>
#include "lcd.h"
#include "mkd51sim.h"
 unsigned char xdata PTWE _at_ 0x8008;   
 unsigned char xdata PTWY _at_ 0x8008;  
 unsigned char xdata PTSEG _at_ 0x8018;   

void wyswietl(int x);

int licznik=0;
int wcisniety=0;

void main(void) {
while(1){
	if(!(PTWE&16)) licznik=0;
	wyswietl(licznik);
	if(!(PTWE&32)&&wcisniety==0){
		wcisniety=1;
		licznik++;
		wyswietl(licznik);
		if (licznik>3) licznik=0;
	}
}
}

void wyswietl(int x){
	switch(x){
		case 0:
			PTWY=1;
			PTSEG=63;
		if(PTWE&32) wcisniety=0;
		break;
		case 1:
			PTWY=2;
			PTSEG=6;
		if(PTWE&32) wcisniety=0;
		break;
		case 2:
			PTWY=4;
			PTSEG=91;
		if(PTWE&32) wcisniety=0;
		break;
		case 3:
			PTWY=8;
			PTSEG=79;
		if(PTWE&32) wcisniety=0;
		break;
	}
}
