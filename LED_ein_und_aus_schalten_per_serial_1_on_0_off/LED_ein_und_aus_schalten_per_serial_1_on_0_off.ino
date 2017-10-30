/*
 * serial_control.pde
 * -----------------
 * Turns the LED 13 ON and OFF depending on what is received
 * through the serial port.
 *
 * http://spacetinkerer.blogspot.com
 */

#define LED 13

int input = 0;       // variable to keep the data from the serial port

void setup() {
  pinMode(LED,OUTPUT);    // declare the LED's pin as output
  Serial.begin(9600);        // connect to the serial port
}

void loop () {
  input = Serial.read();      // read the serial port

  // if the input is '1' turn the LED ON, if '0' turn it OFF
  if (input == '1' ) {
    digitalWrite(LED,HIGH);
    Serial.println("LED13 is ON");
  }
  if (input == '0'){
      digitalWrite(LED, LOW);
      Serial.println("LED13 is OFF");
  }
}
