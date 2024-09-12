#define WIFI_SSID "ASUS21G"
#define WIFI_PASS "Asus164w"

#define PWDN_GPIO_NUM 32
#define RESET_GPIO_NUM -1
#define XCLK_GPIO_NUM 0
#define SIOD_GPIO_NUM 26
#define SIOC_GPIO_NUM 27
#define Y9_GPIO_NUM 35
#define Y8_GPIO_NUM 34
#define Y7_GPIO_NUM 39
#define Y6_GPIO_NUM 36
#define Y5_GPIO_NUM 21
#define Y4_GPIO_NUM 19
#define Y3_GPIO_NUM 18
#define Y2_GPIO_NUM 5
#define VSYNC_GPIO_NUM 25
#define HREF_GPIO_NUM 23
#define PCLK_GPIO_NUM 22

#define BOT_TOKEN "7543909116:AAHSUMY_eVJX1jCWAr_hGCluNko4ybPDGl0"

#define CON_PERIOD 400

char ftp_server[] = "192.168.0.77";
char ftp_user[]   = "Lidiya";
char ftp_pass[]   = "labora1";

int GMT = 0;
int isSDcard;
int isCamera;
int isPhoto;
int isWritedFile;
int isFtp;
uint32_t lstCon = 0;


String chatID;
String lastFileName = "0123";


byte isTeleg=0;


struct Str {
  float inT;
  float inH;
  float outT;
  float outH;
  int light;
  int soilHum;
  int waterLevel;
  int isWent;
  int isHot;
  int isLight;
  int isWater;
  int isAuto;
};

float inT=-43;
float inH=-43;
float outT=-43;
float outH=-43;
int light=-43;
int soilHum=-43;
int waterLevel=-43;
int isWent=-43;
int isHot=-43;
int isLight=-43;
int isWater=-43;
int isAuto=-43;