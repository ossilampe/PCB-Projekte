/*
Übung 07
Mit einem Fotowiderstand wird eine LED Ein/Aus geschaltet.
Wird ein bestimmter Helligkeitswert unterschritten, so wird die LED eingeschaltet.
(Dämmerungsschalter)
by Thomas Ecker,
www.physicalcomputing.at
Juni 2010

*/

int Poti = 1; // Fotowiderstand am Analog 0
 // LED am Digital 3
int ValuePot = 0; // Variable für Spannung am Analog In
int Empfindlichkeit = 800;
const int ledPin = 9;
// über diesen Wert kann die Empfindlichkeit eingestellt werden
// wird der Wert erhöht, so schaltet die LED erst ein, wenn es dunkler wird
// und umgekehrt

void setup() {
pinMode(ledPin, OUTPUT);
}

void loop() {
byte brightness;

ValuePot = analogRead(Poti); // Abfrage am Analog Eingang
// ValuePot kann einen Wert von 0 - 1023 annehmen.

if (ValuePot >= Empfindlichkeit){

analogWrite(ledPin, 180);
}
else {
analogWrite(ledPin, 50);
}

}
