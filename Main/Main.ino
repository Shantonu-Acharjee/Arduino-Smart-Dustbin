/*
Project Name :- Smart Dustbin
Full Project Link :- https://tinyurl.com/y8r5y3ph
Github Project Link :- https://tinyurl.com/ybdpm8jk


Author:- Shantonu Acharjee
Email:- shantonuacharjee@gmail.com
YouTube :- https://tinyurl.com/yf466yws
FaceBook Page:- https://tinyurl.com/ybvwfrbn
*/





#include <Servo.h>
Servo myservo;  
Servo myservoB;
   
int trigPinA =A5;
int echoPinA =A4;
long durationA;
int distanceA;

int trigPinB =A3;
int echoPinB =A2;
long durationB;
int distanceB;


int a = 0;
int b = 0;

void setup() {
  
  pinMode(trigPinA,OUTPUT);
  pinMode(echoPinA,INPUT);

  pinMode(trigPinB,OUTPUT);
  pinMode(echoPinB,INPUT);
  
  
  myservo.attach(9);
  myservoB.attach(10);
}



void loop() {
  
  
   digitalWrite(trigPinA,LOW);
   delayMicroseconds(2);
   digitalWrite(trigPinA,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPinA,LOW);
   durationA=pulseIn(echoPinA,HIGH);
   distanceA = durationA*0.034/2;
   






   digitalWrite(trigPinB,LOW);
   delayMicroseconds(2);
   digitalWrite(trigPinB,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPinB,LOW);
   durationB=pulseIn(echoPinB,HIGH);
   distanceB = durationB*0.034/2;
   



  //Dustbin Door
  if(distanceA < 15 && b == 0){
     myservo.write(90); 
     b = 1;
     
   }




   

   /*
  
  if(distanceA > 16){
    myservo.write(0); 
     
  }

  */


  
  // For chocolate
  if(distanceB < 15 && a == 0 && b == 1){
    myservo.write(0); 
    myservoB.write(90); 
    delay(400);
    myservoB.write(0);
    a = 1;
    b = 0;
  }
  
  if(distanceB > 16){
    myservoB.write(0);
    a = 0;
  }

  
  
  //Serial.print("distanceA:");
  //Serial.println(distanceA);
  
  //Serial.print("distanceB:");
  //Serial.println(distanceB);


}//End Loop


      
