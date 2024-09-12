
void DHTBegin(){
  dhtin.begin();
  dhtout.begin();
}

void DHTGetData(){
  inT=dhtin.readTemperature();
  inH=dhtin.readHumidity();
  outT=dhtout.readTemperature();
  outH=dhtout.readHumidity();
}