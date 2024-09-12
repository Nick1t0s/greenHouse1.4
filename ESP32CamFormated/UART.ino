String strData;
boolean recievedFlag;

void checkUART(){
  while (Serial.available() > 0) {         // ПОКА есть что то на вход    
    strData += (char)Serial.read();        // забиваем строку принятыми данными
    recievedFlag = true;                   // поднять флаг что получили данные
    delay(2);                              // ЗАДЕРЖКА. Без неё работает некорректно!
  }
  if (recievedFlag) {                      // если данные получены
    Serial.println(strData);               // вывести
    if (isTeleg==0){
      saveData(strData);
      if (ftp.isConnected()){
        listDir(SD_MMC,"/",0);
      }
    }
    else{
      sendData(chatID);
      isTeleg=0;
    }
    strData = "";                          // очистить
    recievedFlag = false;                  // опустить флаг
  }
}

void sendCheck(){
  mySerial.print("1");
}

void requestData(){
  mySerial.print("getData");
}