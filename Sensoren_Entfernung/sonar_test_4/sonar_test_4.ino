// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN_Vorne   4 
#define ECHO_PIN_Vorne      8

#define TRIGGER_PIN_Rechts  4
#define ECHO_PIN_Rechts     9

#define TRIGGER_PIN_Back    4
#define ECHO_PIN_Back       10

#define TRIGGER_PIN_Links   4
#define ECHO_PIN_Links      11

#define MAX_DISTANCE_Vorne  10   // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define MAX_DISTANCE_Rechts 10
#define MAX_DISTANCE_Hinten 10
#define MAX_DISTANCE_Links  10

NewPing sonar_vorne(TRIGGER_PIN_Vorne, ECHO_PIN_Vorne, MAX_DISTANCE_Vorne); // NewPing setup of pins and maximum distance.
NewPing sonar_rechts(TRIGGER_PIN_Rechts, ECHO_PIN_Rechts, MAX_DISTANCE_Rechts);
NewPing sonar_hinten(TRIGGER_PIN_Back, ECHO_PIN_Back, MAX_DISTANCE_Hinten);
NewPing sonar_links(TRIGGER_PIN_Links, ECHO_PIN_Links, MAX_DISTANCE_Links);

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  
  
  
  //Setup Channel A
    pinMode(12, OUTPUT); //Initiates Motor Channel A pin
    pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
    pinMode(13, OUTPUT); //Initiates Motor Channel B pin
    pinMode(8, OUTPUT);  //Initiates Brake Channel B pin

  }

  void AllStop()  //Stop
  {
    digitalWrite(9, HIGH);   //Disengage the Brake for Channel A
    digitalWrite(8, HIGH);   //Disengage the Brake for Channel B
    delay(1000);
  }
  
  void AllVor() //Vorwärts
  { 
   // Channal A
   digitalWrite(12, HIGH);  //Laufrichtung
   digitalWrite(9, LOW);   //Bremse aus
   analogWrite(3, 220);    //SPEED
   // Channal B
   digitalWrite(13, LOW); 
   digitalWrite(8, LOW);   
   analogWrite(11, 215);
   delay(300);
  }
  
  void turnRight() //Rechtsrum
  { 
    digitalWrite(12, LOW); 
    digitalWrite(9, LOW);   
    analogWrite(3, 150);   
   
    digitalWrite(13,LOW);
    digitalWrite(8, LOW);   
    analogWrite(11, 150);   
    delay(400);
    
  }
  
  void GoBack()  //zurück
  { 
    digitalWrite(12, LOW); 
    digitalWrite(9, LOW);   
    analogWrite(3, 123);   
    
    digitalWrite(13, HIGH);  
    digitalWrite(8, LOW);   
    analogWrite(11, 123);    
    delay(1000);
    
  }
  
  void AllBackAus()//kurz zurück vor turn
  {
    digitalWrite(12, LOW); 
    digitalWrite(9, LOW);   
    analogWrite(3, 180);   
    
    digitalWrite(13, HIGH);  
    digitalWrite(8, LOW);   
    analogWrite(11, 180);    
    delay(1000);  
  
  
  }
  
   void AllBackSlow()//kurz zurück vor turn
  {
    digitalWrite(12, LOW); 
    digitalWrite(9, LOW);   
    analogWrite(3, 120);   
    
    digitalWrite(13, HIGH);  
    digitalWrite(8, LOW);   
    analogWrite(11, 120);    
    delay(500);  
  
  
  }
  
   void turnLeft() //Linksrum
   { 
     digitalWrite(12, HIGH); 
     digitalWrite(9, LOW);   
     analogWrite(3, 150);   
   
     digitalWrite(13, HIGH); 
     digitalWrite(8, LOW);   
     analogWrite(11, 150);  
     delay(400);
   
  }

void AllVorSlow() //Vorwärts
  { 
   // Channal A
   digitalWrite(12, HIGH);  //Laufrichtung
   digitalWrite(9, LOW);   //Bremse aus
   analogWrite(3, 120);    //SPEED
   // Channal B
   digitalWrite(13, LOW); 
   digitalWrite(8, LOW);   
   analogWrite(11, 120);
   delay(500);
  }



void loop() {
  
  
    //delay(300);  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    int channelA = analogRead(A0);
    int channelB = analogRead(A1);
    int irDistHinten = analogRead(A3);   //Sharp IR Hinten pin A3
    //Serial.println("Current A " + String(channelA));
    //Serial.println("Current B " + String(channelB));
    //Serial.println("IR Dist " + String(irDistHinten)); //IR Hinten
    
    
    
    


  {
  delay(1000);                      
  unsigned int uSvorne = sonar_vorne.ping(); 
  Serial.println("Vorne Ping " + String(uSvorne / US_ROUNDTRIP_CM));
 
  }
  {
  delay(1000);                     
  unsigned int uSrechts = sonar_rechts.ping();
  Serial.println("Rechts Ping " + String(uSrechts / US_ROUNDTRIP_CM));
  
  }
  {
  delay(1000);                   
  unsigned int uShinten = sonar_hinten.ping();
  Serial.println("Hinten Ping " + String(uShinten / US_ROUNDTRIP_CM));
  
  
  }
  {
  delay(1000);                      
  unsigned int uSlinks = sonar_links.ping(); 
  Serial.println("Links Ping " + String(uSlinks / US_ROUNDTRIP_CM));
  }
}
