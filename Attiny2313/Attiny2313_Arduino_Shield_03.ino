/*
Blink for Attiny-2313

Led0, Led1, Led2 are blinking.

Pin Attiny2313
  1 Reset
  2 PD0 RXD
  3 PD1 TXD
  4 PA1 XTAL2
  5 PA0 XTAL1
  6 PD2 CKOUT
  7 PD3 INT1
  8 PD4 TO
  9 PD5 T1
 10 GND
 
 11 PD6 ICP
 12 PB0 PCINT0
 13 PB1 PCINT1
 14 PB2 PCINT2
 15 PB3 PCINT3
 16 PB4 PCINT4
 17 PB5 MOSI
 18 PB6 MISO
 19 PB7 PCINT7
 20 VCC
  
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

