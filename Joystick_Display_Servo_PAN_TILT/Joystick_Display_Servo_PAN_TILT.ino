/*
Joystick
poti eins pin1 masse pin2 pin9 arduino pin 3 VCC
poti zwei pin1 masse pin2 pin8 arduino pin 3 VCC

mit button kann man licht des display einschalten 





*/



#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

const int servo1 = 9;       // first servo
const int servo2 = 8;       // second servo
const int joyH = 0;        // L/R Parallax Thumbstick
const int joyV = 1;        // U/D Parallax Thumbstick

int servoVal;           // variable to read the value from the analog pin

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

const int button2Pin = 1;     // the number of the pushbutton pin
const int ledPin =  7;      // the number of the LED pin

// Variables
int ledState = LOW;         // the current state of the output pin
int lastButtonState = LOW;   // the previous reading from the input pin



void setup() {

  // Servo 
  myservo1.attach(servo1);  // attaches the servo
  myservo2.attach(servo2);  // attaches the servo
 
lcd.begin(20, 4);
lcd.clear();


pinMode(button2Pin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Inizialize Serial
  Serial.begin(9600);
}


void loop()
{
  {
// read the state of the switch into a local variable:
int reading = digitalRead(button2Pin);
  
if (lastButtonState == LOW && reading == HIGH)
{
if (ledState == HIGH) {ledState = LOW;}
else {ledState = HIGH;}
digitalWrite(ledPin, ledState);}
lastButtonState = reading;
  }
 
lcd.setCursor(0, 0);{
lcd.print("---Mark  Wapenaar---");
} lcd.setCursor(0, 1);{
lcd.print("Arduino Uno Project");
}
lcd.setCursor(0, 2);
if(analogRead(0) == 511){
lcd.print("Camera STOPPED");
} else if(analogRead(0) < 509) {
lcd.print("Camera Down   ");
} else if(analogRead(0) > 513) {
lcd.print("Camera Up     ");
}
lcd.setCursor(0, 3);
if(analogRead(1) == 511){
lcd.print("Camera STOPPED");
} else if(analogRead(1) < 509) {
lcd.print("Camera Left   ");
} else if(analogRead(1) > 513) {
lcd.print("Camera Right  ");
}

// Display Joystick values using the serial monitor
outputJoystick();

// Read the horizontal joystick value  (value between 0 and 1023)
{
servoVal = analogRead(joyH);         
servoVal = map(servoVal, 0, 1021, 0, 180);}     // scale it to use it with the servo (result  between 0 and 180)
{
myservo2.write(servoVal);                         // sets the servo position according to the scaled value
}
delay(15);   

// Read the horizontal joystick value  (value between 0 and 1023)
{
servoVal = analogRead(joyV);}          
servoVal = map(servoVal, 0, 1021, 50, 180);     // scale it to use it with the servo (result between 70 and 180)
{
myservo1.write(servoVal);                           // sets the servo position according to the scaled value
}
delay(15);                                       // waits for the servo to get there

}


/**
* Display joystick values
*/
void outputJoystick(){

    Serial.print(analogRead(joyH));
    Serial.print ("---");
    Serial.print(analogRead(joyV));
    Serial.println ("----------------");
    //delay(500);
}
