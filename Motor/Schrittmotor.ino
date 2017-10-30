/*

befehl step(SCHRITTE,RICHTUNG,TYP);

SCHRITTE>>> SINGLE = EINE SPULE WENIGER STROM
            DOUBLE = BEIDE SPULEN MEHR STRIOM MEHR KRAFT
            INTERLEAVE = WECHSELT ZWISCHEN DOUBLE UND SINGLE
            MICROSTEP = NUTZT PWM um die auflösung zwischen den schritten zu glätten
*/            

#include <AFMotor.h>



AF_Stepper motor(200,1);


void setup() 
  {
  motor.setSpeed(100);
 
  
  Serial.begin(9600);
  }
 
 
  


void loop()

{
//Serial.printnl("singel");

motor.step(100,FORWARD,DOUBLE);
delay(2000);
motor.step(100,BACKWARD,DOUBLE);
delay(2000);

}
