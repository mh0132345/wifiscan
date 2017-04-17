#include "wifiscan.h"
#include "screen.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
	while(1){
		system(CMD); //open "scan.txt" and visualize it;
		read_data();
		sleep(5);
	}
}
