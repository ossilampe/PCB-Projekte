// RFID demo sketch by "jurs" for Arduino Forum Deutsch

// start text character
#define STX 2
// end text character
#define ETX 3

// buffer to hold the last code read from Serial
char rfidBufferLastRead[13];

boolean readRFID() 
{
  if (!Serial.available()) return(false); // nothing available to read
  char rfidBuffer[13];
  char c=0;
  int i=0;
  memset(rfidBuffer,0,sizeof(rfidBuffer)); // clear receive buffer
  delay(50); // wait for code to appear in the Serial input buffer
  while (Serial.available()&& c!=STX) // watch out for start of text character
    c=Serial.read();
  while (Serial.available()&& i<12 && c!=ETX) // watch out for end of text character
  {
    c=Serial.read();
    rfidBuffer[i] = c;
    i++;
  }
  if (i!=12) return(false); // less than 12 characters read from Serial
  if (Serial.available()) c=Serial.read();
  if (c!=ETX) return(false);
  strncpy(rfidBufferLastRead,rfidBuffer,sizeof(rfidBuffer)); // copy into global variable rfidBufferLastRead
  return(true); // if we reach this line, we have read 12 digits from Serial
}

 
void setup()
{
  Serial.begin(9600);
  Serial.println("warten auf RFID...");
}

void loop()
{
  if (readRFID())
  {
    if (strcmp(rfidBufferLastRead,"070044C9D359")==0)
      Serial.println("Hallo Mark!");
    else if (strcmp(rfidBufferLastRead,"070043AB21CE")==0)
      Serial.println("Hallo Nicki!");
    else if (strcmp(rfidBufferLastRead,"030023202828")==0)
      Serial.println("Hallo Tom!");
    else 
    {
      Serial.print("Fuck off! ");  
      Serial.println(rfidBufferLastRead);
    }  
  }
}




