/*
 JY-MCU    Arduino Mega
            TXD <----> RX1 
            RXD <----> TX1
            
*/



void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // read from port 1, send to port 0:
  if (Serial1.available()) {
    int inByte = Serial1.read();
    if( inByte ){
      Serial1.write("*");
    }     
    Serial.write(inByte);
  }
 
  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }
}
