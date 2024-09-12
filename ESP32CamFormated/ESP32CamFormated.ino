#include "settings.h"

#include "esp_camera.h"

#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

#include <WiFi.h>
#include <WiFiClient.h> 
#include <ESP32_FTPClient.h>

#include <NTPClient.h>
#include <WiFiUdp.h>

#include "FS.h"
#include "SD_MMC.h"
#include <SoftwareSerial.h>

#include <FastBot.h>

#include <TimerMs.h>

TimerMs con(CON_PERIOD);

ESP32_FTPClient ftp (ftp_server,ftp_user,ftp_pass);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

SoftwareSerial mySerial(12345, 16); // RX, TX

camera_config_t config;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  mySerial.begin(4000);
  con.attach(sendCheck);
  con.start();
  initWiFi(WIFI_SSID, WIFI_PASS);
//  initFTP(); 
  initMicroSDCard();
//  Serial.println(readFile(SD_MMC,"/test.txt"));
  configInitCamera();
  initNTP(GMT);
  initBot();

}

void loop() {
  // put your main code here, to run repeatedly:
  checkBot();
//  checkUART();
  delay(10);
}

void initWiFi(String ssid,String password){
  WiFi.begin(ssid,password);
  
  Serial.println("Connecting Wifi...");
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println("Connected");
}
