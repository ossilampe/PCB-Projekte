/*
 Connect a Navman Jupiter 12 GPS module to the Arduino
 Listen for the $GPRMC string and extract the GPS location data from this.
 Display the result on a HD44780 compatible LCD display.
 More details and wiring here http://zorg.org/d5
 Picture http://flic.kr/p/a2iUVE
 */ 
 #include <string.h>
 #include <ctype.h>
 //#include <LiquidCrystal.h>
 #include <Wire.h> 
 #include <LiquidCrystal_I2C.h>
 int ledPin = 13;                  // LED test pin
 int rxPin = 0;                    // RX PIN 
 int byteGPS=-1;
 char linea[300] = "";
 char comandoGPR[7] = "$GPRMC";
 int cont=0;
 int good=0;
 int conta=0;
 int indices[13];

 // initialize the LCD library with the numbers of the interface pins
//LiquidCrystal lcd(8, 7, 5, 4, 3, 2);
LiquidCrystal_I2C lcd(0x27,20,4);

 void setup() {
   lcd.init();                      // initialize the lcd 
   lcd.init();
   lcd.backlight();
   pinMode(ledPin, OUTPUT);       // Initialize LED pin
   pinMode(rxPin, INPUT);
   Serial.begin(9600);
   for (int i=0;i<300;i++){       // Initialize a buffer for received data
     linea[i]=' ';
  //lcd.begin(20, 4);               // set up the LCD's number of rows and columns
   }   
 }
 void loop() {
   digitalWrite(ledPin, HIGH);
   byteGPS=Serial.read();         // Read a byte of the serial port
   if (byteGPS == -1) {           // See if the port is empty yet
     delay(100); 
   } else {
     linea[conta]=byteGPS;        // If there is serial port data, it is put in the buffer
     conta++;                      

     if (byteGPS==13){            // If the received byte is = to 13, end of transmission
       digitalWrite(ledPin, LOW); 
       cont=0;
       good=0;
       for (int i=1;i<7;i++){     // Verifies if the received command starts with $GPR
         if (linea[i]==comandoGPR[i-1]){
           good++;
         }
       }
       if(good==6){               // If yes, continue and process the data
         for (int i=0;i<300;i++){
           if (linea[i]==','){    // check for the position of the  "," separator
             indices[cont]=i;
             cont++;
           }
           if (linea[i]=='*'){    // ... and the "*"
             indices[11]=i;
             cont++;
           }
         }

         for (int i=0;i<12;i++){
           switch(i){
             case 0 :lcd.setCursor(0, 2);lcd.print("Time (UTC): ");
             for (int j=indices[i];j<(indices[1]-1);j++){
             lcd.print(linea[j+1]); 
             };
             break;
             
             case 1 :lcd.setCursor(14, 3);lcd.print("Sts: ");
             for (int j=indices[i];j<(indices[3]-1);j++){
             lcd.print(linea[j+1]); 
             };
             break;

             case 2 :lcd.setCursor(0, 0);lcd.print("Lat: ");         
             for (int j=indices[i];j<(indices[4]-1);j++){
             lcd.print(linea[j+1]); 
             };
             break;
             
             case 4 :lcd.setCursor(0, 1);lcd.print("Long: ");
             for (int j=indices[i];j<(indices[6]-1);j++){
             lcd.print(linea[j+1]); 
             };
             break;
             
             case 8 :lcd.setCursor(0, 3);lcd.print("Date: ");
             for (int j=indices[i];j<(indices[9]-1);j++){
             lcd.print(linea[j+1]); 
             };
             break;
           }         

         }

       }
       conta=0;                    // Reset the buffer
       for (int i=0;i<300;i++){    //  
         linea[i]=' ';             
       }                 
     }
   }
 }

