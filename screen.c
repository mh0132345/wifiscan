#include "screen.h"
#include <stdio.h>

void display_channel(void){
	int i;
	for(i=1;i<=11;i++) printf("\t%d",i);
	printf("\n");
}
void setFGcolor(int fg){
	printf("\033[%d;1m", fg);
	fflush(stdout);
}

void resetColors(void){
	printf("\033[0m");
	fflush(stdout);
}

void gotoXY(int row, int col){
	printf("\033[%d;%dH", row, col);
	fflush(stdout);
}

void clearScreen(void){
	printf("\033[2J");
	fflush(stdout);
}

void displayBar(double rms, int col){
	int i;
	for(i=0; i<rms/100; i++){
		gotoXY(30-i-2, col);
#ifndef UNICODE
	printf("*");
#else
	printf("%s",BAR);
#endif
	}
	fflush(stdout);
}
