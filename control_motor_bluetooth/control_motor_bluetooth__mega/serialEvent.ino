// Function that adquire data from Android App
void serialEvent2(){
  while(Serial2.available()) {
    data=(char)Serial2.read();    
    if (data != '\n'){
      syllable[i++]=data;   
    } else{
        comFinished = true; 
       x=i;
       i=0;
    }
  }
}
