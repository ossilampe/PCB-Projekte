#include <LiquidCrystal.h>

/* 
 LiquidCrystal display with:
 LCD 1 (0V) to arduino ground pin 14 
 LCD 2 (5V) to arduino +5 V
 LCD 3 (V0) to output from potentiometer 10kOhm connected between +5 V and GND
 LCD 4 (RS) to arduino pin 12
 LCD 5 (R/W) to arduino ground
 LCD 6 (E) to arduino pin 11
 LCD 11 (DB4), 12 (DB5), 13 (DB6), 14 (DB7) on arduino pins 7, 8, 9, 10 
 LCD15 (LED+) through resistor 12 Ohm to arduino +5 V
 LCD16 (LED-) to arduino ground 
 */

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

void setup()
{
  lcd.begin(20, 4); //lcd.begin(columns, rows)
  lcd.setCursor(2,0); // Position cursor on line x=3,y=1
  lcd.print("4x20 LCD DISPLAY"); // Print a message to the LCD
  lcd.setCursor(3,1);
  lcd.print("with controller");
  lcd.setCursor(7,2);
  lcd.print("HD44780");
  lcd.setCursor(1,3);
  lcd.print("useful for Arduino");
}

void loop()
{
}

Více zde: http://www.hwkitchen.com/products/lcd-display-4x20-characters/
