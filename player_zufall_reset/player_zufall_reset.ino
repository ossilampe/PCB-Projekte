
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>
#define BREAKOUT_RESET  9      // VS1053 reset pin (output)
#define BREAKOUT_CS     10     // VS1053 chip select pin (output)
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)
#define CARDCS 4     // Card chip select pin
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin

Adafruit_VS1053_FilePlayer musicPlayer = 
Adafruit_VS1053_FilePlayer(BREAKOUT_RESET, BREAKOUT_CS, BREAKOUT_DCS, DREQ, CARDCS);
long randNumber;
  
void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit VS1053 Simple Test"); 
  
  randomSeed(analogRead(0));
  randNumber = random(1, 6);
  Serial.println(randNumber);
  
       if (! musicPlayer.begin()) { // initialise the music player
           Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
        while (1);
        }
        
  Serial.println(F("VS1053 found"));
  SD.begin(CARDCS);    // initialise the SD card
  
  //Lautstärke
  musicPlayer.setVolume(20,20);
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int

  /*
  // Play one file, don't return until complete
  Serial.println(F("Playing track 001"));
  musicPlayer.playFullFile("track001.mp3");
  // Play another file in the background, REQUIRES interrupts!
  Serial.println(F("Playing track 002"));
  musicPlayer.startPlayingFile("track002.mp3");
*/


  switch (randNumber) {
  case 1:
     musicPlayer.startPlayingFile("track001.mp3");
     Serial.println(F("Playing track 001"));
    break;
  case 2:
     musicPlayer.startPlayingFile("track002.mp3");
     Serial.println(F("Playing track 002"));
    break;
      case 3:
     musicPlayer.startPlayingFile("track003.mp3");
     Serial.println(F("Playing track 003"));
    break;
      case 4:
     musicPlayer.startPlayingFile("track004.mp3");
     Serial.println(F("Playing track 004"));
    break;
      case 5:
     musicPlayer.startPlayingFile("track005.mp3");
     Serial.println(F("Playing track 005"));
    break;
  default:
    musicPlayer.stopPlaying();
    break;
}
}



void loop() 
{
  
}




/*{
  // File is playing in the background
  if (musicPlayer.stopped()) {
    Serial.println("Done playing music");
    while (1);
  }
  if (Serial.available()) {
    char c = Serial.read();
    
    // if we get an 's' on the serial console, stop!
    if (c == 's') {
      musicPlayer.stopPlaying();
    }
    
    // if we get an 'p' on the serial console, pause/unpause!
    if (c == 'p') {
      if (! musicPlayer.paused()) {
        Serial.println("Paused");
        musicPlayer.pausePlaying(true);
      } else { 
        Serial.println("Resumed");
        musicPlayer.pausePlaying(false);
      }
    }
  }

  delay(100);
}
*/
