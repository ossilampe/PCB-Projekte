#include <AFMotor.h> // Enables the Motor library
#include <Servo.h> // Enables the Servo library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

  LiquidCrystal_I2C lcd(0x27,20,4);

    Servo PingServo;
    AF_DCMotor motor1(1); // Motor 1 is connected to the port 1 on the motor shield
    AF_DCMotor motor2(2); // Motor 2 is connected to the port 2 on the motor shield
    AF_DCMotor motor3(3); // Motor 3 is connected to the port 3 on the motor shield
    AF_DCMotor motor4(4); // Motor 4 is connected to the port 4 on the motor shield
    int minSafeDist = 11 ; // Minimum distance for ping sensor to know when to turn
    int pingPin = A0; // Ping sensor is connected to port A0
    int centerDist, leftDist, rightDist, backDist; // Define variables center, left, right and back distance
    long duration, inches, cm; // Define variables for Ping sensor


  void setup() 
  {
    PingServo.attach(10); // Servo is attached to pin 10 in the motor shield
    PingServo.write(90); // Center the Ping sensor (puts it at 90 degrees)
    motor1.setSpeed(215); // Sets the speed of the first motor (At 0, the motors are turned off. 255 is the fastest setting that you are able to use, I used 215 to not push the motors too hard.)
    motor2.setSpeed(215); // Sets the speed of the second motor (At 0, the motors are turned off. 255 is the fastest setting that you are able to use, I used 215 to not push the motors too hard.)
    motor3.setSpeed(215); // Sets the speed of the first motor (At 0, the motors are turned off. 255 is the fastest setting that you are able to use, I used 215 to not push the motors too hard.)
    motor4.setSpeed(215); // Sets the speed of the second motor (At 0, the motors are turned off. 255 is the fastest setting that you are able to use, I used 215 to not push the motors too hard.)


    Serial.begin(9600); 
    Serial.println("Serial test!"); 
    lcd.init();                      
    lcd.init();
    lcd.backlight();
    lcd.setCursor(3,0);
    lcd.print("ossilampe robot");
    lcd.setCursor(3,3);
    lcd.print(">>>ACHTUNG<<<");
    delay(1000);
    lcd.setCursor(10,2);
    lcd.print("s");
    lcd.setCursor(9,2);
    lcd.print("4");
    delay(1000);
    lcd.setCursor(9,2);
    lcd.print("3");
    delay(1000);
    lcd.setCursor(9,2);
    lcd.print("2");
    delay(1000);
    lcd.setCursor(9,2);
    lcd.print("GO");
    delay(2000);
    lcd.setCursor(8,2);
    lcd.print("   ");
    lcd.setCursor(3,3);
    lcd.print("              ");
  }

  void AllStop() 
  {
    motor1.run(RELEASE); // Turns off motor 1
    motor2.run(RELEASE); // Turns off motor 2
    motor3.run(RELEASE); // Turns off motor 3
    motor4.run(RELEASE); // Turns off motor 4
  }
  
  void AllForward() 
  { // Makes the robot go forward
    motor1.run(FORWARD); // Motor 1 goes forward
    motor2.run(FORWARD); // Motor 2 goes forward
    motor3.run(FORWARD); // Motor 3 goes forward
    motor4.run(FORWARD); // Motor 4 goes forward
    Serial.println("Going forward"); // Prints a line in the serial monitor
    lcd.setCursor(1,0);
    lcd.print("Roboter gerade aus  ");
  }
  
  void turnRight() 
  { // Makes the robot go right
    motor2.run(BACKWARD); // Turns off motor 2
    motor1.run(FORWARD); // Motor 1 goes forward
    motor3.run(FORWARD); // Motor 1 goes forward
    motor4.run(BACKWARD); // Turns off motor 2
    delay(1600); // Time required to turn right (1.6 seconds)
    Serial.println("Motors going Right"); // Prints a line in the serial monitor
    lcd.setCursor(1,0);
    lcd.print("Roboter nach rechts ");
  }
  
  void GoBack()
  { // Makes the robot go back
    motor2.run(BACKWARD); // Motor 2 goes back
    motor1.run(BACKWARD); // Motor 1 goes back
    motor3.run(BACKWARD); // Motor 3 goes back
    motor4.run(BACKWARD); // Motor 4 goes back
    delay(1600); // Time Required to go back (1.6 seconds)
    Serial.println("Backward"); // Prints a line in the serial monitor
    lcd.setCursor(1,0);
    lcd.print("Roboter Rueckwaerts ");
  }
  
   void turnLeft() 
   { // Makes the robot go Left
    motor2.run(FORWARD); // Motor 2 goes forward
    motor1.run(BACKWARD); // turns off motor 1
    motor3.run(BACKWARD); // turns off motor3
    motor4.run(FORWARD); // Motor 4 goes forward
    delay(1600); //Time Required to turn left (1.6)Seconds
    Serial.println("Motors going Left");// Prints a line in the serial monitor
    lcd.setCursor(1,0);
    lcd.print("Roboter nach links   ");
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

// Prints a line in the serial monitor
    Serial.print("RightDist: ");
    Serial.println(rightDist);
    Serial.print("LeftDist: ");
    Serial.println(leftDist);
    Serial.print("CenterDist: ");
    Serial.println(centerDist);
    lcd.setCursor(2,1);
    lcd.print("Vorwaerts");
    lcd.setCursor(12,1);
    lcd.print(rightDist);
    lcd.setCursor(15,1);
    lcd.print(" cm ");
    lcd.setCursor(2,2);
    lcd.print("Links");
    lcd.setCursor(12,2);
    lcd.print(leftDist);
    lcd.setCursor(15,2);
    lcd.print(" cm ");
    lcd.setCursor(2,3);
    lcd.print("Rechts");
    lcd.setCursor(12,3);
    lcd.print(centerDist);
    lcd.setCursor(15,3);
    lcd.print(" cm ");
}
