typedef struct{
	unsigned char MAC[17]; // 6 byte of MAC address
	int channel; //channel number 1-13
	double frequency; //frequency of this channel
	char essid[100]; //ESSID of network
	double slevel; //signal level in dBm
}WIFI_INFO;

// #define DEBUG
#define CMD "sudo iwlist wlan0 scan | egrep \"Address|Frequency|ESSID|Quality\" > scan.txt" 

void read_data(void);
void remove_spaces(char[]);
void get_MAC(char [], char []);
double get_freq(char []);
double get_slevel(char[]);
void get_essid(char[],char[]);
void display_network(WIFI_INFO);
