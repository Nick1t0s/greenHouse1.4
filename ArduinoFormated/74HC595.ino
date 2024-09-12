

void HCBegin(){
  pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	digitalWrite(latchPin, LOW);
}

void HCGenereteByte(){ // При bitPos=0 получим B00000001, при bitPos=1 - B00000010, при bitPos=2 - B00000100 и т.д.
  devic=0;
  if(isWent==1) bitWrite(devic, 7, HIGH);
  else bitWrite(devic, 7, LOW);

  if(isHot==1) bitWrite(devic, 3, HIGH);
  else bitWrite(devic, 3, LOW);

  if(isLight==1) bitWrite(devic, 5, HIGH);
  else bitWrite(devic, 5, LOW);

  if (isWater == 1) bitWrite(devic, 1, HIGH);
  else bitWrite(devic, 1, LOW);
//  bitWrite(devic, 4, LOW); // При bitPos=0 получим B00000001, при bitPos=1 - B00000010, при bitPos=2 - B00000100 и т.д.
//  bitWrite(devic, 3, LOW); // При bitPos=0 получим B00000001, при bitPos=1 - B00000010, при bitPos=2 - B00000100 и т.д.
//  bitWrite(devic, 2, LOW); // При bitPos=0 получим B00000001, при bitPos=1 - B00000010, при bitPos=2 - B00000100 и т.д.
//  bitWrite(devic, 0, LOW); // При bitPos=0 получим B00000001, при bitPos=1 - B00000010, при bitPos=2 - B00000100 и т.д.
//  Serial.println(devic,BIN);
  Serial.println(isWent);
  Serial.println(isHot);
  Serial.println(isLight);
  Serial.println(isWater);
}

void HCSendByte(){
    digitalWrite(latchPin, LOW); // начинаем передачу данных
	  shiftOut(dataPin, clockPin, LSBFIRST, devic); // устанавливаем нужный байт
	  digitalWrite(latchPin, HIGH); // прекращаем передачу данных
}