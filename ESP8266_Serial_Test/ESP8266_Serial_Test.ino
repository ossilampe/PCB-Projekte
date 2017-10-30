#include <SoftwareSerial.h>
 
SoftwareSerial wifi(10,11); 
                           
void setup(){
  Serial.begin(115200);
  Serial.println("Wifi Startet");
  wifi.begin(115200); 
}
 
void loop() {
if(Serial.available() > 0){
  byte b = Serial.read();
  wifi.write(b);
}

if(wifi.available() > 0){
  byte b = wifi.read();
  Serial.write(b);
}
}
