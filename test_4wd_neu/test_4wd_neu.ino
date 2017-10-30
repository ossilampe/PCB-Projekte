/*************************************************************

*************************************************************/
#include <Servo.h> // Enables the Servo library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
 
 
Servo PingServo;
int pingPin = A0; // Ping sensor is connected to port A0
long duration, inches, cm; // Define variables for Ping sensor


void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel B pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel B pin
  
  PingServo.attach(10); // Servo is attached to pin 10 in the motor shield
  PingServo.write(90); // Center the Ping sensor (puts it at 90 degrees)


  void MotorStop()
  {
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A  
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  }
  
  
  
}

void loop(){

  
  //Motor A forward @ full speed
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed

  //Motor B backward @ half speed
  digitalWrite(13, LOW);  //Establishes backward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 123);    //Spins the motor on Channel B at half speed

  
  delay(3000);

  
  digitalWrite(9, HIGH);  //Engage the Brake for Channel A
  digitalWrite(9, HIGH);  //Engage the Brake for Channel B


  delay(1000);
  
  
  //Motor A forward @ full speed
  digitalWrite(12, LOW);  //Establishes backward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 123);    //Spins the motor on Channel A at half speed
  
  //Motor B forward @ full speed
  digitalWrite(13, HIGH); //Establishes forward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, 255);   //Spins the motor on Channel B at full speed
  
  
  delay(3000);
  
  
  digitalWrite(9, HIGH);  //Engage the Brake for Channel A
  digitalWrite(9, HIGH);  //Engage the Brake for Channel B
  
  
  delay(1000);
  
 
}
