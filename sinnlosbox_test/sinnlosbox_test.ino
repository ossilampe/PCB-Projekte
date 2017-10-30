#include <Servo.h> 
  #define PIN 6
 
 
 
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
     digitalWrite(ledred, HIGH);
 
      handrausmodus();
  
 
    }
    else{
     digitalWrite(ledred, LOW); 
     handreinmodus();
 
    } 
  }

