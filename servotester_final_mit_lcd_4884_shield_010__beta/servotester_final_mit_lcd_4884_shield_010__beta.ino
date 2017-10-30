//*************************************************************************************************************
// Receiver and Servo PWM Testset               by Airpac - Lars Rotermundt Avionic
//*************************************************************************************************************

//digital out pin 2-8 display
//digital out pin 9 writes servo
//digital in  pin 10-13 read RX Channels 1-4  
//analog  in  pin A3-A5 read RX Channels 3-7  
//analog  in  pin A2 read RX Channel 8        
//analog in   pin A0 steers the menue

//signal width 580-2400 us - middle position 1500 us
//if receiverchannel without input it will become 1500 by default
//servo output is mixed with channel 1-8 in combinated mode  x indicates the binded channel
//Servo 20ms PWM with is created by the Servo PWM library not by any delay in the loop
//loop delays will delay the servo refreshrate negative
//rx and servo are powered from tester
//welcome menu: last selected mode  will be safed
//servo menu: last step & delay setting will be safed   servo out is recenterd to 1500 us
//
//Servo Startposition after restart is defiend in the servo librarie:
//#define DEFAULT_PULSE_WIDTH  1500     // default pulse width when servo is attached
//so modify as u like the servo.h file
//*************************************************************************************************************
//
//*************************************************************************************************************

#include <Wire.h>  // Comes with Arduino IDE
// include 14 * 6 serial 4884 lcd display shield by sainsmart 
#include <LCD4884.h>
#include <EEPROM.h>  //includes  EEPROM memory    

// variables for analogstick
int z = 0; 
int az = 0;
int dd = 50;

//menu position
int vertical = 1; //welcome
int alma = 3;  //servo test
char almax[10];
int xray = 1; // combinated
char xrayx[10];


#include <Servo.h>     // Comes with Arduino IDE
Servo myservo;         // create servo object to control a servo  


int anna = 1500;       // servo startvalue
char annax[10];        // lcd value

int sw = 50;           // step value
char swx[10];          // lcd value

int deli = 50;         // servo delay
char delix[10];        // lcd value

int minpulse = 580;
int maxpulse = 2400;

// integration against servojitter
int iv = 0; // integration 1=on / 0=off

//int analogin = 5;        // analog pin connect the potentiometer/varistor
int val;               // variable to read the value from the analog pin 

int pos;

int i = 1;

int time = 25 * 1000;  // reading rate in us = 25ms
unsigned long duration1;
unsigned long duration2;
unsigned long duration3;
unsigned long duration4;
unsigned long duration5;
unsigned long duration6;
unsigned long duration7;
unsigned long duration8;

int xyz;
char xyzx[10];

// receiver PWM incoming
int pwmin1;
int pwmin2;
int pwmin3;
int pwmin4;
int pwmin5;
int pwmin6;
int pwmin7;
int pwmin8;
// receiver PWM incoming prepared for lcd display
char pwm1[10];
char pwm2[10];
char pwm3[10];
char pwm4[10];
char pwm5[10];
char pwm6[10];
char pwm7[10];
char pwm8[10];
char a5[10];

char zz[10];

//RX in  
int pin1 = 10;
int pin2 = 11;
int pin3 = 12;
int pin4 = 13;
int pin5 = A3; // beachte  stecker verdreht  + und - vertauscht am Display Board!!!
int pin6 = A4; // beachte  stecker verdreht  + und - vertauscht am Display Board!!!
int pin7 = A5; // beachte  stecker verdreht  + und - vertauscht am Display Board!!!
int pin8 = A2; // beachte  stecker verdreht  + und - vertauscht am Display Board!!!


// integration against servojitter
float fac = 0.5;
int posa;
char posax[10];
float posx;
float posy;
int   posz;
float posnew;
float posold;
//*************************************************************************************************************
//                END
//*************************************************************************************************************

void setup()  

{//pwm out Pins: 3 5 6 9 10 11    
myservo.attach(9);  // attaches the servo on pin 9 to the servo PWM object 

lcd.LCD_init(); // creates first instance of LCD
lcd.LCD_clear(); // blanks the display 

lcd.LCD_write_string(0,  0, "  PWM Tester  " , MENU_NORMAL);
lcd.LCD_write_string(0,  1, "              " , MENU_NORMAL);
lcd.LCD_write_string(0,  2, "      by      " , MENU_NORMAL);
lcd.LCD_write_string(0,  3, "              " , MENU_NORMAL);
lcd.LCD_write_string(0,  4, "    Airpac    " , MENU_NORMAL);
lcd.LCD_write_string(0,  5, "              " , MENU_NORMAL);
delay(2000);
lcd.LCD_clear(); // blanks the display 

vertical = EEPROM.read(1);
sw = EEPROM.read(2);
deli = EEPROM.read(3);

//EEPROM.write(1, 1 ); //beim ersten Upload activieren damit der EEPROM auf 1 gesetzt wird
//EEPROM.write(2, 50 );
//EEPROM.write(3, 20 );


// aktivieren um servo mit Stellung aus EEPROM anzufahren, zusätzlich in b_servo_test die passende passage aktivieren
// anna = EEPROM.read(4) * 10;   
// posz = map(anna, minpulse, maxpulse, 0, 180);  // mappes varistor value to +- 90° left/right  
// myservo.write(posz);                           // sets the servo position according to the scaled value  


//pwm out Pins: 3 5 6 9 10 11    
myservo.attach(9);  // attaches the servo on pin 9 to the servo PWM object }
}

void loop()    
{
  welcome();
}

/* ( THE END ) */

