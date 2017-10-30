#include <dht.h>
#include <VirtualWire.h>

dht DHT;

#define DHT11PIN 3

void setup()
{
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(8);
  vw_setup(2000);
  Serial.begin(9600);
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  //Serial.println(DHT11LIB_VERSION);
  Serial.println();
}

void loop()
{

  int chk = DHT.read(DHT11PIN);
  int temp = DHT.temperature;
  char *temperatur = "0";
  switch (temp)
  {
    case 10:
      temperatur = "10";
      break;
    case 11:
      temperatur = "11";
      break;
    case 12:
      temperatur = "12";
      break;
    case 13:
      temperatur = "13";
      break;
    case 14:
      temperatur = "14";
      break;
    case 15:
      temperatur = "15";
      break;
    case 16:
      temperatur = "16";
      break;
    case 17:
      temperatur = "17";
      break;
    case 18:
      temperatur = "18";
      break;
    case 19:
      temperatur = "19";
      break;
    case 20:
      temperatur = "20";
      break;
    case 21:
      temperatur = "21";
      break;
    case 22:
      temperatur = "22";
      break;
    case 23:
      temperatur = "23";
      break;
    case 24:
      temperatur = "24";
      break;  
    case 25:
      temperatur = "25";
      break;
    case 26:
      temperatur = "26";
      break;
    case 27:
      temperatur = "27";
      break;
    case 28:
      temperatur = "28";
      break;
  }  
  Serial.println(temperatur);
  vw_send((uint8_t*)temperatur, 2);
  vw_wait_tx();
  delay(200);
}
