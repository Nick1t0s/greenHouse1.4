
void OLEDBegin(){
  oled.init();
  oled.clear();
}

void OLEDdraw(){
  oled.clear();
  if (wifi) oled.drawBitmap(112, 0, Wifi, 16, 16);
  else oled.drawBitmap(112, 0, notWifi, 16, 16);
  if (camera) oled.drawBitmap(94, 0, Cam, 16,16);
  else oled.drawBitmap(94, 0, notCam, 16,16);
  
  if (saved) oled.drawBitmap(74, 0, Saved, 16, 16);
  else oled.drawBitmap(74, 0, notSaved, 16, 16);

  if (sd) oled.drawBitmap(54, 0, Sd, 16, 16);
  else oled.drawBitmap(54, 0, notSd, 16, 16);
}

void OLEDdrawCon(){
  if(millis()-lstCon>CON_PERIOD){
    IsconnectionB=!IsconnectionB;
    if(IsconnectionB) oled.drawBitmap(34,0,connection,16,16);
    else oled.rect(34, 0, 53, 16, 0);
    Serial.println(IsconnectionB);
  }
  else{
    oled.drawBitmap(34,0,connection,16,16);
}