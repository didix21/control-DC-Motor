// Function that adquire data from Android App
void serialEvent(){
  while(Serial.available()) {
    data=(char)Serial.read();
   
    if (data != '\n'){
      syllable[i++]=data;
   
    } else{
        comFinished = true;
       x=i;
       i=0;
    }
   
  }
}
