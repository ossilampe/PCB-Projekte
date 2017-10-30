#include <math.h>
 
float temperatur =0; //Variable zum Zwischenspeichern der Temperatur
 
void setup()
{
Serial.begin(9600);
 
}
 
void loop()
{
temperatur = temp(analogRead(0));
Serial.println(temperatur);


}
 
float temp(int rawadc)
// Hilfsfunktion zur Umrechnung auf Grad Celsius
{
int r1 = 4700; // Wert des Festen Wiederstandes des sabbungsteiler
int r2 = 4700; // Wiederstand des Thermristors bei 25grad
int b = 3950;  // Fixwert aus Datenblatt
float r_akt; // Aktueller Wiederstand
float temp; //Temporäre Variable
float ergebnis; //
float tn = 25; //Basistemperatur in Grad Celsius
// Wiederstand Therm ausrechnen
//Widerstand auf Temperatur umrechnen
tn = tn+273.15; // Basitemperatur auf Kelvin umrechnen
r_akt = ((4.64/(4.64/1023*rawadc))*r1)-r2; //Aktuellen Widerstand ermitteln
temp = b*tn/(b+log10((r_akt/r2))*tn);
temp = temp - 273.15; //Ergebnis in Grad Celsius umwandeln
ergebnis =temp;
return ergebnis;
}
