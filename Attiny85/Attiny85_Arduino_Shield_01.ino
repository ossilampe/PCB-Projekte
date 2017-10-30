/*
Blink for Attiny-85

Led0, Led1, Led2 are blinking.

Pin Attiny85      
  1 Reset
  2 Analog Input3 (PIN3)
  3 Analog Input2 (PIN4)
  4 GND
  
  5 Pin 0 PWM, MOSI AREF
  6 Pin 1 PWM, MISO
  7 Pin 2 Analog Input 1, SCK
  8 VCC +5 Volt
  
 */

int led0 = 0;
int led1 = 1;
int led2 = 2;

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

