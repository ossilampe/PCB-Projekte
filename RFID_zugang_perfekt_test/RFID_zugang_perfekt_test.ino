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
int lockPIN=7;
 
void setup()
{
  pinMode(lockPIN,OUTPUT);
  Serial.begin(9600);
  Serial.println("waiting for RFID...");
  
}

void loop()
{
  if (readRFID())
  {
    {
      if (strcmp(rfidBufferLastRead,"08000B203112")==0)
      digitalWrite(lockPIN,HIGH);
    else if (strcmp(rfidBufferLastRead,"02006199B349")==0)
     digitalWrite(lockPIN,HIGH);
    else if (strcmp(rfidBufferLastRead,"800C4C028042")==0)
      digitalWrite(lockPIN,HIGH);
    else 
    {
      digitalWrite(lockPIN,LOW);  
      Serial.println(rfidBufferLastRead);
    }  
  }
}
}



