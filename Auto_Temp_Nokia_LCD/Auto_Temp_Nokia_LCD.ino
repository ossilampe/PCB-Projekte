//  original sketch by niq_ro from http://nicuflorica.blogspot.com for dual thermometer with LM335
//  version 1m1 - 2013.10.23, Craiova - Romania
//  Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
//  Copyright (c) 2012, olikraus@gmail.com
//  All rights reserved.

#include "U8glib.h"
// ecran de Nokia 3410
//U8GLIB_PCF8812 u8g(13, 11, 10, 9, 8); // SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9, Reset = 8
U8GLIB_PCF8812 u8g(3,4,6,5,7); // la mine
/*               ----------------------------
                 | Arduino | Nokia 3410 LCD |
                 ----------------------------
                 |    D3   |       SCK      |
                 |    D4   |       MOSI     |
                 |    D5   |     D/C (A0)   |
                 |    D6   |        CS      |
                 |    D7   |      RESET     |
                 ----------------------------
*/

// temperaturi
int t1, t2;
float t10, t20;
float t11, t21;
float t12, t22;

int temperaturePin1 = A0; 
int temperaturePin2 = A1; 
// cei 2 senzori de temperaturi LM335 sunt legati la pinii A0 si A1

// indicator de confort  
int led = 13; //pin for LED
int ledr = 11; // LED-ul rosu e conectat la pinul 11
int leda = 12; // LED-ul albastru e conectat la pinul 10
int ledv = 9; // LED-ul verde e conectat la pinul 9



void subrutina0(void) {
  // pictez un chenar
 // u8g.drawFrame(0,0,95,65);
  // pun un font maricel
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
 
    
 // u8g.setFont(u8g_font_unifont);
 u8g.setFont(u8g_font_7x14);
  u8g.drawStr( 12, 20, "ossilampe");
  u8g.setFont(u8g_font_5x7);
  u8g.drawStr( 9, 38, "");

}


void subrutinat1(uint8_t t101)
//void subrutinat1(int t101)
{
char s[2] = " ";

u8g.setFont(u8g_font_5x7);
 u8g.drawStr(15, 18, "ext");

/* if (t101=0)
 {
   // schimb semnul
s[0]=48; // transform cifrele in caractere ASCII
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(25, 32, "0.0");
// u8g.drawStr(58, 32, s);
 }
else
*/
if (t101<10 & t101>0)
 {
   // see http://www.asciitable.com/
s[0]=t101+48; // transform cifrele in caractere ASCII
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(25, 32, "+0.");
 u8g.drawStr(58, 32, s);
 }
else
if (t101<100 & t101>=10)
{
  // afla cifra unitatilor
s[0]=int(t101/10)+48;
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(25, 32, "+");
u8g.drawStr(40, 32, s);
u8g.drawStr(48, 32, ".");
  // afla cifra dupa virgula
s[0]=t101-10*int(t101/10)+48;
 u8g.drawStr(58, 32, s);
}
else
if (t101>=100)
{
// afla cifra zecilor
s[0]=int(t101/100)+48;
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(18, 32, "+");
u8g.drawStr(28, 32, s);
// afla numarul de la unitati in jos
t101 = t101-100*int(t101/100);
s[0]=int(t101/10)+48;
 u8g.drawStr(38, 32, s);
// afla cifra dupa virgula
u8g.drawStr(48, 32, ".");
s[0]=t101-10*int(t101/10)+48;
 u8g.drawStr(58, 32, s);
}
else
if (t101>-10 & t101<0)
 {
   // schimb semnul
t101 = -t101;
s[0]=t101+48; // transform cifrele in caractere ASCII
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(28, 32, "-0.");
 u8g.drawStr(58, 32, s);
 }
else
if (t101>-100 & t101<10)
 {
   // schimb semnul
t101 = -t101;
  // aflu cifra unitatilor
s[0]=int(t101/10)+48; // transform cifrele in caractere ASCII
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(28, 32, "-");
 u8g.drawStr(38, 32, s);
 u8g.drawStr(48, 32, ".");
  // aflu cifra dupa virgula
s[0]=t101-10*int(t101/10)+48; // transform cifrele in caractere ASCII 
 u8g.drawStr(58, 32, s);
 }
else
if (t101<=100)
{
// schimb semnul
t101=-t101;
// afla cifra zecilor
s[0]=int(t101/100)+48;
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(18, 32, "-");
u8g.drawStr(28, 32, s);
// afla numarul de la unitati in jos
t101 = t101-100*int(t101/100);
s[0]=int(t101/10)+48;
 u8g.drawStr(38, 32, s);
// afla cifra dupa virgula
u8g.drawStr(48, 32, ".");
s[0]=t101-10*int(t101/10)+48;
 u8g.drawStr(58, 32, s);
}
// afisez grade Celsius
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(70, 26, "o");
 u8g.drawStr(80, 32, "C");
}

