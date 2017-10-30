

/************************( Importieren der genutzten Bibliotheken )************************/
#include <Wire.h>                   // Wird für die Sensoren mit I2C Bus benötigt
#include <BH1750.h>                 // Helligkeit Sensor
#include <BMP280.h>                 // Luftdruck und Temperatur Sensor
#include <SI7021.h>                 // Luftfeuchtigkeit und Temperatur Sensor
#include <RunningMedian.h>          // Sehr gute Library für Mittelwertbildung von Messdaten
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>            // Wifi Funktionen um sich mit dem Wlan zu verbinden

#include <OneWire.h>                // Wird für die Kommunikation mit dem Temperatursensor-
#include <DallasTemperature.h>      // DS18B20 genutzt.

BMP280 bmp;

/********************( Definieren der Globale Variablen und Konstanten)********************/
float SI7021T;                           // Variable zum Speichern der Temperatur
float SI7021H;                           // Variable zum Speichern der Luftfeuchtigkeit
double BMP280P;                          // Variable zum Speichern des Luftdrucks
double BMP280T;                          // Variable zum Speichern des Temperatur
float BMP280P2;                          // Hilfsvariable für Umwandlung in float
float BMP280T2;                          // Hilfsvariable für Umwandlung in float
int BH1750Lux;                           // Variable zum Speichern der Helligkeit in Lux
float DS18B20T;                          // Variable zum Speichern der Temperatur

char resultBMP280;                       // Variable für Fehlerauswertung und Messzeit

#define ONE_WIRE_BUS 2                   // Anschluss Pin von DS18B20 hier GPIO02
#define TEMPERATURE_PRECISION 12         // Höchste Auflösung 12 Bit Messzeit ca 750ms
#define LEDPIN 5                         
#define SENSORPOWERPIN 14

unsigned long ThingspeakLastLogTime = 0;      // Hilfs Variable letzte Log Zeit
unsigned long SensorenLetzteAktualisierung;   // Hilfsvariable für Zeitmessung

int status = WL_IDLE_STATUS;                  // status Wifi

/**********************************(Thingspeak Eistellungen)*******************************/
unsigned long myChannelNumber = 127787;          // Deine ThingSpeak Kanal Nummer
const char * myWriteAPIKey = "YM1VOB60D5274RLU"; // Dein ThingSpeak API Key

/************************************(Wifi Einstellungen)**********************************/
char ssid[] = "tom_home!";               // Deine Wlan SSID (Name)
char pass[] = "heimnetz";   // Dein Wlan Passwort

/************************( Definieren von Zeitabhänigen Variablen )************************/
float SensorenSampelTime = 4000;               // Zeit in ms für Aktualisierung der Sensoren-
// und Mittelwertbildung


// Zeit in ms für Aktualisierung zum schicken der Messdaten an Thingspeak in ms. Kleiner als
// 15000ms (15s) geht mit dem kostenlosen Account nicht.
// Empfehlung von mir 60000ms oder 300000ms!
int ThingspeakSampelTime = 15000;

/***********************( Definieren der Objekte und initialisieren )***********************/

BH1750 lightMeter(0x23);                           // BH1750 initialisieren



RunningMedian MedianBMP280T2 = RunningMedian(2);  // Mittelung aktivieren über 10 Messwerte
RunningMedian MedianBMP280P2 = RunningMedian(2);  // Mittelung aktivieren über 10 Messwerte
RunningMedian MedianBH1750Lux = RunningMedian(2); // Mittelung aktivieren über 10 Messwerte


WiFiClient  client;                                // Wifi

/*****************************************( Setup )****************************************/
void setup() {
  
  pinMode(LEDPIN, OUTPUT);
  pinMode(SENSORPOWERPIN, OUTPUT);

  digitalWrite(SENSORPOWERPIN, 1);
  digitalWrite(LEDPIN, 1);

  delay(2000);
 
  Serial.begin(9600);
  Serial.println("\nSensor Test");



  Wire.begin(D2, D1);         // Festlegen der I2C Pins und initialisieren (4,5 oder D2,D1)
  WiFi.begin(ssid, pass);     // Wlan Aktivieren und mit definiertem Netzwerk verbinden
  ThingSpeak.begin(client);   // ThingSpeak Client starten
  lightMeter.begin(BH1750_CONTINUOUS_HIGH_RES_MODE); // BH1750 Lichtsensor starten
  bmp.begin();                                       // BMP280 Luftdruck Sensor starten
  bmp.setOversampling(4);                     // Sensor auf die Höchste Auflösung einstellen

 // BMP280 Messung Starten
    resultBMP280 = bmp.startMeasurment();

    if (resultBMP280 != 0) {
      delay(resultBMP280);
    delay(1000);
      bmp.getTemperatureAndPressure(BMP280T, BMP280P); // Messwerte abholen und Speichern

      // Messwerte in Float umwandeln und Mittelwert neu in Variable Speichern
      MedianBMP280T2.add(BMP280T * 1.0);  // Messwerte in Float umwandeln
      MedianBMP280P2.add(BMP280P * 1.0);  // Messwerte in Float umwandeln
      BMP280T2 = MedianBMP280T2.getAverage();
      BMP280P2 = MedianBMP280P2.getAverage();


// BH1750 Lux auslesen und Mittelwert in Variable Speichern
    MedianBH1750Lux.add(lightMeter.readLightLevel());
    BH1750Lux = MedianBH1750Lux.getAverage();


    


      Serial.print("BH1750   ");
      Serial.print(BH1750Lux);
      Serial.println("  Lux");
 

   
    delay(1000);
      Serial.print("BMP280   ");
      Serial.print(BMP280T2);
      Serial.println("  C");
      Serial.print("BMP280   ");
      Serial.print(BMP280P2);
      Serial.println("  mBar");
      delay(1000);
    }
   

    ThingSpeak.setField(1, BMP280T2);
    ThingSpeak.setField(2, BMP280P2);
    ThingSpeak.setField(3, BH1750Lux);


    // Alle Messdaten zusammen an Thingspeak schicken
    ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

     digitalWrite(SENSORPOWERPIN, 0);
     digitalWrite(LEDPIN, 0);


      //ESP.deepSleep(60000000*UPDATEINTERVAL,WAKE_RF_DEFAULT);
      //delay(100);
 }


void loop() {
}
                     


