#include "wifiscan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read_data(void){
	FILE *fp;
	WIFI_INFO wf;
	int c;
	char line[200];
	if((fp = fopen("scan.txt", "r")) == NULL){
		printf("Cannot open file %s\n", "scan.txt");
		return;
	} 
	while(fgets(line,200,fp)!=NULL){
#ifdef DEBUG
		printf("Line read;%s",line);
#endif 
		remove_spaces(line);
		if(strncmp(line,"Cell",4) == 0){
			c=0;
			get_MAC(line, wf.MAC);
		}
		else{
			c++;
			if(c==1){
				wf.frequency = get_freq(line);
				wf.channel = get_channel(line);
			} 
			if(c==2){
				wf.slevel = get_slevel(line);
			}
		  	if(c==3){
				get_essid(line, wf.essid);
			}
		} 
		if (c==3) display_network(wf);
	}
	fclose(fp);
	printf("Wifi data will be processed\n");
}

void display_network(WIFI_INFO wf){
	printf("MAC: %s\n",wf.MAC);
	printf("Channel: %d\n",wf.channel);
	printf("Frequency: %.3f GHz\n",wf.frequency);
	printf("Signal level: %.0f dBm\n", wf.slevel);
	printf("ESSID: %s\n\n", wf.essid); 
}

void remove_spaces(char s[]){
	int i, len = strlen(s);
	for(i=0;i<len;i++){
		if(s[i] != ' ' && s[i] !='\t' && s[i] !='\n') break;
	}
	strcpy(s,&s[i]);
	
}

//get MAC of a cell
void get_MAC(char line[],char mac[]){
	int i; //19 characters of cell and address:
	strncpy(mac,&line[19],17);
}

double get_freq(char line[]){
	double freq; 
	char *find;
	find = strstr (line,"Frequency");
	freq = atof(strncpy(line, find+10,5));
	 //freq = 2.413 for example, 10 is number of word we do not care
	return freq; 
}

int get_channel(char line[]){
	int channel;
	char *find;
	find = strstr(line, "Channel");
	channel = atoi(strncpy(line,find+8,1));
	return channel; 
}

double get_slevel(char line[]){
	char *find;
	find = strstr(line,"Signal level");
	double s_level = atof(strncpy(line,find+13,3));
	return s_level;
}

void get_essid(char line[], char essid[]){
	strcpy(essid,&line[7]); //Remove 7 characters: ESSID: in scan.txt
	essid[strlen(essid)-2] = '\0'; //Remove the last "
}
