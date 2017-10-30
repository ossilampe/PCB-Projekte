#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <functional>
#include "switch.h"
#include "UpnpBroadcastResponder.h"
#include "CallbackFunction.h"
 
// prototypes
boolean connectWifi();
 
//on/off callbacks 
void lichtan();
void lichtaus();
;
 
// Change this before you flash
const char* ssid = "tom_home!";
const char* password = "heimnetz";
 
boolean wifiConnected = false;

UpnpBroadcastResponder upnpBroadcastResponder;
 
Switch *lightOne = NULL;

 
// Set Relay Pins
int relayOne = 4;

 
void setup()
{
  Serial.begin(115200);
   digitalWrite(relayOne, HIGH);
  // Initialise wifi connection
  wifiConnected = connectWifi();
  
  if(wifiConnected){
    upnpBroadcastResponder.beginUdpMulticast();
    
    // Define your switches here. Max 14
    // Format: Alexa invocation name, local port no, on callback, off callback
    lightOne = new Switch("Licht", 80, lichtan, lichtaus);
    
 
    Serial.println("Adding switches upnp broadcast responder");
    upnpBroadcastResponder.addDevice(*lightOne);
    
 
    //Set relay pins to outputs
       pinMode(4,OUTPUT); 

       
  }
}
 
void loop()
{
   if(wifiConnected){
      upnpBroadcastResponder.serverLoop();
      
      lightOne->serverLoop();
   
   }
}
 
void lichtan() {
    Serial.print("Switch 1 turn on ...");
    digitalWrite(relayOne, LOW);   // sets relayOne on
}
 
void lichtaus() {
    Serial.print("Switch 1 turn off ...");
    digitalWrite(relayOne, HIGH);   // sets relayOne off
}
 


 
// connect to wifi – returns true if successful or false if not
boolean connectWifi(){
  boolean state = true;
  int i = 0;
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");
 
  // Wait for connection
  Serial.print("Connecting ...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 10){
      state = false;
      break;
    }
    i++;
  }
  
  if (state){
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("");
    Serial.println("Connection failed.");
  }
  
  return state;
}
