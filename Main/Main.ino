/*
Full Project Link : https://shantonuacharjee.blogspot.com/2022/04/Arduino-smart-dustbin-with-chocolate-gift.html
Author  :- Shantonu Acharjee(Shanto)
Phone   :- +880 1789333514
Email   :- ShantonuAcharjee@gmail.com
Website :- https://tinyurl.com/y7drg9df
FaceBook Profile :- https://tinyurl.com/ydetnpqc
FaceBook Page-1  :- https://tinyurl.com/ybvwfrbn
FaceBook Page-2  :- https://tinyurl.com/y9zql7l8
YouTube-1 :- https://tinyurl.com/yf466yws
YouTube-2 :- https://tinyurl.com/yag3z37l
Linkedin  :- https://tinyurl.com/y9h5s32e
Github    :- https://tinyurl.com/ydypssmp
Instagram :- https://tinyurl.com/y3y7429m
Twitter   :- https://tinyurl.com/yadhkq9f
TikTok    :- https://tinyurl.com/y8pnh4mb
EasyEda   :- https://tinyurl.com/yagqwv7k
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


      
