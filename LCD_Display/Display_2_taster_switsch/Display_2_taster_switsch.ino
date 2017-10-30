//www.ossilampe.de
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 

const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int ledPin1 =  13;
const int ledPin2 =  12;
int buttonState1 = 0;
int buttonState2 = 0;
 
void setup() {
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  
  pinMode(ledPin1, OUTPUT);      //kontrolle led1
  pinMode(buttonPin1, INPUT);    //kontrolle taster1
  pinMode(ledPin2, OUTPUT);      //kontrolle led2
  pinMode(buttonPin2, INPUT);    //kontrolle taster2
}
 
  void loop()
   {
     lcd.setCursor(0,0);                //cursor start position
     lcd.print("www.ossilampe.de");     //ausgabe Text   
     lcd.setCursor(0,1);                //cursor start position zweite Zeile
     lcd.print("Druecke T1 / T2");
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    if (buttonState1 == HIGH) {
    digitalWrite(ledPin1, HIGH);
    lcd.setCursor(0,2);
    lcd.print("T1 Gedrueckt      ");
    
  }
  else 
  {
    digitalWrite(ledPin1, LOW);
    lcd.setCursor(0,2);
    lcd.print("T1 nicht Gedrueckt ");
  }
  if (buttonState2 == HIGH) {
    digitalWrite(ledPin2, HIGH);
    lcd.setCursor(0,3);
    lcd.print("T2 Gedrueckt      ");
    
  }
  else 
  {
    digitalWrite(ledPin2, LOW);
    lcd.setCursor(0,3);
    lcd.print("T2 nicht Gedrueckt");
    
  }
  
}
