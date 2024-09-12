void drawMenu(){
  mySerial.print(String(WiFi.status() == WL_CONNECTED)+String(isSDcard)+String(isCamera)+String(isPhoto)+String(isFtp));
}