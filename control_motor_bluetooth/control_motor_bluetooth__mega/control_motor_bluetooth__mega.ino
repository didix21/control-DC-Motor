/*  This program consist in control two DC motors using a bluetooth module
 *  and Android App. This program have been disegned  for Arduino MEGA, but
 *  it can use Arduino UNO, too */


//Define PIN L298n
#define ENA 22
#define ENB 24
#define IN4 7
#define IN3 6
#define IN2 5
#define IN1 4

//Define Variables
boolean comFinished= false;
char syllable[5], data=0;
int i=0, j=0, x=0;
int pwmA = 0, pwmB = 0;
String strPwmA="", strPwmB="", enableMotor="";

void setup() {
  // put your setup code here, to run once:
  Serial2.begin(9600);
  Serial.begin(9600);
  pinMode(ENB, OUTPUT);
  pinMode(ENA, OUTPUT);
  strPwmA.reserve(10); // Reserve 10 bytes
  strPwmB.reserve(10);
}

void loop() {
 
  if(comFinished){ 
    if(syllable[0]=='A'||syllable[0]=='B'){//Check if data to enable motor A or B
      for(j=0; j<x; j++){
        enableMotor += syllable[j];
      }
      Serial.println(enableMotor); // Data that is sended from App is showed in Serial Monitor
      if(enableMotor=="AH"){ 
        digitalWrite(ENA,HIGH); //Enable Motor A
        Serial.println("Motor A ENABLED");
      }else if(enableMotor=="AL"){
        digitalWrite(ENA,LOW); //Disable Motor A
        analogWrite(IN2,0);
        analogWrite(IN1,0);
        Serial.println("Motor A DISABLED");
      }
      if(enableMotor=="BH"){
        digitalWrite(ENB,HIGH); //Enable Motor B
        Serial.println("Motor B ENABLED");
      }else if (enableMotor=="BL"){
        digitalWrite(ENB,LOW); //Disable Motor B
        analogWrite(IN4,0);
        analogWrite(IN3,0);
         Serial.println("Motor B DISABLED");
      }
      enableMotor="";
    }else if(syllable[0]=='a'){
      for(j=1; j<x; j++){
        strPwmA += syllable[j]; // Save data in a String
      }
      pwmA=strPwmA.toInt(); // Convert String to Integer
      // Control motor A's velocity and direction
      if(pwmA>=0){
        analogWrite(IN2,0);
        analogWrite(IN1,pwmA);
      }else if(pwmA<0){
        analogWrite(IN1,0);
        analogWrite(IN2,-pwmA);
      }
      Serial.print("PWMA= ");
      Serial.println(pwmA);
      
      strPwmA="";
    }else if(syllable[0]=='b'){
      for(j=1; j<x; j++){
        strPwmB += syllable[j];
      }
      pwmB=strPwmB.toInt();
      //Control motor's B velocity and direction
      if(pwmB>=0){
        analogWrite(IN4,0);
        analogWrite(IN3,pwmB);
      }else if(pwmB<0){
        analogWrite(IN3,0);
        analogWrite(IN4,-pwmB);
      }
      Serial.print("PWMB= ");
      Serial.println(pwmB);
      strPwmB="";
    }
    comFinished= false; 
  }
}



