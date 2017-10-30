/* TimeRTC Sketch: Ausgabe auf serieller Konsole & LC-Display 
 *
 * SCL pin A5 arduino
 * SDA pin A4 arduino
*/







// Bibliothen fuer Echtzeituhr:
#include <LiquidCrystal.h>  // binde LCd-Bibliothek ein
#include <Time.h> // binde Bibliothek Time ein
#include <Wire.h> // binde Wire-Bibliothek ein
#include <DS1307RTC.h>  // binde Bibliothek fuer DS1307-RTC(Uhr) ein

// abhaengig von Beschaltung des LC-Displays, siehe http://macherzin.net/article38-Arduino-Ausgabe-LC-Display(externer Link)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // initialisieren Bibliothek und Interface-Pins

void setup()
{
  Serial.begin(9600); // initialisieren serielle Kommunikation
  setSyncProvider(RTC.get); // holen Zeit von RTC(Uhr)
  
  // Nur zur Kontrolle:
  if(timeStatus()!= timeSet) // wenn Status geaendert
  {
     Serial.println("Synchronisation fehlgeschlagen"); // bei Fehler
  }
  else // sonst ...
  {
     Serial.println("Synchronisation erfolgreich"); // alles ok
  }
  lcd.begin(16, 2); // Display hat 16 Zeichen x 2 Zeilen,
  // Kontrolle Ende
  
  Serial.println("Uhrzeit   Datum: "); // nur so
  lcd.print("Uhrzeit   Datum: "); // nur so
}

void loop()
{
   digitalUhrAnzeige(); // rufen Subroutine auf
   delay(1000); // warten, weil unser Auge nicht so schnell ...
}

void digitalUhrAnzeige() // definieren Subroutine
{
   // digitale Anzeige der Zeit
   lcd.setCursor(0, 1); // positionieren LCD-Cursor, 1. Zeile, 1. Spalte
   printZiffernGenulltOhnePunkt(hour()); // rufen Subroutine auf
   printZiffernGenulltmitPunkt(minute()); // rufen Subroutine auf
   printZiffernGenulltmitPunkt(second()); // rufen Subroutine auf
   Serial.print(" "); // fuegen Freizeichen ein
   lcd.print(" "); // fuegen Freizeichen ein
   printZiffernGenulltOhnePunkt(day()); // rufen Subroutine auf
   Serial.print(" "); // fuegen Freizeichen ein
   lcd.print(" "); // fuegen Freizeichen ein
   printZiffernGenulltOhnePunkt(month()); // rufen Subroutine auf
   Serial.print(" "); // fuegen Freizeichen ein
   Serial.println(year());; // Zeilenvorschub
   // deaktiviert, kein Platz mehr auf 16er-Display:
   // lcd.print(" ");  
   // printZiffernGenulltOhneSemikolon(year());
}

void printZiffernGenulltOhnePunkt(int zahl) // definieren Subroutine
{
  // verschoenern Anzeige, indem wir ...
  if(zahl < 10) // wenn kleiner als 10 ...
   {
     Serial.print(""); // fuehrende 0 einfuegen
     lcd.print("");  // fuehrende 0 einfuegen
   }
   Serial.print(zahl); // Ausgabe auf serieller Konsole
   lcd.print(zahl); // Ausgabe auf LCD     
}

void printZiffernGenulltmitPunkt(int zahl) // definieren Subroutine
{
  // verschoenern Anzeige, indem wir ...
  Serial.print(":"); // trennende ":" einfuegen
  lcd.print(":"); // trennende ":" einfuegen
  if(zahl < 10) // wenn kleiner als 10 ...
  {
     Serial.print('0'); // fuehrende 0 einfuegen
     lcd.print('0');
  }
  Serial.print(zahl); // Ausgabe auf serieller Konsole
  lcd.print(zahl);
}

// haben fertig: Have A Lot Of Fun ...
