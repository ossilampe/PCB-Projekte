// 433 MHz Sender mit der VirtualWire Library  V 1.27
//
// Matthias Busse 17.5.2014 Version 1.0

// Verbindungen zum Uno
// GND > D5
// VCC > D6
// Daten > D7
 
#include <VirtualWire.h>
#define ledPin 3

char *msg = "Hallo Welt";// Nachricht
 
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);   // GND 0V
  digitalWrite(5, LOW);
  pinMode(6, OUTPUT);   // VCC 5V
  digitalWrite(6, HIGH);
  vw_setup(5000);       // Bits pro Sekunde
  vw_set_tx_pin(7);     // Datenleitung
}
 
void loop(){
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx(); // warten bis alles übertragen ist
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
