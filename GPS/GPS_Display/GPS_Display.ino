#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <TinyGPS.h>


LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7);
TinyGPS gps;
#define RXPIN 3
#define TXPIN 2
SoftwareSerial nss(RXPIN, TXPIN);
void gpsdump(TinyGPS &gps);
bool feedgps();
void printFloat(double f, int digits = 2);
void setup()
{
Serial.begin(115200);
nss.begin(38400);
lcd.begin(16, 2);
//Print a message to the LCD.
lcd.print("Elaboration");
lcd.setCursor(0,1);
lcd.print("coordonnees GPS");
//We test the version of the library
Serial.print("Testing TinyGPS library v. ");
Serial.println(TinyGPS::library_version());
Serial.println(sizeof(TinyGPS));
Serial.println();
}
void loop()
{
bool newdata = false;
unsigned long start = millis();
while(millis() - start < 5000){
if (feedgps())
newdata = true;
}
if (newdata)
{
Serial.println("Acquisition Data");
Serial.println("————-");
gpsdump(gps);
Serial.println("————-");
Serial.println();
}
}


void printFloat(double number, int digits)
{
// Handle negative numbers
if (number < 0.0)
{
number = -number;
}

// Round correctly so that print(1.999, 2) prints as "2.00"
double rounding = 0.5;
for (uint8_t i=0; i<digits; ++i)
rounding /= 10.0;

number += rounding;

// Extract the integer part of the number and print it
unsigned long int_part = (unsigned long)number;
double remainder = number - (double)int_part;

// Print the decimal point, but only if there are digits beyond
if (digits > 0)

// Extract digits from the remainder one at a time
while (digits-- > 0)
{
remainder *= 10.0;
int toPrint = int(remainder);
remainder -= toPrint;
}
}


void gpsdump(TinyGPS &gps)
{
float flat, flon;
lcd.clear();
gps.f_get_position(&flat, &flon);
Serial.print("Lat/Long(float): ");
printFloat(flat, 5);
Serial.print(", ");
printFloat(flon, 5);
lcd.print("lat:");
lcd.print(flat,5);
lcd.setCursor(0,1);
lcd.print("lon: ");
lcd.print(flon,5);
feedgps();
}
bool feedgps()
{
while (nss.available())
{
if (gps.encode(nss.read()))
return true;
}
return false;
}
