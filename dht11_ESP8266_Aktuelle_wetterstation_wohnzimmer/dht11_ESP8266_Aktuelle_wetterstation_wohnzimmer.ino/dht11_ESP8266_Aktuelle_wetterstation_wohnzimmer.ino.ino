#include <ESP8266WiFi.h>
#include "DHT.h"
 

#define DHTPIN 4             

#define DHTTYPE DHT22    
#define Sleeptime 1200000  
 
#define UPDATEINTERVAL 15 //Wir aktualisieren den Thingspeak Channel alle 15 Minuten (Mindestabstand=15 Minuten)
#define CONNECTIONTIMEOUT 60 //Verbindungstimeout für die Verbindung mit unserem WLAN (Sekunden)


 
const char* THINGSPEAKAPIKEY = "FT6V86Q2GBDDAH2J"; //Der Write Key des Thingspeak Channels kommt hier rein
const char* THINGSPEAKHOST = "api.thingspeak.com";
 
const char* WLANSSID = "tom_home_werkstatt"; //Die SSID eures WLAN kommt hier rein
const char* WLANPWD = "heimnetz";  //Das WLAN Passwort eures WLAN kommt hier rein, bei einem offenen WLAN einfach leer lassen
 
DHT dht(DHTPIN, DHTTYPE);
ADC_MODE(ADC_VCC);
void setup() {


  Serial.begin(115200);
  
}
 
void loop() {

 delay(3000);


  Serial.println(analogRead(A0)); 
  Serial.println(F(""));  
  Serial.println(F(""));  
  Serial.println(F("ESP8266-DHT22-AKKU-SENSOR Thingspeak Test mit Deep-Sleep..."));
  Serial.println(F(""));
  Serial.print(F("SDK-Version: "));
  Serial.println(ESP.getSdkVersion());
  Serial.print(F("ESP8266 Chip-ID: "));
  Serial.println(ESP.getChipId());
  Serial.print(F("ESP8266 Speed in MHz: "));  
  Serial.println(ESP.getCpuFreqMHz());
  Serial.print(F("Free Heap Size in Bytes: "));
  Serial.println(ESP.getFreeHeap());
  Serial.println(F(""));

  
  delay(1000);
   
  dht.begin();
 
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  
 
 
 
  if (isnan(hum) || isnan(temp)) {
    Serial.println(F("Sensorfehler!"));
    
    delay(100);
  } else {
    Serial.print(F("Luftfeuchte: "));
    Serial.print(hum);
    Serial.println(F(" %"));
    Serial.print(F("Temperatur: "));
    Serial.print(temp);
    Serial.println(F(" *C"));
    Serial.println(F(""));
    Serial.print(F("ESP-Spannung: "));
    Serial.println(ESP.getVcc());
    Serial.print(F(" mV"));
    Serial.println(F(""));

     
    Serial.print(F("Verbinde mit "));
    Serial.println(WLANSSID);
   
    WiFi.begin(WLANSSID, WLANPWD);
 
    int timeout=0;
     
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.print(F("."));
      timeout+=1;
 
      if (timeout>=CONNECTIONTIMEOUT) {
        Serial.println(F(""));
         Serial.println(F("Timeout!"));  
        delay(100);
      }
    }
 
    Serial.println(F(""));
    Serial.println(F("Verbindung hergestellt"));  
    Serial.print(F("IP Addresse: "));
    Serial.println(WiFi.localIP());
   
    Serial.print(F("Verbinde mit "));
    Serial.println(THINGSPEAKHOST);
   
    WiFiClient client;
 
    if (!client.connect(THINGSPEAKHOST, 80)) {
      Serial.println(F(""));
      Serial.println(F("Verbindung fehlgeschlagen!"));
 
      delay(100);
    } else {
      Serial.println(F("Verbindung erfolgreich hergestellt"));
      Serial.println(F("Sende Daten an Thingspeak Channel..."));
   
      String POSTString ="api_key=";
      POSTString += THINGSPEAKAPIKEY;
      POSTString += "&field1=";
      POSTString += temp;
      POSTString += "&field2=";
      POSTString += hum;
      POSTString += "&field8=";
      POSTString += ESP.getVcc();
   
      client.print(F("POST /update HTTP/1.1\n")); 
      client.print(F("HOST: "));
      client.print(THINGSPEAKHOST);
      client.print(F("\n"));
      client.print(F("X-THINGSPEAKAPIKEY:"));
      client.print(THINGSPEAKAPIKEY);
      client.print(F("\n"));
      client.print(F("Connection: close\n")); 
      client.print(F("Content-Type: application/x-www-form-urlencoded\n")); 
      client.print(F("Content-Length: "));
      client.print(POSTString.length()); 
      client.print(F("\n\n"));
      client.print(POSTString);
      client.stop();
       
      Serial.println(F("Verbindung zum Server beendet"));
      Serial.println(F("Daten an Thingspeak Channel gesendet"));
    
      WiFi.disconnect();
     
      Serial.println(F("Verbindung mit WLAN beendet"));
      Serial.println(F("Ich lege mich schlafen..."));
 
  

     delay(Sleeptime);
  
    }  
  }
}
