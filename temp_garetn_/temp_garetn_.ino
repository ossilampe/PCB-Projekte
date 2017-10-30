#include <ESP8266WiFi.h>
#include "DHT.h"
 
#define LEDPIN 5             
#define DHTPIN 4             
#define DHTPOWERPIN 14
#define DHTTYPE DHT22        
 
#define UPDATEINTERVAL 15 //Wir aktualisieren den Thingspeak Channel alle 15 Minuten (Mindestabstand=15 Minuten)
#define CONNECTIONTIMEOUT 60 //Verbindungstimeout für die Verbindung mit unserem WLAN (Sekunden)
 
const char* THINGSPEAKAPIKEY = "YM1VOB60D5274RLU"; //Der Write Key des Thingspeak Channels kommt hier rein
const char* THINGSPEAKHOST = "api.thingspeak.com";
 
const char* WLANSSID = "tom_home!"; //Die SSID eures WLAN kommt hier rein
const char* WLANPWD = "heimnetz"; //Das WLAN Passwort eures WLAN kommt hier rein
 
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(DHTPOWERPIN, OUTPUT);
 
  digitalWrite(DHTPOWERPIN, 1);
  digitalWrite(LEDPIN, 1);
 
  Serial.begin(115200);
 
  Serial.println(F(""));  
  Serial.println(F(""));  
  Serial.println(F("ESP8266-DHT22-AKKU-SENSOR Thingspeak Test mit Deep-Sleep und Anzeige vorhandener WLANs..."));
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
  Serial.println(F("WiFi-Netzwerk-Scan gestartet..."));
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
 
  int n = WiFi.scanNetworks();
     
  Serial.println(F("WiFi-Netzwerk-Scan abgeschlossen..."));
  Serial.println(F(""));
 
  if (n == 0) {
    Serial.println(F("Kein WiFi-Netzwerk gefunden!"));
  } else {
    Serial.print(n);
 
    if(n<=1) {
     Serial.println(F(" WiFi-Netzwerk gefunden"));
    } else {
      Serial.println(F(" WiFi-Netzwerke gefunden"));
    }
   
    Serial.println(F(""));
 
    for (int i = 0; i < n; ++i) { 
      Serial.print(i + 1);
      Serial.print(F(": "));
      Serial.print(WiFi.SSID(i));
      Serial.print(F(" ("));
      Serial.print(WiFi.RSSI(i));
      Serial.print(F(")"));
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
    }
  }
 
  Serial.println(F("")); 
 
  delay(1000);
   
  dht.begin();
 
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
 
  digitalWrite(DHTPOWERPIN, 0);
 
  if (isnan(hum) || isnan(temp)) {
    Serial.println(F("Sensorfehler!"));
    ESP.deepSleep(1000000,WAKE_RF_DEFAULT);
    delay(100);
  } else {
    Serial.print(F("Luftfeuchte: "));
    Serial.print(hum);
    Serial.println(F(" %"));
    Serial.print(F("Temperatur: "));
    Serial.print(temp);
    Serial.println(F(" *C"));
    Serial.println(F(""));
     
    Serial.print(F("Verbinde mit WLAN "));
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
         
        ESP.deepSleep(1000000,WAKE_RF_DEFAULT);
        delay(100);
      }
    }
 
    Serial.println(F(""));
    Serial.println(F("Verbindung mit WLAN hergestellt"));  
    Serial.print(F("Zugewiesene IP Addresse: "));
    Serial.println(WiFi.localIP());
   
    Serial.print(F("Verbinde mit "));
    Serial.println(THINGSPEAKHOST);
   
    WiFiClient client;
 
    if (!client.connect(THINGSPEAKHOST, 80)) {
      Serial.println(F(""));
      Serial.println(F("Verbindung mit Thingspeak-Server fehlgeschlagen!"));
 
      ESP.deepSleep(1000000,WAKE_RF_DEFAULT);
      delay(100);
    } else {
      Serial.println(F("Verbindung mit Thingspeak-Server erfolgreich hergestellt"));
      Serial.println(F("Sende Daten an Thingspeak Channel..."));
   
      String POSTString ="api_key=";
      POSTString += THINGSPEAKAPIKEY;
      POSTString += "&field1=";
      POSTString += temp;
      POSTString += "&field2=";
      POSTString += hum;
   
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
 
      ESP.deepSleep(60000000*UPDATEINTERVAL,WAKE_RF_DEFAULT);
      delay(100);
    }  
  }
}
 
void loop() {
}
