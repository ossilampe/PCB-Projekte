/*ESP8266_Trinket_01.ino Arduining.com (29 APR 2015)
Sending temperature data to ThingSpeak.
Hardware:
 -Adafruit's Arduino Trinket (3.3V)
 -ESP8266(ESP-01)
 -Temperature sensor TMP35

Data update rate set by the SPERIOD value.
Using SoftwareSerial at 9600 bauds.
String and math functions avoided.
The temperature is not calibrated.
  -ATtiny85 internal reference differs a little from 1.1V
  -The TMP35 is affected by radio frequencies.

Sketch uses 4,748 bytes (89%) of program storage space. Maximum is 5,310 bytes.
-----------------------------------------------------------------------------*/

#include <SoftwareSerial.h> 

//Network parameters and server IP address:
#define mySSID    "tom_home"           //WiFi network ID.
#define myPASS    "heimnetz"           //Password.
#define serverIP  "184.106.153.149"     //IP of ThingSpeak.com
#define ChannKEY  "YM1VOB60D5274RLU"    //ThingSpeak channel key.

#define updField1  "1"                   //Updating Field( 1,2,3,4,5...)
#define updField2  "2"                   //Updating Field( 1,2,3,4,5...)
#define updField3  "3"                   //Updating Field( 1,2,3,4,5...)
#define SPERIOD   30000                 //Sampling period (milliseconds).
#define MAXFAILS  10                    //Number of fails to RESET the ESP8266.

//Concatenating the string messages:
#define mode_MSG  "AT+CWMODE=3\r\n"       //Dual mode (Station and Access Point).
#define join_MSG  "AT+CWJAP=\"" mySSID "\",\"" myPASS "\"\r\n"      //set data to join the AP.
#define conn_MSG  "AT+CIPSTART=\"TCP\",\"" serverIP "\",80\r\n"     //TCP, ThingSpeak, port 80.
#define send_MSG  "AT+CIPSEND=46\r\n"     //Send data, size=46 (4 bytes for the value)
#define upda_MSG  "GET /update?key=" ChannKEY "&field" updField1 "=" //Updating Field data.
#define clos_MSG  "AT+CIPCLOSE\r\n"       //Close TCP connection.


//Trinket pins assignament:
#define RXDATA    1      // SoftwareSerial receive pin (RED LED connected).
#define TXDATA    0      // SoftwareSerial transmit pin.
#define HRESET    3      // Pin to hardware Reset the ESP8266
#define ANATEMP   1      // Analog channel 1 for temperature measurement.

int i,j;
int fails=100;           // set failures>MAXFAILS to generate initial RESET.
unsigned int temp;       // Use positive range values (0-32768)
String tempVal="00.0";   // Four characters (fixed format number).

SoftwareSerial ESPSerial(RXDATA, TXDATA);   // Creates SoftwareSerial channel.

//====================== Setup ================================================
void setup(){
  
  //analogReference(INTERNAL);        //Use the 1.1V internal reference.
  pinMode(HRESET,OUTPUT);           //hardware reset for the ESP8266.
  ESPSerial.begin(115200);
  initESP();                        // ESP8266 init.

}   //END of setup.

//====================== loop =================================================
void loop(){

  while((millis() % SPERIOD)>10){};   //Wait for the next multiple of SPERIOD.

  while(ESPSerial.read()!= -1){};     //Wait until no serial data available.

//------------- Here is the temperature reading for the TMP35 ------------------
/*-------------------------------------------------------------------
    For compactness of the code, integer math is used:
    TheTMP35 has 10 mV/°C scale factor:Temp in °C = (Vout in mV)/10 
    With Vref=1.1V the range is: 0°C to +60°C, (0.1 degree resolution)
    AnalogRead value (559) => 60 degree.
    32768/1024= 32 (maximum multiplier to keep the integer positive).
    Multiplier and divider factors are: 29/27= 1.0740 close to 1100/1024.
 --------------------------------------------------------------------*/
  temp= (analogRead(100)* 29)/27;  //value in millivolts (1.1V internal ref.)

//------ formating the integer temp to a 4 character string ---------  
  tempVal[0]= '0'+(temp/100);
  tempVal[1]= '0'+(temp%100/10);
//  tempVal[2]= '.';   //decimal point already there.
  tempVal[3]= '0'+(temp%10);

  updateValue();
  if (fails > MAXFAILS) initESP();   //Reset and init ESP8266 after some fails.

}   // END of loop.

/*-----------------------------------------------------------------------------
Function updateValue() 
-----------------------------------------------------------------------------*/
void updateValue(){
  ESPSerial.print(conn_MSG);        //Open TCP connection with ThingSpeak.
  if(waitChar('K',10000)){          //Wait for 'K' of "OK".
    delay(250);                     //Delay to receive the message "Linked"
    ESPSerial.print(send_MSG);      //Send message AT+CIPSEND= and size.
    if(waitChar('>',10000)){        //Wait for '>'.
      ESPSerial.print(upda_MSG);    //Update Field value.
//      tempVal= "13.4";
      ESPSerial.print(tempVal);
//      ESPSerial.print("20.7");    // test value
      ESPSerial.print("\r\n");      //to replace println (less code).
      fails=0;                      // clear failure counter.
      return;                       // Unlink automatically....
    }
  }
  fails++;
  ESPSerial.print(clos_MSG);       //Close the TCP connection with ThingSpeak.  
}

/*-----------------------------------------------------------------------------
Function waitChar() 
-----------------------------------------------------------------------------*/
bool waitChar(char Wchar, int duration){
  for(i=duration;i>0;i--){
    delay(1);
    if(ESPSerial.read()== Wchar)return true;
  }
  return false;
}

/*-----------------------------------------------------------------------------
Function initESP() 
-----------------------------------------------------------------------------*/
void initESP(){
  while(1){
    if (fails > MAXFAILS){           //------Hardware reset for ESP8266.
      digitalWrite(HRESET,LOW);
      delay(100);
      digitalWrite(HRESET,HIGH);
      delay(5000);
      fails=0;
    }

    ESPSerial.print("AT\r\n");       //"\r\n" to replace println  (less code)
    delay(1000);
    if(waitChar('K',1000)){          //Wait for 'K' of "OK".
      ESPSerial.print(mode_MSG);     //Set Station mode.
      delay(250); 
      ESPSerial.print(join_MSG);     //Set name and password of the AP.
      if(waitChar('K',10000))return; //Wait for 'K' of "OK" to exit setup
    }
    fails++;
  }

}

