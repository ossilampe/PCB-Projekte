#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 

const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int ledPin1 =  13;      //kontroll Leds 
const int ledPin2 =  12;
int buttonState1 = 0;
int buttonState2 = 0;


// start text character
#define STX 2
// end text character
#define ETX 3

// buffer to hold the last code read from Serial
char rfidBufferLastRead[13];
char rfidBufferStored[13];

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
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  digitalWrite(lockPIN, HIGH);
  pinMode(lockPIN,OUTPUT);
  Serial.begin(9600);
  //digitalWrite(lockPIN = OFF);
  Serial.println("warten auf RFID...");
}

void loop()
{
  lcd.setCursor(0,0);                //cursor start position
     lcd.print("Tel. 06646252113");     //ausgabe Text   
     lcd.setCursor(0,1);                //cursor start position zweite Zeile
     lcd.print("warten auf RFID...");
     
     
     
  if (readRFID())
  {
   if (memcmp(rfidBufferStored, rfidBufferLastRead, 13) != 0 {
    if else (strcmp(rfidBufferLastRead,"05008C36E758")==0){
      lcd.setCursor(0,1);                
      lcd.print("warten auf RFID...");
      lcd.setCursor(0,1);
      lcd.print("Hallo Heli!        ");
      lcd.setCursor(0,3);
      lcd.print("Opening the door...!");
      digitalWrite(lockPIN,LOW);
      delay(2000);
      digitalWrite(lockPIN,HIGH);
      Serial.print("Close the door...!");
      lcd.setCursor(0,2);
      lcd.print("             ");
      lcd.setCursor(0,3);
      lcd.print("Close the door...!  ");
      delay(2000);
      lcd.setCursor(0,3);
      lcd.print("                   ");
      
    
    }
    else 
    {
      Serial.print("Fuck off! "); 
      lcd.setCursor(0,2);
      lcd.print("     Fuck off !!!   ");
      lcd.setCursor(0,3);
      lcd.print("                   "); 
      delay(2000);
      lcd.setCursor(0,2);
      lcd.print("                   ");
      Serial.println(rfidBufferLastRead);
    }  
  }

}
}


