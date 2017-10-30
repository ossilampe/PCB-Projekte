
#include <Servo.h> // Enables the Servo library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

  LiquidCrystal_I2C lcd(0x27,20,4);

    Servo PingServo;
    int minSafeDist = 11 ; // Minimum distance for ping sensor to know when to turn
    int pingPin = A0; // Ping sensor is connected to port A0
    int centerDist, leftDist, rightDist, backDist; // Define variables center, left, right and back distance
    long duration, inches, cm; // Define variables for Ping sensor


  void setup() 
  {
    PingServo.attach(10); // Servo is attached to pin 10 in the motor shield
    PingServo.write(90); // Center the Ping sensor (puts it at 90 degrees)
  //Setup Channel A
    pinMode(12, OUTPUT); //Initiates Motor Channel A pin
    pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
    pinMode(13, OUTPUT); //Initiates Motor Channel B pin
    pinMode(8, OUTPUT);  //Initiates Brake Channel B pin

  }

  void AllStop()  //Stop
  {
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  }
  
  void AllForward() //Vorwärts
  { 
   digitalWrite(12, HIGH); //Establishes forward direction of Channel A
   digitalWrite(13, HIGH); //Establishes forward direction of Channel A
    
  }
  
  void turnRight() //Rechtsrum
  { 
    digitalWrite(12, HIGH); //Establishes forward direction of Channel A
    analogWrite(11, 123);    //Spins the motor on Channel B at half speed
    delay(1600); // Time required to turn right (1.6 seconds)
    
  }
  
  void GoBack()  //zurück
  { 
    digitalWrite(12, LOW); //Establishes forward direction of Channel A
    digitalWrite(9, LOW);   //Disengage the Brake for Channel A
    analogWrite(3, 123);   //Spins the motor on Channel A at full speed
    digitalWrite(13, LOW);  //Establishes backward direction of Channel B
    digitalWrite(8, LOW);   //Disengage the Brake for Channel B
    analogWrite(11, 123);    //Spins the motor on Channel B at half speed
    delay(1600); // Time Required to go back (1.6 seconds)
    
  }
  
   void turnLeft() //Linksrum
   { 
     digitalWrite(12, HIGH); //Establishes forward direction of Channel A
     analogWrite(11, 123);    //Spins the motor on Channel B at half speed
     delay(1600); // Time required to turn right (1.6 seconds)
   
  }

// Starts the loop to decide what to do
  void loop()
  {
    LookAhead();
    Serial.print(inches);
    Serial.println(" inches"); // Prints a line in the serial monitor
    if(inches >= minSafeDist) /* If the inches in front of an object is greater than or equal to the minimum safe distance (11 inches), react*/
  {
    AllForward(); // All wheels forward
    delay(110); // Wait 0.11 seconds
  }
    else // If not:
  {
    AllStop(); // Stop all motors
    LookAround(); // Check your surroundings for best route
    if(rightDist > leftDist) // If the right distance is greater than the left distance , turn right
   {
    turnRight();
   }
     else if (leftDist > rightDist) // If the left distance is greater than the right distance , turn left
   {
    turnLeft();
   }
     else if (leftDist&&rightDist<minSafeDist) // If the left and right distance is smaller than the min safe distance (11 inch) go back
   {
     
    GoBack();
   }
  }
 }

unsigned long ping() 
  {
    pinMode(pingPin, OUTPUT); // Make the Pingpin to output
    digitalWrite(pingPin, LOW); //Send a low pulse
    delayMicroseconds(2); // wait for two microseconds
    digitalWrite(pingPin, HIGH); // Send a high pulse
    delayMicroseconds(5); // wait for 5 micro seconds
    digitalWrite(pingPin, LOW); // send a low pulse
    pinMode(pingPin,INPUT); // switch the Pingpin to input
    duration = pulseIn(pingPin, HIGH); //listen for echo

/*Convert micro seconds to Inches
-------------------------------------*/

    inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);
   }

    long microsecondsToInches(long microseconds) // converts time to a distance
  {
    return microseconds / 74 / 2;
  }
    long microsecondsToCentimeters(long microseconds) // converts time to a distance
  {
    return microseconds / 29 / 2;
  }

  void LookAhead() 
    {
      PingServo.write(90);// angle to look forward
      delay(175); // wait 0.175 seconds
      ping();
    }

  void LookAround()
    {
      PingServo.write(180); // 180° angle
      delay(320); // wait 0.32 seconds
      ping();
      rightDist = inches; //get the right distance
      PingServo.write(0); // look to the other side
      delay(620); // wait 0.62 seconds
      ping();
      leftDist = inches; // get the left distance
      PingServo.write(90); // 90° angle
      delay(275); // wait 0.275 seconds


}
