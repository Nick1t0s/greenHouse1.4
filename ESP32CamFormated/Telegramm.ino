FastBot bot(BOT_TOKEN);
camera_fb_t* frame;
void initBot(){
  bot.attach(newMsg);
}

void checkBot(){
  bot.tick();
}

void newMsg(FB_msg& msg){
  Serial.print(msg.chatID);     // ID чата 
  Serial.print(", ");
  Serial.print(msg.username);   // логин
  Serial.print(", ");
  Serial.println(msg.text);     // текст
  if (msg.text=="/start"){aStart(msg);}
  else if (msg.text=="Получить последние данные"){aGetLastData(msg);}
  else if (msg.text=="Запросить новые данные"){aRequestData(msg);}
  else if (msg.text=="Запросить фото"){aRequestPhoto(msg);}
  else if (msg.text=="Получить справку"){aGetHelp(msg);}
}

void aStart(FB_msg& msg){
  bot.sendMessage("Приветствую вас в боте для управления теплицей\nВы можете управлять теплицей при помощи кнопок и комманд", msg.chatID);
  bot.showMenu("Получить последние данные \t Запросить новые данные \t Запросить фото \n Получить справку", msg.chatID);
}

void aGetLastData(FB_msg& msg){
  if(inT != -43 && inH != -43 && isWent != -43){
    bot.sendMessage("Данные за " + lastFileName + ":",msg.chatID);
    sendData(msg.chatID);
  }
  else{
    bot.sendMessage("Данные еще не приходили",msg.chatID);
  }
}

void aRequestData(FB_msg& msg){
  bot.sendMessage("Данные запрошены, скоро они придут",msg.chatID);
  isTeleg=1;
  chatID=msg.chatID;
  Serial.println(isTeleg);
  requestData();
}

void aRequestPhoto(FB_msg& msg){
  frame = esp_camera_fb_get();
  esp_camera_fb_return(frame); // dispose the buffered image
  frame = NULL; // reset to capture errors
  frame = esp_camera_fb_get();
  if (frame) {
    bot.sendFile((byte*)frame->buf, frame->len, FB_PHOTO, "photo.jpg", msg.chatID);
    esp_camera_fb_return(frame);
  }
  else{
    bot.sendMessage("Произошла ошибка захвата камеры", msg.chatID);
  }
}

void aGetHelp(FB_msg& msg){
  bot.sendMessage("Помощь",msg.chatID);
}

void sendData(String id){
  String inTS = "Температура внутри: " + String(inT) + "\n";
  String inHS = "Влажность внутри: " + String(inH) + "\n";
  String outTS = "Температура снаружи: " + String(outT) + "\n";
  String outHS = "Влажность снаружи: " + String(outH) + "\n";
  String lightS = "Уровень свещение: " + String(light) + "\n";
  String waterLevelS = "Уровень воды в баке: " + String(waterLevel) + "\n";
  String soilHumS = "Влажность почвы: " + String(soilHum) + "\n";
  String isWentS = "Вентиляция: " + String(isWent) + "\n";
  String isHotS = "Подогрев: " + String(isHot) + "\n";
  String isLightS = "Искусственное освещение: " + String(isLight) + "\n";
  String isWaterS = "Помпа полива: " + String(isLight) + "\n";
  String isAutoS = "Автоуправление: " + String(isAuto);
  String resultMess =inTS + inHS + outTS + outHS + lightS + waterLevelS + soilHumS + isWentS + isHotS + isLightS + isWaterS + isAutoS;
  bot.sendMessage(resultMess,id);
}