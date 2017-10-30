#include <NewPing.h>
#include <Servo.h>

#define SENSOR_TRIG_PIN 7
#define SENSOR_ECHO_PIN 6
#define SENSOR_MIN_DIST 40
#define SENSOR_MAX_DIST 200

#define MOTOR_CH_A 12
#define BRAKE_CH_A 9
#define SPEED_CH_A 3

#define MOTOR_CH_B 13
#define BRAKE_CH_B 8
#define SPEED_CH_B 11

#define HI_SPEED 255
#define LO_SPEED 128

NewPing sonar(SENSOR_TRIG_PIN, SENSOR_ECHO_PIN, SENSOR_MAX_DIST);

// servo stuff:
int pos = 0;
int servoCenter = 45;
int servoRight = 90; // how far right? Max is 180, full right.
int servoLeft = 0; // how far left? Min is 0, full left.

Servo myservo; // create servo object to control a servo
// a maximum of eight servo objects can be created
void setup() {
Serial.begin(9600);

pinMode(MOTOR_CH_A, OUTPUT);
pinMode(BRAKE_CH_A, OUTPUT);
pinMode(SPEED_CH_A, OUTPUT);

pinMode(MOTOR_CH_B, OUTPUT);
pinMode(BRAKE_CH_B, OUTPUT);
pinMode(SPEED_CH_B, OUTPUT);

myservo.attach(5); // attaches the servo on pin 5 to the servo object
myservo.write(servoCenter); // center it by default
}

void loop() {
// delay(50);
int ping = sonar.ping_cm();
int dir;
Serial.println(ping);

if ( ping > SENSOR_MIN_DIST ) {
go_forward();
}

if ( ping <= SENSOR_MIN_DIST ) {

// if ( ping != 0 ) {
brake();
delay(20);
dir = go_look();
delay(20);
go_backwards();
delay(650);
// be smart about turn direction

if (dir = 1) {
Serial.println(“Left is blocked – going right.”);
Serial.println(dir);
turn_right();
delay(550);
}
if (dir = 2) {
Serial.println(“Right is blocked – going left.”);
Serial.println(dir);
turn_left();
delay(550);
}

brake();
delay(20);
// }

 

}
}

int go_look () {
// look both ways for better path
myservo.write(servoRight);
int anglel = myservo.read();
Serial.println(anglel);

delay(1000);

myservo.write(servoLeft);
int angler = myservo.read();
Serial.println(angler);
delay(1000);

myservo.write(servoCenter);
int anglec = myservo.read();
Serial.println(anglec);

if ( anglel <= SENSOR_MIN_DIST ) {
return 1;
}
if ( angler <= SENSOR_MIN_DIST ) {
return 2;
}
}

void go_forward() {
Serial.println(“Going forward…”);

digitalWrite(MOTOR_CH_A, HIGH);
digitalWrite(BRAKE_CH_A, LOW);
analogWrite(SPEED_CH_A, HI_SPEED);

digitalWrite(MOTOR_CH_B, HIGH);
digitalWrite(BRAKE_CH_B, LOW);
analogWrite(SPEED_CH_B, HI_SPEED);
}

void go_backwards() {
Serial.println(“Going back…”);

digitalWrite(MOTOR_CH_A, LOW);
digitalWrite(BRAKE_CH_A, LOW);
analogWrite(SPEED_CH_A, LO_SPEED);

digitalWrite(MOTOR_CH_B, LOW);
digitalWrite(BRAKE_CH_B, LOW);
analogWrite(SPEED_CH_B, HI_SPEED);
}

void turn_left() {
Serial.println(“Going left…”);
digitalWrite(BRAKE_CH_A, LOW);
analogWrite(SPEED_CH_A, HI_SPEED);
digitalWrite(MOTOR_CH_B, HIGH);
digitalWrite(BRAKE_CH_B, LOW);
analogWrite(SPEED_CH_B, HI_SPEED);
}

void turn_right() {
Serial.println(“Going right…”);

digitalWrite(MOTOR_CH_A, HIGH);
digitalWrite(BRAKE_CH_A, LOW);
analogWrite(SPEED_CH_A, HI_SPEED);
digitalWrite(BRAKE_CH_B, LOW);
analogWrite(SPEED_CH_B, HI_SPEED);
}

void brake() {
Serial.println(“Braking…”);

digitalWrite(BRAKE_CH_A, HIGH);
digitalWrite(BRAKE_CH_B, HIGH);
}
