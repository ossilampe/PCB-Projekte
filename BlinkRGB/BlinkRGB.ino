/*********************************************
*                                            *
*            http://www.ossilampe.de         *
*    Autor: Thomas Licht                     *
*    Mail:  tom@ossilampe.de                 *
*                                            *
*********************************************/
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledred = 6;
int ledgrn = 5;
int ledblu = 4;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledred, OUTPUT);
  pinMode(ledgrn, OUTPUT);
  pinMode(ledblu, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(ledred, LOW);   
  delay(1000);              
  digitalWrite(ledred, HIGH);    
  delay(1000); 
  digitalWrite(ledgrn, LOW);   
  delay(1000);              
  digitalWrite(ledgrn, HIGH);    
  delay(1000); 
  digitalWrite(ledblu, LOW);   
  delay(1000);              
  digitalWrite(ledblu, HIGH);    
  delay(1000);  
  
}
