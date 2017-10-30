#include <FastSPI_LED.h>

#define NUM_LEDS 9

// Sometimes chipsets wire in a backwards sort of way
struct CRGB { unsigned char b; unsigned char r; unsigned char g; };
// struct CRGB { unsigned char r; unsigned char g; unsigned char b; };
struct CRGB *leds;

#define PIN 3

void setup()
{
  FastSPI_LED.setLeds(NUM_LEDS);
  FastSPI_LED.setChipset(CFastSPI_LED::SPI_TM1809);
   FastSPI_LED.setPin(PIN);
   FastSPI_LED.init();
   FastSPI_LED.start();

  leds = (struct CRGB*)FastSPI_LED.getRGBData(); 

 
/*
  for(int j = 0; j < 3; j++) { 
    for(int i = 0 ; i < NUM_LEDS; i++ ) {
      memset(leds, 0, NUM_LEDS * 3);
      switch(j) { 
        case 0: leds[i].r = 255; break;
        case 1: leds[i].g = 255; break;
        case 2: leds[i].b = 255; break;
      }
      FastSPI_LED.show();
      delay(100);
    }
  }
  */
}
  



void loop() 
{
int i = 4;
int t = 100;
 
leds [i].r = 255; 
  FastSPI_LED.show();
      delay(t);
leds [i].r = 0;
  FastSPI_LED.show();
      delay(t);
      
leds [i].b = 255;
  FastSPI_LED.show();
      delay(t);
leds [i].b = 0; 
  FastSPI_LED.show();
      delay(t);
      
leds [i].g = 255;
  FastSPI_LED.show();
      delay(t);
leds [i].g = 0;
  FastSPI_LED.show();
      delay(t);
  


}

