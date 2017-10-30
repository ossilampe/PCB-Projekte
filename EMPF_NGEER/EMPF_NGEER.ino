// 433 MHz Empfänger mit der VirtualWire Library V 1.27
//
// Matthias Busse 17.5.2014 Version 1.0

// Verbindungen zum Uno
// GND > D4
// Data > D5
// Input > D6
// VCC > D7

#include <VirtualWire.h>
#define ledPin 3

int i;
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

void setup() {
  Serial.begin(38400);
pinMode(ledPin,OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);   
  pinMode(4, OUTPUT);   // GND 0V
  digitalWrite(4, LOW);
  pinMode(7, OUTPUT);   // VCC 5V
  digitalWrite(7, HIGH);
  vw_setup(5000);       // Bits pro Sekunde
  vw_set_rx_pin(5);     // Datenleitung
  vw_rx_start();        // Empfänger starten
}
 
void loop() {
  if (vw_get_message(buf, &buflen)) { // überprüfen ob eine Nachricht eingegangen ist
    for (i=0;i< buflen;i++) {
       Serial.print((char)buf[i]);    // Nachricht aus buf ausgeben
      digitalWrite(ledPin, HIGH); 
       
    }
    Serial.println("");
    digitalWrite(ledPin, LOW);
  }
}
