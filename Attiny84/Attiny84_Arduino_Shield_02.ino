/*
Blink for Attiny-84

Pin Attiny84
  1 VCC
  2 D0
  3 D1
  4 Reset
  5 D2
  6 D3  (A7)
  7 D4  (A6) MOSI
  
  8 D5  (A5) MISO
  9 D6  (A4) SCK
 10 D7  (A3)
 11 D8  (A2)
 12 D9  (A1)
 13 D10 (A0) AREPF
 14 GND

  
 */

int led0 = 10;
int led1 = 9;
int led2 = 8;

int delay_time = 250;

// the setup routine runs once when you press reset:
void setup() 
{     
  // initialize the digital pin as an output.
  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  
 
}

// the loop routine runs over and over again forever:
void loop() 
{
  digitalWrite(led0,HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delay_time);               // wait for a time

  digitalWrite(led1,HIGH);
  delay(delay_time);
  
  digitalWrite(led2,HIGH);
  delay(delay_time);  
  
  
  digitalWrite(led0,LOW);    // turn the LED off by making the voltage LOW
  delay(delay_time);               // wait for a time
 
  digitalWrite(led1,LOW);
  delay(delay_time);

  digitalWrite(led2,LOW);
  delay(delay_time);

}

