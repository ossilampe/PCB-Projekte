// Uncomment this line if you have any interrupts that are changing pins - this causes the library to be a little bit more cautious
// #define FAST_SPI_INTERRUPTS_WRITE_PINS 1

// Uncomment this line to force always using software, instead of hardware, SPI (why?)
// #define FORCE_SOFTWARE_SPI 1

// Uncomment this line if you want to talk to DMX controllers
// #define FASTSPI_USE_DMX_SIMPLE 1

#include "FastSPI_LED2.h"
#include <Wire.h>
#include "RTClib.h"

#include <OneWire.h>
#include <DallasTemperature.h>


RTC_DS1307 rtc;

#define NUM_LEDS 60

#define ONE_WIRE_BUS 7 

CRGB leds[NUM_LEDS];

OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);

// Taster
const int buttonPinModus = 5;    // Stellenmodus
int buttonStateModus = 0;
int buttonStateModusOld = 0;
const int buttonPinMinuten = 4;    // Minuten
int buttonStateMinuten = 0;
int buttonStateMinutenOld = 0;
const int buttonPinStunden = 3;    // Stunden
int buttonStateStunden = 0;
int buttonStateStundenOld = 0;
const int buttonPinDisplay = 8;    // Anzeigemodus
int buttonStateDisplay = 0;
int buttonStateDisplayOld = 0;

// DayNightLED
int LEDGreen=9;
int LEDBlue=10;
int LEDRed=11;

// Uhrzeit Voreinstellung
volatile int stunde = 1;
volatile int displaystunde = 0;
volatile int minuten = 27;
volatile int sekunde = 30;
volatile int daynight = 0;

int DisplayMode = 0;        // Anzeigemodus

DateTime volatile t;
float temp;

/*
long debouncing_time = 100; //Debouncing Time in Milliseconds
 volatile unsigned long last_micros;
 */

void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  //delay(2000);
  Serial.begin(9600);

  pinMode(2, INPUT);                    // Test of the SQW pin, D2 = INPUT
  digitalWrite(2, HIGH);                // Test of the SQW pin, D2 = Pullup on
  attachInterrupt(0, DisplayIntTime, FALLING);  // RTC

#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(__DATE__, __TIME__));
  }

  // For safety (to prevent too high of a power draw), the test case defaults to
  // setting brightness to 25% brightness
  LEDS.setBrightness(255);

  LEDS.addLeds<WS2812, 6>(leds, NUM_LEDS);

  pinMode(LEDRed,OUTPUT);
  pinMode(LEDGreen,OUTPUT);
  pinMode(LEDBlue,OUTPUT);  

  //sensors.begin();/* Inizialisieren der Dallas Temperature library */

  //adresseAusgeben(); /* Adresse der Devices ausgeben */

  //attachInterrupt(0, debounceInterrupt, RISING);

  DateTime t = rtc.now();
  sekunde = t.second();
  minuten = t.minute();
  stunde = t.hour();
  Serial.print(t.year(), DEC);
  Serial.print('/');
  Serial.print(t.month(), DEC);
  Serial.print('/');
  Serial.print(t.day(), DEC);
  Serial.print(' ');
  Serial.print(t.hour(), DEC);
  Serial.print(':');
  Serial.print(t.minute(), DEC);
  Serial.print(':');
  Serial.print(t.second(), DEC);
  Serial.println();
}

void loop() { 

  // Taster abfragen
  buttonStateModus = digitalRead(buttonPinModus);
  buttonStateDisplay = digitalRead(buttonPinDisplay);
  buttonStateMinuten = digitalRead(buttonPinMinuten);
  buttonStateStunden = digitalRead(buttonPinStunden);

  if (buttonStateModus == HIGH) {    
    buttonStateModusOld = buttonStateModus;
    Serial.println(" Modus" + buttonStateModus);
    //minuten = minuten + 1;
  }
  if (buttonStateDisplay == HIGH && buttonStateDisplayOld == LOW ) {      
    Serial.println(" Display" + buttonStateDisplay);
    DisplayMode = DisplayMode + 1;
    if (DisplayMode > 3)
      DisplayMode = 0;
  }
  if (buttonStateMinuten == HIGH) {    
    Serial.println(" Minuten" + buttonStateMinuten);
    //minuten = minuten + 1;
  }
  if (buttonStateStunden == HIGH) {    
    Serial.println(" Stunden" + buttonStateStunden);
    //minuten = minuten + 1;
  }
  
  buttonStateDisplayOld = buttonStateDisplay;

  // Temperatur abfragen
  sensors.requestTemperatures(); // Temp abfragen
  //Serial.println("Temperatur");
  temp = sensors.getTempCByIndex(0);
  //Serial.println(sensors.getTempCByIndex(0) );

  delay(100);
}

