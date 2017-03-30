typedef struct{
	unsigned char MAC[6]; // 6 byte of MAC address
	int channel; //channel number 1-13
	double frequency; //frequency of this channel
	char essid[100]; //ESSID of network
	double slevel; //signal level in dBm
}WIFI_INFO;

#define CMD "sudo iwlist wlan0 scan | egrep \"Address|Frequency|ESSID|Quality\" > scan.txt" 

void read_data(void);
