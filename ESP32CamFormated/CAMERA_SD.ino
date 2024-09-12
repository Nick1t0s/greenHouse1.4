void saveData(String data){
  lastFileName=getFileName();
  isPhoto = takeSavePhoto(lastFileName+".jpg");
  isWritedFile = writeFile(SD_MMC,converter(lastFileName+".txt"),converter(data));
}