// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN_VORNE   52 
#define ECHO_PIN_VORNE      50

#define TRIGGER_PIN_Rechts  48
#define ECHO_PIN_Rechts     46

#define TRIGGER_PIN_Back    44
#define ECHO_PIN_Back       42

#define TRIGGER_PIN_Links   40
#define ECHO_PIN_Links      38

#define MAX_DISTANCE_Vorne  100   // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define MAX_DISTANCE_Rechts 100
#define MAX_DISTANCE_Hinten 100
#define MAX_DISTANCE_Links  100

NewPing sonar_vorne(TRIGGER_PIN_VORNE, ECHO_PIN_VORNE, MAX_DISTANCE_Vorne); // NewPing setup of pins and maximum distance.
NewPing sonar_rechts(TRIGGER_PIN_Rechts, ECHO_PIN_Rechts, MAX_DISTANCE_Rechts);
NewPing sonar_hinten(TRIGGER_PIN_Back, ECHO_PIN_Back, MAX_DISTANCE_Hinten);
NewPing sonar_links(TRIGGER_PIN_Links, ECHO_PIN_Links, MAX_DISTANCE_Links);

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  {
  delay(500);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar_vorne.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm Vorne");
  }
  {
  delay(500);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar_rechts.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm Rechts");
  }
  {
  delay(500);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar_hinten.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm Hinten");
  }
  {
  delay(500);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar_links.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm Links");
  }
}
