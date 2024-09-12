void GPIOBegin(){
//  pinMode(xxx,OUTPUT);
}
void GPIOGetAnalog(){
  light=analogRead(lightPin);
  soilHum=analogRead(soilHumPin);
  waterLevel=analogRead(waterLevelPin);
}