-------------------------------------------------
https://github.com/mh0132345/wifiscan
OVERVIEW:
	An Inssider application to scan wifi
1. Configuration:
	1.1 Hardware configuration:

		A raspberry Pi 3 is recommended. If an older version of Pi is used, corresponding configuration might be changed

	1.2 Software configuration:
		
		If the wlan0 not the name of network, you may want to change it in wifiscan.h
		In command: #define CMD "sudo iwlist wlan0 scan | egrep \"Address|Frequency|ESSID|Quality\" > scan.txt" 
		
2. Installation instruction:

	a) Make a clone from my GitHub
	b) Open Terminal and change directory to source code folder. Change display to UTF-8.
	c) Use command "make" to compile and link all the source code

3. Opertating instruction:

	a) Run "./wifi.a" to run the program
	b) Open file "wave.h" and add line "#define DEBUG" to view in DEBUG mode. You can see the file infomation in text. 
	c) You can also open scan.txt in them same folder with source code to see infomation scaned
	d) To stop the program: press Crtl+C or Crtl+Z

4. Files include in this project:
	main.c	wifiscan.c	wifiscan.h	screen.h  screen.c  makefile README.md

5. Coppyright and licensing information:
	This is a open source project. No coppyright and licensing

6. Contact information for the distributor or programmer:
	Name: 	Le Minh Hoang
	Phone:  +358 469 451 195
	Email:  leminhhoang2509@gmail.com
	
7. Credit and acknowledgement:
	This project is made by following the instruction of Doctor Gao Chao, VAMK.
