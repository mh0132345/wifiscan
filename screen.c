#include "screen.h"
#include <stdio.h>

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

void drawRect(int top, int left, int height, int width){
	int i;
#ifdef UNICODE
	for(i=left; i<left+width; i++){
		gotoXY(top, i);
		printf("%s", BAR);
	}
	for(i=top; i<top+height; i++){
		gotoXY(i, left);
		printf("%s", BAR);
		gotoXY(i, left+width);
		printf("%s", BAR);
	}
#endif
}
