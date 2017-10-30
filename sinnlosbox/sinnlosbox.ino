/*********************************************
*                                            *
*            http://www.ossilampe.de         *
*    Autor: Thomas Licht                     *
*    Mail:  tom@ossilampe.de                 *
*                                            *
*********************************************/

#include <Servo.h> 
  #define PIN 6
 
 
 
  const int  buttonPin = 7;

  const int ledPin =  13;
  int buttonState = 0;
 
  Servo tuerServo;
  Servo handServo;
  Servo fanServo;
 
  int pos = 0;
  long randNumber;
 
 
 
 
  void setup() 
  { 
    pinMode(ledPin, OUTPUT); 
    pinMode(buttonPin, INPUT);
    
    randomSeed(analogRead(0));
    Serial.begin(9600);
 
    tuerServo.attach(10);         //Handservo Pin 10
    handServo.attach(9);          //Handservo Pin 9
    fanServo.attach(11);         //Fahneservo Pin 11
    tuerServo.write(10);          //Türservo startposition 
    handServo.write(150);         //Handservo startposition
    fanServo.write(145);           //Fahneservo startposition 
  } 
 
 
  void loop() 
  { 
    randNumber = random(17);
    delay(100);
    Serial.println(randNumber);
 
     buttonState = digitalRead(buttonPin);  // Schalterposition Lesen
     if (buttonState == HIGH) {
     digitalWrite(ledPin, HIGH);
 
      if (randNumber == 0) {handrausmodus();}
     else if (randNumber == 1) {fanwinkimodus();} 
     else if (randNumber == 2) {handrausmodus();}
     else if (randNumber == 3) {handrausmodus();}
     else if (randNumber == 4) {tuermodus();}
     else if (randNumber == 5) {handrausmodus();}
     else if (randNumber == 8) {handrausmodusslow();}
     else if (randNumber == 9) {handrausmodus();}
     else if (randNumber == 11) {handrausmodus();}
     else if (randNumber == 13) {tuermodus1();}
     else if (randNumber == 14) {handrausmodus();}
     else if (randNumber == 15) {fanwinkimodus1();}
     else if (randNumber == 16) {handrausmodus1();}
 
    }
    else{
     digitalWrite(ledPin, LOW); 
     handreinmodus();
 
    } 
  }

