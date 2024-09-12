

void UARTBegin(){
  Serial.begin(115200);
  mySerial.begin(115200);
}

void UARTGenerateBuf(){
  buf.inT = inT;
  buf.inH = inH;
  buf.outT = outT;
  buf.outH = outH;
  buf.light = light;
  buf.soilHum = soilHum;
  buf.waterLevel = waterLevel;
  buf.isWent = isWent;
  buf.isHot = isHot;
  buf.isLight = isLight;
  buf.isWater = isWater;
  buf.isAuto = isAuto;
}

void UARTSendBuf(){
  mySerial.write((byte*)&buf, sizeof(buf));
  Serial.println("sendDone");
}

void UARTSend(){
  UARTGenerateBuf();
  UARTSendBuf();
}

void UARTcheck(){
  while (mySerial.available() > 0) {         // ПОКА есть что то на вход    
    strData += (char)mySerial.read();        // забиваем строку принятыми данными
    recievedFlag = true;                   // поднять флаг что получили данные
    delay(2);                              // ЗАДЕРЖКА. Без неё работает некорректно!
    Serial.println("dsgffg");
    
  }
  if (recievedFlag) {                      // если данные получены
       
    Serial.println("ds43gffgfdsgshdhgfhhjgfdf");                // опустить флаг
    Serial.print(strData);
    if(strData="1"){
      mySerial.print("1");
      lstCon=millis();
    }
    else if(strData=="onWent"){
      isWent=1;
      Serial.println("onWent");
    }
    else if(strData=="onHot"){
      isHot=1;
      Serial.println("onHot");
    }
    else if(strData=="onLight"){
      isLight=1;
      Serial.println("onLight");
    }
    else if(strData=="onWater"){
      isWater=1;
      Serial.println("onWater");
    }
    else if(strData=="onAuto"){
      isAuto=1;
      Serial.println("onAuto");
    }
    else if(strData=="offWent"){
      isWent=0;
      Serial.println("offWent");
    }
    else if(strData=="offHot"){
      isHot=0;
      Serial.println("offHot");
    }
    else if(strData=="offLight"){
      isLight=0;
      Serial.println("offLight");
    }
    else if(strData=="offWater"){
      isWater=0;
      Serial.println("offWater");
    }
    else if(strData=="offAuto"){
      isAuto=0;
      Serial.println("offAuto");
    }
    else if(strData=="getData"){
      UARTSend();
      Serial.println("data sended");
    }
    else if(strData.indexOf(";")!=1){//wifi;camera;sd;saved;data
      wifi=strData.substring(0,1).toInt();
      camera=strData.substring(2,3).toInt();
      sd=strData.substring(4,5).toInt();
      saved=strData.substring(6,7).toInt();

    }
    strData = "";                          // очистить
    recievedFlag = false;  
  }
}