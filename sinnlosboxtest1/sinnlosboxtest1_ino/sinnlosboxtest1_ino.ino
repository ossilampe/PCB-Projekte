/*********************************************
*                                            *
*            http://www.ossilampe.de         *
*    Autor: Thomas Licht                     *
*    Mail:  tom@ossilampe.de                 *
*                                            *
*********************************************/



#include <Servo.h> 

  const int  buttonPin = 7;
  int ledred = 6;
  int ledgrn = 5;
  int ledblu = 4;
  int buttonState = 0;
 
  Servo tuerServo;
  Servo handServo;
  Servo fanServo;
 
  int pos = 0;
  long randNumber;
 
 
 
 
  void setup() 
  { 
    pinMode(ledred, OUTPUT);
    pinMode(ledgrn, OUTPUT);
    pinMode(ledblu, OUTPUT); 
    pinMode(buttonPin, INPUT);
    digitalWrite(ledgrn, HIGH);
    digitalWrite(ledred, HIGH);
    digitalWrite(ledblu, HIGH);
    // LED TEST
    digitalWrite(ledgrn, LOW);
    delay(300);
    digitalWrite(ledgrn, HIGH);
    digitalWrite(ledred, LOW);
    delay(300);
    digitalWrite(ledred, HIGH);
    digitalWrite(ledblu, LOW);
    delay(300);
    digitalWrite(ledblu, HIGH);
    delay(300);
    
    digitalWrite(ledgrn, LOW);
    delay(150);
    digitalWrite(ledgrn, HIGH);
    digitalWrite(ledred, LOW);
    delay(150);
    digitalWrite(ledred, HIGH);
    digitalWrite(ledblu, LOW);
    delay(150);
    digitalWrite(ledblu, HIGH);
    delay(150);
    
    digitalWrite(ledgrn, LOW);
    delay(150);
    digitalWrite(ledgrn, HIGH);
    digitalWrite(ledred, LOW);
    delay(150);
    digitalWrite(ledred, HIGH);
    digitalWrite(ledblu, LOW);
    delay(150);
    digitalWrite(ledblu, HIGH);
    delay(150);
    
    digitalWrite(ledgrn, LOW);
    delay(150);
    digitalWrite(ledgrn, HIGH);
    digitalWrite(ledred, LOW);
    delay(150);
    digitalWrite(ledred, HIGH);
    digitalWrite(ledblu, LOW);
    delay(150);
    digitalWrite(ledblu, HIGH);
    delay(150);
    
    digitalWrite(ledgrn, LOW);
    delay(150);
    digitalWrite(ledgrn, HIGH);
    digitalWrite(ledred, LOW);
    delay(150);
    digitalWrite(ledred, HIGH);
    digitalWrite(ledblu, LOW);
    delay(150);
    digitalWrite(ledblu, HIGH);
    delay(150);
    
    
    
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
    
 
     buttonState = digitalRead(buttonPin);  // Schalterposition Lesen
     if (buttonState == HIGH) {
     digitalWrite(ledgrn, HIGH);
     digitalWrite(ledred, HIGH);
     digitalWrite(ledblu, HIGH);
     handrausmodus();

     }
   
  }

