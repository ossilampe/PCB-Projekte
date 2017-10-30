#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

#define DEBUG 0
// set to 1 to print to serial monitor, 0 to disable
#include <Servo.h>
Servo headservo; // headservo
// Constants
const int EchoPin = 2; // Ultrasonic signal input
const int TrigPin = 3; // Ultrasonic signal output
const int leftmotorpin1 =8; // signal input of Dc motor driven plate
const int leftmotorpin2 =9;
const int rightmotorpin1 = 6;
const int rightmotorpin2 = 7;
const int HeadServopin = 10; // signal input of headservo
const int Sharppin = 11; // infrared output
const int maxStart = 800; //run dec time

// Variables
int isStart = maxStart;

//start
int currDist = 0;

// distance
boolean running = false;

  void setup() {
    
    
    Serial.begin(9600);
    lcd.init();                      // initialize the lcd 
    lcd.backlight();
    lcd.setCursor(3,0);
    lcd.print("ossilampe Ro);
    
  

//signal input port
  pinMode(EchoPin, INPUT);
  pinMode(Sharppin, INPUT);
//signal output port
  for (int pinindex = 3; pinindex < 11; pinindex++)
  {
    pinMode(pinindex, OUTPUT); // set pins 3 to 10 as outputs
  }
// headservo interface
  headservo.attach(HeadServopin);
//start buffer movable head
  headservo.write(70);
  delay(1000);
  headservo.write(20);
  delay(1000);
  }
    void loop() {
      
     
    if(DEBUG){
  Serial.print("running:");
  if(running){
  Serial.println("true");
  }
  
  else{
  Serial.println("false");
  }
 }
 
  if (isStart <= 0) {
  if(running){
  totalhalt();
// stop!
  }
  int findsomebody = digitalRead(Sharppin);
  if(DEBUG){
  Serial.print("findsomebody:");
  Serial.println(findsomebody);
  }
  if(findsomebody > 0) {
  isStart = maxStart;
  }
  delay(4000);
  return;
   }
    isStart--;
    delay(100);
    if(DEBUG){
    Serial.print("isStart: ");
    Serial.println(isStart);
   }
    currDist = MeasuringDistance(); //measure front distance
    if(DEBUG)
   {
    Serial.begin(9600);
    Serial.print("Current Distance: ");
    Serial.println(currDist);
    lcd.init();                      
    lcd.backlight();
    lcd.setCursor(8,1);
    lcd.print(currDist);
    lcd.setCursor(14,1);
    lcd.print("cm");
   }
    if(currDist > 50) {
    nodanger();
   }
    else if(currDist < 30){
    backup();
    randTrun();
  }
    else
   {
    //whichway();
    
    randTrun();
    }
}
//measure distance, unit “cm”

    long MeasuringDistance() {
    long duration;
    
//pinMode(TrigPin, OUTPUT);

    digitalWrite(TrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(TrigPin, LOW);
    
//pinMode(EchoPin, INPUT);

    duration = pulseIn(EchoPin, HIGH);
    return duration / 29 / 2;
    }
// forward

    void nodanger() 
    {
      running = true;
      digitalWrite(leftmotorpin1, HIGH);
      digitalWrite(leftmotorpin2, LOW);
      digitalWrite(rightmotorpin1, HIGH);
      digitalWrite(rightmotorpin2, LOW);
      return;
    }

//backward
    void backup() 
    {
      running = true;
      digitalWrite(leftmotorpin1, LOW);
      digitalWrite(leftmotorpin2, HIGH);
      digitalWrite(rightmotorpin1, LOW);
      digitalWrite(rightmotorpin2, HIGH);
      delay(1000);
    }

//choose way
     void whichway() 
    {
      running = true;
      totalhalt();
    
// first stop!

      headservo.write(20);
      delay(1000);
      int lDist = MeasuringDistance(); // check left distance
      totalhalt();
    
// probe recovering

      headservo.write(120); // turn the servo right
      delay(1000);
      int rDist = MeasuringDistance();  // check right distance
      totalhalt();

// probe recovering

      if(lDist < rDist) 
    {
      body_lturn();
    }
      else
    {
      body_rturn();
    }
    return;
    }
  
//remodulate to the original status mechanically

    void totalhalt() 
    {
      digitalWrite(leftmotorpin1, HIGH);
      digitalWrite(leftmotorpin2, HIGH);
      digitalWrite(rightmotorpin1, HIGH);
      digitalWrite(rightmotorpin2, HIGH);
      headservo.write(70); // set servo to face forward
      running = false;
      return;
      delay(1000);
    }
    
//turn left

    void body_lturn() 
    {
      running = true;
      digitalWrite(leftmotorpin1, LOW);
      digitalWrite(leftmotorpin2, HIGH);
      digitalWrite(rightmotorpin1, HIGH);
      digitalWrite(rightmotorpin2, LOW);
      delay(1500);
      totalhalt();
    }
    
//turn right

    void body_rturn() 
    {
      running = true;
      digitalWrite(leftmotorpin1, HIGH);
      digitalWrite(leftmotorpin2, LOW);
      digitalWrite(rightmotorpin1, LOW);
      digitalWrite(rightmotorpin2, HIGH);
      delay(1500);
      totalhalt();
    }
    
    void randTrun()
    {
      long randNumber;
      randomSeed(analogRead(0));
      randNumber = random(0, 10);
      if(randNumber > 5) {
      body_rturn();
    }
      else
    {
    body_lturn();
  }
}

