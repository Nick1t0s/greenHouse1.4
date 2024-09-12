#define minTemp 20
#define maxTemp 30
#define minSH 100
#define minLight 200
#define minWaterLevel 250

#define SEND_PERIOD 15000
#define HC_PERIOD 500

#define dataPin 4   // к выводу 14 регистра SD
#define clockPin 6  // к выводу 11 регистра (SH_CP)
#define latchPin 5  // к выводу 12 регистра (ST_CP)

#define DHTINPIN 7
#define DHTOUTPIN 8

#define lightPin A0
#define soilHumPin A1
#define waterLevelPin A2

#define RXPin 2
#define TXPin 3

#define CON_PERIOD 500