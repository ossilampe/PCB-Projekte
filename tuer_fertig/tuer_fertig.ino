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
    if (strcmp(rfidBufferLastRead,"070044C9D359")==0){
      Serial.println("Hallo Mark!");
      Serial.print("Opening the door...!");
      lcd.setCursor(0,1);                
      lcd.print("warten auf RFID...");
      delay(100);
      lcd.setCursor(0,1);               
      lcd.print("     Danke          ");
      delay(1500);
      lcd.setCursor(0,2);
      lcd.print("Hallo Mark!   ");
      lcd.setCursor(0,3);
      lcd.print("Opening the door...!");
      digitalWrite(lockPIN,HIGH);
      delay(2000);
      digitalWrite(lockPIN,LOW);
      Serial.print("Close the door...!");
      lcd.setCursor(0,2);
      lcd.print("             ");
      lcd.setCursor(0,3);
      lcd.print("Close the door...!  ");
      delay(2000);
      lcd.setCursor(0,3);
      lcd.print("                   ");
      delay(2000);
      
    }
    else if (strcmp(rfidBufferLastRead,"070043AB21CE")==0){
      Serial.println("Hallo Nicki!");
     Serial.print("Opening the door...!");
      lcd.setCursor(0,1);                
      lcd.print("warten auf RFID...");
      delay(100);
      lcd.setCursor(0,1);               
      lcd.print("     Danke          ");
      delay(1500);
      lcd.setCursor(0,2);
      lcd.print("Hallo Nicki!   ");
      lcd.setCursor(0,3);
      lcd.print("Opening the door...!");
      digitalWrite(lockPIN,HIGH);
      delay(2000);
      digitalWrite(lockPIN,LOW);
      Serial.print("Close the door...!");
      lcd.setCursor(0,2);
      lcd.print("             ");
      lcd.setCursor(0,3);
      lcd.print("Close the door...!  ");
      delay(2000);
      lcd.setCursor(0,3);
      lcd.print("                   ");
      delay(2000);
      
    }  
    else if (strcmp(rfidBufferLastRead,"07004525086F")==0){
      Serial.println("Hallo Tom!");
      Serial.print("Opening the door...!");
      lcd.setCursor(0,1);                
      lcd.print("warten auf RFID...");
      delay(100);
      lcd.setCursor(0,1);               
      lcd.print("     Danke          ");
      delay(1500);
      lcd.setCursor(0,2);
      lcd.print("Hallo Tom!   ");
      lcd.setCursor(0,3);
      lcd.print("Opening the door...!");
      digitalWrite(lockPIN,HIGH);
      delay(2000);
      digitalWrite(lockPIN,LOW);
      Serial.print("Close the door...!");
      lcd.setCursor(0,2);
      lcd.print("             ");
      lcd.setCursor(0,3);
      lcd.print("Close the door...!  ");
      delay(2000);
      lcd.setCursor(0,3);
      lcd.print("                   ");
      delay(2000);
    
    }
    else if (strcmp(rfidBufferLastRead,"05008C36E758")==0){
      Serial.println("Hallo Heli!");
      Serial.print("Opening the door...!");
      lcd.setCursor(0,1);                
      lcd.print("warten auf RFID...");
      delay(100);
      lcd.setCursor(0,1);               
      lcd.print("     Danke          ");
      delay(1500);
      lcd.setCursor(0,2);
      lcd.print("Hallo Heli!   ");
      lcd.setCursor(0,3);
      lcd.print("Opening the door...!");
      digitalWrite(lockPIN,HIGH);
      delay(2000);
      digitalWrite(lockPIN,LOW);
      Serial.print("Close the door...!");
      lcd.setCursor(0,2);
      lcd.print("             ");
      lcd.setCursor(0,3);
      lcd.print("Close the door...!  ");
      delay(2000);
      lcd.setCursor(0,3);
      lcd.print("                   ");
      delay(2000);
    
    }
    
    else if (strcmp(rfidBufferLastRead,"070043C3A82F")==0){
      Serial.println("Hallo Richi!");
      Serial.print("Opening the door...!");
      lcd.setCursor(0,1);                
      lcd.print("warten auf RFID...");
      delay(100);
      lcd.setCursor(0,1);               
      lcd.print("     Danke          ");
      delay(1500);
      lcd.setCursor(0,2);
      lcd.print("Hallo Richi!   ");
      lcd.setCursor(0,3);
      lcd.print("Opening the door...!");
      digitalWrite(lockPIN,HIGH);
      delay(2000);
      digitalWrite(lockPIN,LOW);
      Serial.print("Close the door...!");
      lcd.setCursor(0,2);
      lcd.print("             ");
      lcd.setCursor(0,3);
      lcd.print("Close the door...!  ");
      delay(2000);
      lcd.setCursor(0,3);
      lcd.print("                   ");
      delay(2000);
    
    }
    
    else if (strcmp(rfidBufferLastRead,"030023202828")==0){
      Serial.println("*** ROOT TOKKEN ***");
      Serial.print("Opening the door...!");
      lcd.setCursor(0,1);                
      lcd.print("warten auf RFID...");
      delay(100);
      lcd.setCursor(0,1);               
      lcd.print("     Danke          ");
      delay(1500);
      lcd.setCursor(0,2);
      lcd.print("*** ROOT TOKKEN ***");
      lcd.setCursor(0,3);
      lcd.print("Tocken Check       ");
      digitalWrite(lockPIN,HIGH);
      delay(5000);
      Serial.print("*****************");
      lcd.setCursor(0,2);
      lcd.print("                    ");
      lcd.setCursor(0,3);
      lcd.print("***************** ");
      delay(2000);
      lcd.setCursor(0,3);
      lcd.print("                   ");
      delay(2000);
    
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



