
// Пример отправки и приёма структуры через Serial
// ОТПРАВИТЕЛЬ
// Ардуины соединены так:
// отправитель D11 -> приёмник D10
#include "icos.h"
#include "settings.h"
#include <SoftwareSerial.h>
#include "DHT.h"
#include <TimerMs.h>
#include <GyverOLED.h>



TimerMs sendTMR(SEND_PERIOD);
TimerMs hcTMR(HC_PERIOD);
TimerMs blinkConTMR(BLINK_CON_PERIOD);
String strData = "";
boolean recievedFlag;
byte devic;
boolean IsconnectionB=1;

SoftwareSerial mySerial(RXPin, TXPin); // RX, TX
DHT dhtin(DHTINPIN, DHT11);
DHT dhtout(DHTOUTPIN, DHT11);
GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;
/*
  Данный код позволяет принять данные, идущие из порта, в строку (String) без "обрывов"
*/

struct Str {
  float inT;
  float inH;
  float outT;
  float outH;
  long light;
  long soilHum;
  long waterLevel;
  long isWent;
  long isHot;
  long isLight;
  long isWater;
  long isAuto;
};

float inT=0;
float inH=0;
float outT=0;
float outH=0;
long light=0;
long soilHum=0;
long waterLevel=0;
long isWent=0;
long isHot=0;
long isLight=0;
long isWater=0;
long isAuto=0;

Str buf;
int wifi=1;
int sd=0;
int camera=0;
int saved=0;
int isCon=0;

uint32_t lstCon = 0;
#define T_PERIOD 1000  // период переключения


void setup() {
  hcTMR.attach(HCSendByte);
  sendTMR.attach(UARTSend);
//  sendTMR.start();
//  hcTMR.start();
  blinkConTMR.attach(OLEDdrawCon);
  UARTBegin();
//  HCBegin();
//  GPIOBegin();
//  DHTBegin();
  OLEDBegin();
  OLEDdraw();
  blinkConTMR.start();
}

void loop() {
  OLEDdraw();
  OLEDdrawCon();
  delay(500);
}