  // Initialisierung mit 2 Pins, Vollschritt
  // RESET muss an SLEEP angeschlossen werden
AH_Pololu(int RES,int DIR,int STEP)

  // Initialisierung mit 6 Pins, Änderung der Mikroschrittauflösung
  // und Sleep-Modus sind verfügbar.
  // RESET muss an SLEEP angeschlossen werden
AH_Pololu(int RES,int DIR,int STEP,int MS1,int MS2,int MS3,int SLEEP)

  // Initialisierung mit 9 Pins, alle Funktionen vorhanden.
AH_Pololu(int RES,int DIR,int STEP,int MS1,int MS2,int MS3,
              int SLEEP,int ENABLE,int RESET)


  // Modul zurücksetzen
void resetDriver()

  // Modul ein- oder ausschalten
void enableDriver()
void disableDriver()

  // Schlaf-Modus ein- und ausschalten
void sleepON()
void sleepOFF()

  // Geschwindigkeit ändern
void setSpeedRPM(int RPM)
void setSpeedHz(int FREQ)
void setSpeedMax()

  // Mikroschritt-Modus wählen
  //  MODE 0 -> Vollschritt
  //  MODE 1 -> 1/2  Mikroschritt
  //  MODE 2 -> 1/4  Mikroschritt
  //  MODE 3 -> 1/8  Mikroschritt
  //  MODE 4 -> 1/16 Mikroschritt
void setMicrostepping(int MODE)

  // Motorsteuerung
void move(int NUMBER_OF_STEPS)
void move(int NUMBER_OF_STEPS, boolean DIRECTION)
void rotate(float DEGREES)
void revolve(float TIMES)

  // Bibliothekversion
String getVersion()