// void subrutinat2(uint8_t t102)
void subrutinat2(int t102)
{
char s[2] = " ";
// folosesc font mare, pentru a vedea de la distanta
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(4, 45, "t  :");
// folosesc font mic pentru indice
u8g.setFont(u8g_font_7x14);
 u8g.drawStr(15, 48, "int");

/*if (t102=0)
 {
 s[0]=48; // transform cifrele in caractere ASCII
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(25, 32, "0.0");
// u8g.drawStr(58, 32, s);
 }
else
*/
if (t102<10 & t102>0)
 {
   // see http://www.asciitable.com/
s[0]=t102+48; // transform cifrele in caractere ASCII
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(25, 62, "+0.");
 u8g.drawStr(58, 62, s);
 }
else
if (t102<100 & t102>=10)
{
  // afla cifra unitatilor
s[0]=int(t102/10)+48;
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(25, 62, "+");
u8g.drawStr(40, 62, s);
u8g.drawStr(48, 62, ".");
  // afla cifra dupa virgula
s[0]=t102-10*int(t102/10)+48;
 u8g.drawStr(58, 62, s);
}
else
if (t102>=100)
{
// afla cifra zecilor
s[0]=int(t102/100)+48;
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(18, 62, "+");
u8g.drawStr(28, 62, s);
// afla numarul de la unitati in jos
t102 = t102-100*int(t102/100);
s[0]=int(t102/10)+48;
 u8g.drawStr(38, 62, s);
// afla cifra dupa virgula
u8g.drawStr(48, 62, ".");
s[0]=t102-10*int(t102/10)+48;
 u8g.drawStr(58, 62, s);
}
else
if (t102>-10 & t102<0)
 {
   // schimb semnul
t102 = -t102;
s[0]=t102+48; // transform cifrele in caractere ASCII
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(28, 62, "-0.");
 u8g.drawStr(58, 62, s);
 }
else
if (t102>-100 & t102<10)
 {
   // schimb semnul
t102 = -t102;
  // aflu cifra unitatilor
s[0]=int(t102/10)+48; // transform cifrele in caractere ASCII
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(28, 62, "-");
 u8g.drawStr(38, 62, s);
 u8g.drawStr(48, 62, ".");
  // aflu cifra dupa virgula
s[0]=t102-10*int(t102/10)+48; // transform cifrele in caractere ASCII 
 u8g.drawStr(58, 62, s);
 }
else
if (t102<=100)
{
// schimb semnul
t102=-t102;
// afla cifra zecilor
s[0]=int(t102/100)+48;
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(18, 62, "-");
u8g.drawStr(28, 62, s);
// afla numarul de la unitati in jos
t102 = t102-100*int(t102/100);
s[0]=int(t102/10)+48;
 u8g.drawStr(38, 62, s);
// afla cifra dupa virgula
u8g.drawStr(48, 62, ".");
s[0]=t102-10*int(t102/10)+48;
 u8g.drawStr(58, 62, s);
}
// afisez grade Celsius
u8g.setFont(u8g_font_10x20);
 u8g.drawStr(70, 56, "o");
 u8g.drawStr(80, 62, "C");
}



void setup(void) {
  
  // flip screen, if required
  // u8g.setRot180();
  
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
  // parte de prezentare
  u8g.firstPage();  
  do {
    subrutina0(); // unde e mesajul de intampinare
  } while( u8g.nextPage() );
 delay(3000);


}


void loop(void) {

  // Read and store Sensor Data
t11=0;
t21=0;
//lcd.clear(); // clear the screen

for (int x=1; x <= 5; x++)
  {
// calculate the value  
t1 = analogRead(temperaturePin1); // read value from temperature from first sensor (LM335);
 t10 = 100.0*(5.0*t1/1023-2.980)+25.0;
 t11 = t10 + t11;

t2 = analogRead(temperaturePin2); // read value from temperature from second sensor (LM335);
 t20 = 100.0*(5.0*t2/1023-2.980)+25.0;
 t21 = t20 + t21;

delay (500);
  }   

t12 = t11/5.0 -1.0 ; // calculez media si fac corectie
t22 = t21/5.0 -2.0; // calculez media si fac corectie  

float t123=10*t12; // inmultesc cu 10 ca sa pot face afisarea
float t223=10*t22;

/*
 // fac teste de afisare a primei temperaturi
int t1=-765; // atentie temperatura este inmultita cu 10...
int t2=0.1; // atentie temperatura este inmultita cu 10...
*/

{
 u8g.firstPage();  // incepere parte de grafica
  do { // face asta pana termina ce e in subrutina de desenat
    subrutinat1(t123); // munceste la ce e in subrutinat1
    subrutinat2(t223); // munceste la ce e in subrutinat1
    } while( u8g.nextPage() ); // pana o termina
 delay(1000); // sta o secunda
}
// temperature led indicator
analogWrite(leda,0); // sting LED-ul albastru
analogWrite(ledr,0);  // sting LED-ul rosu
analogWrite(ledv,0); // sting LED-ul verde
if (t22<=19.0) analogWrite(leda, 255);
if ((t22>19.0) and (t22<26.0)) analogWrite(ledv, 255);
if (t22>=26.0) analogWrite(ledr, 255);

}
