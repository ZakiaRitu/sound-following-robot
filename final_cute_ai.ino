String voice;
#include <SoftwareSerial.h>
#include <NewPing.h>

SoftwareSerial mySerial(14, 15); // RX, TX
#define TRIGGER_PIN  17  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     16  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200
int sound;
int s ;
unsigned long previousMillis = 0; 
const long interval = 1000;
unsigned long t, t1;
int distance;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void sonarm()
{
  unsigned int uS = sonar.ping();
   distance = uS / US_ROUNDTRIP_CM;
}
  

 


int lmf=8,
    rmf=13,
    lmb=9,
    rmb=12,
 
    lme=10,
    rme=11;
   
    void st(){
  digitalWrite(lmf, LOW);
  digitalWrite(rmf, LOW);
  digitalWrite(lmb, LOW);
  digitalWrite(rmb, LOW);
  
}

void sl(){
     
  digitalWrite(lmf, LOW);
  digitalWrite(rmf, HIGH);
  digitalWrite(lmb, HIGH);
  digitalWrite(rmb, LOW);
  
}

void sr(){
  digitalWrite(lmf, HIGH);
  digitalWrite(rmf, LOW);
  digitalWrite(lmb, LOW);
  digitalWrite(rmb, HIGH);
}

void fr(){
  digitalWrite(lmf, HIGH);
  digitalWrite(rmf, HIGH);
  digitalWrite(lmb, LOW);
  digitalWrite(rmb, LOW);
  
}
void br(){
  digitalWrite(lmf, LOW);
  digitalWrite(rmf, LOW);
  digitalWrite(lmb, HIGH);
  digitalWrite(rmb, HIGH);
  } 
  
  void forward()
  {
     
    analogWrite(lme, 110);
    analogWrite(rme, 120);
    
    fr();
    

  }
 
    

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  mySerial.begin(9600);
  
  //forward();


    


}
//-----------------------------------------------------------------------// 
void loop() {
 sonarm();
    if(distance>8 && distance <25)
    {
      delay(200);
          if(distance>8 && distance <15)
    {
      delay(200);
            if(distance>8 && distance <15)
    {
      analogWrite(lme, 150);
      analogWrite(rme,150);
      br();
      delay(50);
      st();
      delay(1000);
      
    }
  }
    }
         
  
  while (mySerial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = mySerial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
 /*  sound = analogRead(A2);
   Serial.println(sound);
   delay(50);
  /*if(sound >10 && sound <30){
   Serial.println("forward");
    analogWrite(lme, 120);
    analogWrite(rme, 120);   
    fr();
    delay(300);
    analogWrite(lme, 180);
    analogWrite(rme, 180);  
    br();
    delay(50);
    analogWrite(lme, 0);
    analogWrite(rme, 0);
    st();
    delay(300);

 }
 unsigned long currentMillis = millis();
 if(sound >10 && sound <90){

   
   unsigned long currentMillis = millis();
   if( currentMillis-t<=500 || currentMillis-t1<=500){
    Serial.println("backward");
    analogWrite(lme, 120);
    analogWrite(rme, 120);   
    br();
    delay(300);
    analogWrite(lme, 180);
    analogWrite(rme, 180);  
    fr();
    delay(50);
    analogWrite(lme, 0);
    analogWrite(rme, 0);
    st();
    delay(300);}
    else{
      
         
      Serial.println("okay");
     
    analogWrite(lme, 120);
    analogWrite(rme, 120);   
    fr();
    delay(300);
    analogWrite(lme, 180);
    analogWrite(rme, 180);  
    br();
    delay(50);
    analogWrite(lme, 0);
    analogWrite(rme, 0);
    st();
    delay(300); 
     t1 = currentMillis-650;
    }
    
    
   t = currentMillis;
   delay(200);

     
 }
 
 
 */
 
 
 
   
  
  
 

  
  if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//   
 
if(voice == "*forward") 
  {
   
    forward();
   

  } 

  
  
  if(voice == "*back") 
  {
     analogWrite(lme, 150);
    analogWrite(rme, 130);
    
    sr();
    delay(400);
     st();
    delay(100);
        analogWrite(lme, 100);
    analogWrite(rme, 0);
    
    br();
    delay(50);
    st();
    delay(100);
  }
  
  if (voice == "*turn right")
  {
     analogWrite(lme, 150);
    analogWrite(rme, 130);
    
    sr();
    delay(270);
     st();
    delay(100);
        analogWrite(lme, 100);
    analogWrite(rme, 0);
    
    br();
    delay(50);
    st();
    delay(100);
    
  }
  
  if (voice == "*turn left")
 {
    analogWrite(lme, 150);
    analogWrite(rme, 130);
    
    sl();
    delay(270);
     st();
    delay(100);
        analogWrite(lme, 0);
    analogWrite(rme, 100);
    
    br();
    delay(50);
    st();
    delay(100);
 }
 
  if (voice == "*stop")
 {
analogWrite(lme, 120);
      analogWrite(rme, 120);
     
      br();
      delay(50);
      analogWrite(lme, 0);
      analogWrite(rme, 0);
 }
 
  if (voice == "*left")
 {
       analogWrite(lme, 100);
    analogWrite(rme, 120);
   
    fr();
 }
 
   if (voice == "*right")
 {
       analogWrite(lme, 120);
    analogWrite(rme, 100);
   
    fr();
 }
 

   
 
   

voice="";}

}

