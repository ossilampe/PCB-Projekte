
// Rotary encoder example.
// Author: Nick Gammon
// Date:   24th May 2011

// Wiring: Connect common pin of encoder to ground.
// Connect pins A and B (the outer ones) to pins 2 and 3 (which can generate interrupts)

volatile boolean fired = false;
volatile long rotaryCount = 0;

// Interrupt Service Routine
void isr ()
{
 
static boolean ready;
static unsigned long lastFiredTime;
static byte pinA, pinB;  

// wait for main program to process it
 if (fired)
   return;
   
 byte newPinA = digitalRead (10);
 byte newPinB = digitalRead (11);
 
 // Forward is: LH/HH or HL/LL
 // Reverse is: HL/HH or LH/LL
 
 // so we only record a turn on both the same (HH or LL)
 
 if (newPinA == newPinB)
   {
   if (ready)
     {
     long increment = 1;
       
     // if they turn the encoder faster, make the count go up more
     // (use for humans, not for measuring ticks on a machine)
     unsigned long now = millis ();
     unsigned long interval = now - lastFiredTime;
     lastFiredTime = now;
     
     if (interval < 10)
       increment = 5;
     else if (interval < 20)
       increment = 3;
     else if (interval < 50)
       increment = 2;
        
     if (newPinA == HIGH)  // must be HH now
       {
       if (pinA == LOW)
         rotaryCount += increment;
       else
         rotaryCount -= increment;
       }
     else
       {                  // must be LL now
       if (pinA == LOW)  
         rotaryCount -= increment;
       else
         rotaryCount += increment;        
       }
     fired = true;
     ready = false;
     }  // end of being ready
   }  // end of completed click
 else
   ready = true;
   
 pinA = newPinA;
 pinB = newPinB;
}  // end of isr

#include <AH_Pololu.h>

//AH_Pololu(int RES, int DIR, int STEP, int MS1, int MS2, int MS3, int SLEEP);
AH_Pololu stepper(200,2,3,4,5,6,7);    // init w/o "enable" and "reset" functions

int time1;
int time2;
int anzahl;
void setup ()
{
 digitalWrite (10, HIGH);   // activate pull-up resistors
 digitalWrite (11, HIGH); 
 
 attachInterrupt (0, isr, CHANGE);   // pin 2
 attachInterrupt (1, isr, CHANGE);   // pin 3

 Serial.begin (115200);
  Serial.println(stepper.getVersion());
  stepper.setMicrostepping(1);   
}  // end of setup

void loop ()
{

 if (fired)
   {
   Serial.print ("Count = ");  
   Serial.println (rotaryCount);
   anzahl = rotaryCount*100;
   fired = false;
 }  // end if fired
 {
  
  for (int i=1000;i<3000;i=i+anzahl){
    stepper.setSpeedHz(i);  
    Serial.print("Freq.: ");
    Serial.println(i);
      Serial.print("Anzahl.: ");
    Serial.println(anzahl);
         Serial.print("Poti.: ");
    Serial.println(rotaryCount);
    stepper.sleepOFF();
      stepper.revolve(1);
    stepper.sleepON();  
    delay(1000);
  }

} 
}// end of loop
