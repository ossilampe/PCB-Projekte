#include <Wire.h> 
#include <LiquidCrystal_I2C.h>  
//SDA Analog pin 4
//SCL Analog pin 5

LiquidCrystal_I2C lcd(0x27,20,4); 

int pingPin = 12;
int inPin = 11;

void setup() {
                 lcd.init();                      // initialize the lcd 
                 lcd.backlight();
 
}

void loop(){
  // Variablen für Dauer der ping,
  // Und der Abstand Ergebnis in Zoll und Zentimeter:
  long duration, inches, cm;

  // Der PING wird mit einem High-Impuls von 2 oder mehr Mikrosekunden ausgelöst.
  // Geben Sie eine kurze LOW Impuls vorher um eine saubere HIGH-Impuls zu gewährleisten:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

  // Der gleiche Ping dient dazu, das Signal von der PING)) zu lesen
  // dessen Dauer ist die Zeit (in Mikrosekunden) vom Senden
  // Die Verbindungsgeschwindigkeit mit dem Empfang sein echo off von dem Objekts.
  pinMode(inPin, INPUT);
  duration = pulseIn(inPin, HIGH);

  // Hier wird die Zeit in eine entfernung umgewandelt
  cm = microsecondsToCentimeters(duration);

  // wenn der abstand zu Gross ist wird im display angezeigt "zu weit entfernt"
  // resultat wird gelöscht.
  if (cm > 400){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("zu weit entfernt");
  }

  else {

  // clear lcd 
  lcd.clear();
  // set the cursor linie 0 platz 0
  lcd.setCursor(0, 0);
  lcd.print("Object erkannt ");
  lcd.setCursor(5, 2);
  lcd.print(cm);
  lcd.print("cm");
  }

  delay(500);

}

long microsecondsToInches(long microseconds){
  // Nach Parallax das Datenblatt für den PING))), gibt es
  // 73,746 Mikrosekunden pro Zoll (dh Schall bei 1130 Fuß pro
  // Sekunde). Dies gibt die Wegstrecke vom Ping,
  // Und zurück, so dass wir durch 2 teilen, müssen um den Abstand zum Hindernisses zu bekommen.
  return microseconds / 74 / 2;}

long microsecondsToCentimeters(long microseconds){
  // Die Schallgeschwindigkeit beträgt 340 m / s oder 29 Mikrosekunden pro Zentimeter.
  return microseconds / 29 / 2;}