/* Debugfuntkionen
void adresseAusgeben(void) {
 byte i;
 byte present = 0;
 byte data[12];
 byte addr[8];
 
 Serial.print("Suche 1-Wire-Devices...\n\r");// "\n\r" is NewLine 
 while(ourWire.search(addr)) {
 Serial.print("\n\r\n\r1-Wire-Device gefunden mit Adresse:\n\r");
 for( i = 0; i < 8; i++) {
 Serial.print("0x");
 if (addr[i] < 16) {
 Serial.print('0');
 }
 Serial.print(addr[i], HEX);
 if (i < 7) {
 Serial.print(", ");
 }
 }
 if ( OneWire::crc8( addr, 7) != addr[7]) {
 Serial.print("CRC is not valid!\n\r");
 return;
 }
 }
 Serial.println();
 ourWire.reset_search();
 return;
 }
 */

/*
void debounceInterrupt() {
 if((long)(micros() - last_micros) >= debouncing_time * 1000) {
 Interrupt();
 last_micros = micros();
 }
 }
 
 void Interrupt() {
 sensors.requestTemperatures(); // Temp abfragen
 //Serial.println("Temperatur");
 temp = sensors.getTempCByIndex(0);
 //Serial.println(sensors.getTempCByIndex(0) );
 }
 */

void DisplayIntTime()
{
  Serial.println(" Interrupt"); 
  Serial.print("DisplayMode: ");
  Serial.println(DisplayMode); 
  
  sekunde = sekunde + 1;

  if (sekunde > 59)
  {
    sekunde = 0;
    minuten = minuten + 1; 
  }

  if (minuten > 59)
  {
    minuten = 0;
    stunde = stunde + 1;
  }

  if (stunde > 23)
  {
    stunde = 0; 
  }

  memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));    // Alle LEDs löschen

  if (DisplayMode == 0)
  {
  
  }  
  else if (DisplayMode == 1)
  {
    for (int ix = 0; ix <= 60; ix++)
    {
      leds[ix] = CRGB(32, 32, 0);     
    }
  }
  else if (DisplayMode == 2)
  {
    for (int ix = 0; ix <= 60; ix++)
    {
      leds[ix] = CRGB(32, 32, 32);     
    }
  }
  else if (DisplayMode == 3)
  {
    for (int ix = 0; ix <= sekunde; ix++)
    {
      leds[ix] = CRGB(0, 0, 128);     
    }
  }
  
  // Helligkeit der Tageszeit anpassen
  if (stunde >= 6 && stunde <= 20)
    LEDS.setBrightness(255);
  else
    LEDS.setBrightness(128);
  
  
  if (stunde >= 12 && stunde <= 23)
  {
    displaystunde = ((stunde - 12) * 5 + (minuten / 12));
    daynight = 1;
  }
  if (stunde >= 0 && stunde < 12)
  {

    displaystunde = stunde * 5 + (minuten / 12);
    //displaystunde = 0; 
    daynight = 0;
  }

  //Serial.print("DS: ");
  //Serial.println(displaystunde, DEC);
  leds[displaystunde] = CRGB(0, 128, 0); 
  leds[minuten] = CRGB(128, 0, 0); 

  // Farben mischen, wenn übereinander
  if (sekunde == minuten)
    leds[sekunde] = CRGB(128, 0, 128);  
  else if (sekunde == displaystunde)
    leds[sekunde] = CRGB(0, 128, 128);  
  else
    leds[sekunde] = CRGB(0, 0, 128);  

  // Tag-/Nacht-Anzeige
  if (daynight == 0)
  {
    analogWrite(LEDRed, 255);    
    analogWrite(LEDGreen, 255); 
    analogWrite(LEDBlue, 200); 
  }
  else
  {
    analogWrite(LEDRed, 255);    
    analogWrite(LEDGreen, 200); 
    analogWrite(LEDBlue, 255); 
  }

  // Und dann alles anzeigen
  LEDS.show();
}

