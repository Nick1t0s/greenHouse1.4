void AUTOtick(){
  if (isAuto==1){
    if (inT>maxTemp){
      isWent=1;
    } 
    else{
      isWent=0;
    }
    if (inT<minTemp){
      isHot=1;
    }
    else{
      isHot=0;
    }
    if (soilHum>minSH){
      isWater=1;
    }
    else{
      isWater=0;
    }
    if (light>minLight){
      isLight=1;
    }
    else{
      isLight=0;
    }
  }
}