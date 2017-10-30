/*

Bluetoothmodul auf 9600baud einstellen
TX mit TX am arduino verbinden und RX mit RX am arduino


*/


#include <Servo.h> // Enables the Servo library
#include <Wire.h> 
#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
  

  LiquidCrystal_I2C lcd(0x27,20,4);
  
  
 Servo PingServo;
    int minSafeDist = 40 ; // Minimum distance for ping sensor to know when to turn
    int minSonarDist = 500;
    int maxcurrent = 95 ;
    int pingPin = A2; // Ping sensor is connected to port A2
    int centerDist, leftDist, rightDist, backDist; // Define variables center, left, right and back distance
    long duration, cm; // Define variables for Ping sensor
char dataIn = 'S';        //Character/Data coming from the phone.
int pinForwardBack = 13;     //Pin that controls the car's Forward-Back motor.
int pinLeftRight = 12;       //Pin that controls the car's Left-Right motor.
int pinBrakeLeftRight = 9;  //Pin that enables/disables Left-Right motor.
int pinBrakeForwardBack = 8;  //Pin that enables/disables Forward-Back motor.
int pinLeftRightSpeed = 3;    //Pin that sets the speed for the Left-Right motor.
int pinForwardBackSpeed = 11;  //Pin that sets the speed for the Forward-Back motor.
//#define RxD 15 // This is the pin that the Bluetooth (BT_TX) will transmit to the Arduino (RxD)
//#define TxD 14 // This is the pin that the Bluetooth (BT_RX) will receive from the Arduino (TxD)
 


int pinfrontLights = 4;    //Pin that activates the Front lights.
int pinbackLights = 7;    //Pin that activates the Back lights.
char determinant;         //Used in the check function, stores the character received from the phone.
char det;                 //Used in the loop function, stores the character received from the phone.
int velocity = 0;    //Stores the speed based on the character sent by the phone.

void setup()
{       
//*************NOTE: If using Bluetooth Mate Silver use 115200 btu
//                   If using MDFLY Bluetooth Module use 9600 btu
long duration, cm;
Serial.begin(9600);
PingServo.attach(10); // Servo is attached to pin 10 in the motor shield
PingSevo.write(90); // Center the Ping sensor (puts it at 90 degrees)
lcd.init(); 
lcd.backlight();
pinMode(pinForwardBack, OUTPUT);
pinMode(pinLeftRight, OUTPUT);
pinMode(pinBrakeLeftRight, OUTPUT);
pinMode(pinBrakeForwardBack, OUTPUT);
pinMode(pinLeftRightSpeed , OUTPUT);
pinMode(pinForwardBackSpeed , OUTPUT);
pinMode(pinfrontLights , OUTPUT);
pinMode(pinbackLights , OUTPUT);
//pinMode(RxD, INPUT); // Setup the Arduino to receive INPUT from the bluetooth shield on Digital Pin 6
//pinMode(TxD, OUTPUT); // Setup the Arduino to send data (OUTPUT) to the bluetooth shield on Digital Pin 7
//Setup Channel A
    pinMode(12, OUTPUT); //Initiates Motor Channel A pin
    pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
    pinMode(13, OUTPUT); //Initiates Motor Channel B pin
    pinMode(8, OUTPUT);  //Initiates Brake Channel B pin


}

void loop()
{
    det = check();
      while (det == 'F')   //if incoming data is a F, move forward
      {     
          
           Serial.println("F");
            lcd.setCursor(6, 0);
            lcd.print("Vor    ");
            lcd.setCursor(6, 0);
            lcd.print("       ");
             // Channal A
           digitalWrite(12, HIGH);  //Laufrichtung
           digitalWrite(9, LOW);   //Bremse aus
           analogWrite(3, velocity);    //SPEED
           // Channal B
           digitalWrite(13, LOW); 
           digitalWrite(8, LOW);   
           analogWrite(11, velocity);
           
          det = check();   
   
          
      }  
      while (det == 'B')   //if incoming data is a B, move back
      {    
          
          digitalWrite(pinBrakeForwardBack, LOW);
          digitalWrite(12, LOW); 
          digitalWrite(9, LOW);   
          analogWrite(3, velocity);   
      
          digitalWrite(13, HIGH);  
          digitalWrite(8, LOW);   
          analogWrite(11, velocity);   
              
          det = check();          
      }

      while (det == 'L')   //if incoming data is a L, move wheels left
      {     
          
           Serial.println("L");
           lcd.setCursor(6, 0);
           lcd.print("Links ");
           lcd.setCursor(6, 0);
           lcd.print("       ");
           digitalWrite(12, HIGH); 
           digitalWrite(9, LOW);   
           analogWrite(3, 150);   
   
           digitalWrite(13, HIGH); 
           digitalWrite(8, LOW);   
           analogWrite(11, 150);
                 
          det = check();          
      }  
      while (det == 'R')   //if incoming data is a R, move wheels right
      {    
          
           Serial.println("R");
           lcd.setCursor(6, 0);
           lcd.print("Links  ");
           lcd.setCursor(6, 0);
           lcd.print("       ");
           digitalWrite(12, LOW); 
           digitalWrite(9, LOW);   
           analogWrite(3, 150);   
   
           digitalWrite(13,LOW);
           digitalWrite(8, LOW);   
           analogWrite(11, 150);   
                  
          det = check();          
      }
     
      while (det == 'I')   //if incoming data is a I, turn right forward
      {     
          digitalWrite(pinLeftRight, LOW);
           Serial.println("I");
           lcd.setCursor(6, 0);
           lcd.print("R-Vor  ");
           lcd.setCursor(6, 0);
           lcd.print("       ");
          digitalWrite(pinForwardBack, LOW);          
          digitalWrite(pinBrakeLeftRight, LOW);
          digitalWrite(pinBrakeForwardBack, LOW);  
          analogWrite(pinForwardBackSpeed,velocity);
          analogWrite(pinLeftRightSpeed,255);                  
          det = check();          
      }  
      while (det == 'J')   //if incoming data is a J, turn right back
      {      
          digitalWrite(pinLeftRight, LOW);
           Serial.println("J");
           lcd.setCursor(6, 0);
           lcd.print("R-Back ");
           lcd.setCursor(6, 0);
           lcd.print("       ");
          digitalWrite(pinForwardBack, HIGH);         
          digitalWrite(pinBrakeLeftRight, LOW);
          digitalWrite(pinBrakeForwardBack, LOW);
          analogWrite(pinForwardBackSpeed,velocity);
          analogWrite(pinLeftRightSpeed,255);          
          det = check();          
      }          
      while (det == 'G')   //if incoming data is a G, turn left forward
      {
          digitalWrite(pinLeftRight, HIGH); 
          Serial.println("G");    
          lcd.setCursor(6, 0);
           lcd.print("L-Vor  ");
           lcd.setCursor(6, 0);
           lcd.print("       ");  
          digitalWrite(pinForwardBack, LOW);
          digitalWrite(pinBrakeLeftRight, LOW);
          digitalWrite(pinBrakeForwardBack, LOW);
          analogWrite(pinForwardBackSpeed,velocity);
          analogWrite(pinLeftRightSpeed,255);          
          det = check();          
      }    
      while (det == 'H')   //if incoming data is a H, turn left back
      {
          digitalWrite(pinLeftRight, HIGH);
           Serial.println("H");
            lcd.setCursor(6, 0);
           lcd.print("L-Back ");
           lcd.setCursor(6, 0);
           lcd.print("       ");
          digitalWrite(pinForwardBack, HIGH);
          digitalWrite(pinBrakeLeftRight, LOW);
          digitalWrite(pinBrakeForwardBack, LOW);
          analogWrite(pinForwardBackSpeed,velocity);
          analogWrite(pinLeftRightSpeed,255);          
          det = check();                                              
      }   
      while (det == 'S')   //if incoming data is a S, stop
      {
          digitalWrite(pinForwardBack, LOW);
          lcd.setCursor(6, 0);
          lcd.print("Stop   ");
          lcd.setCursor(6, 0);
          lcd.print("        ");
          Serial.println("S");
          digitalWrite(pinLeftRight, LOW);
          analogWrite(pinForwardBackSpeed,0);
          analogWrite(pinLeftRightSpeed,0);          
          det = check();
      }
      while (det == 'U')   //if incoming data is a U, turn ON front lights
      {
          digitalWrite(pinfrontLights, HIGH); 
          lcd.setCursor(0, 1);
          lcd.print("");          
          det = check();
      }
      while (det == 'u')   //if incoming data is a u, turn OFF front lights
      {
          digitalWrite(pinfrontLights, LOW);   
          lcd.setCursor(0, 1);
          lcd.print("");       
          det = check();
      }
      while (det == 'W')   //if incoming data is a W, turn ON back lights
      {
          digitalWrite(pinbackLights, HIGH);  
          lcd.setCursor(0, 1);
          lcd.print("");         
          det = check();
      }
      while (det == 'w')   //if incoming data is a w, turn OFF back lights
      {
          digitalWrite(pinbackLights, LOW);
          lcd.setCursor(0, 1);
          lcd.print("");
          det = check();
      }
      while (det == 'X')   //if incoming data is a W, turn ON back lights
      {
          digitalWrite(pinbackLights, HIGH);  
          lcd.setCursor(0, 1);
          lcd.print("Autonom");        
          det = check();
          
   
   delay(300);  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    int channelA = analogRead(A0);
    int channelB = analogRead(A1);
    int irDistHinten = analogRead(A3);   //Sharp IR Hinten pin A3
    
    
    Serial.println("Current A " + String(channelA));
    Serial.println("Current B " + String(channelB));
    Serial.println("IR Dist " + String(irDistHinten)); //IR Hinten
    
    LookAhead();
  
    Serial.println(" cm" + String(cm));
   
   
   
    
    if(cm >= minSafeDist) /* If the inches in front of an object is greater than or equal to the minimum safe distance (11 inches), react*/
  {
    AllVor(); // All wheels forward
    delay(110); // Wait 0.11 seconds
  }
     else
  {
    AllStop(); // Stop all motors
    LookAround(); // Check your surroundings for best route
    if(rightDist > leftDist) // If the right distance is greater than the left distance , turn right
   {
   
    AllBackSlow();
    turnLeft();
   }
     else if (leftDist > rightDist) // If the left distance is greater than the right distance , turn left
   {
     AllBackSlow();
    turnRight();
   }
     else if (leftDist&&rightDist<minSafeDist)  // If the left and right distance is smaller than the min safe distance (11 inch) go bac
   {
    AllVorSlow();
      if (irDistHinten > minSonarDist)
  
   {
     GoBack();
   }
  }
 }
      if ((channelA < maxcurrent)&&(channelB < maxcurrent))
    
    {
      AllVor();
    }
      else
  
   {
       AllBackAus();
   }
   
   
   
  
  
 }

unsigned long ping() 
  {
    pinMode(pingPin, OUTPUT); // Make the Pingpin to output
    digitalWrite(pingPin, LOW); //Send a low pulse
    delayMicroseconds(2); // wait for two microseconds
    digitalWrite(pingPin, HIGH); // Send a high pulse
    delayMicroseconds(5); // wait for 5 micro seconds
    digitalWrite(pingPin, LOW); // send a low pulse
    pinMode(pingPin,INPUT); // switch the Pingpin to input
    duration = pulseIn(pingPin, HIGH); //listen for echo

/*Convert micro seconds to Inches
-------------------------------------*/

    
    cm = microsecondsToCentimeters(duration);
  
  }
    long microsecondsToCentimeters(long microseconds) // converts time to a distance
  {
    return microseconds / 29 / 2;
  }

  void LookAhead() 
    {
      PingServo.write(90);// angle to look forward
      delay(175); // wait 0.175 seconds
      ping();
    }

  void LookAround()
    {
      PingServo.write(180); // 180° angle
      delay(320); // wait 0.32 seconds
      ping();
      rightDist = cm; //get the right distance
      PingServo.write(0); // look to the other side
      delay(620); // wait 0.62 seconds
      ping();
      leftDist = cm; // get the left distance
      PingServo.write(90); // 90° angle
      delay(275); // wait 0.275 seconds
    
   
    




      }
      while (det == 'x')   //if incoming data is a w, turn OFF back lights
      {
          digitalWrite(pinbackLights, LOW);
          lcd.setCursor(0, 1);
          lcd.print("Manual   ");
          det = check();
      }
}

int check()
{
  if (Serial.available() > 0)    //Check for data on the serial lines.
  {   
    dataIn = Serial.read();  //Get the character sent by the phone and store it in 'dataIn'.
        if (dataIn == 'F')
        {     
          determinant = 'F';
        }  
        else if (dataIn == 'B')
        {
          determinant = 'B';
        }
        else if (dataIn == 'L')  
        {
          determinant = 'L';
        }
        else if (dataIn == 'R')  
        {
          determinant = 'R';
        }
        else if (dataIn == 'I')  
        {
          determinant = 'I';
        }  
        else if (dataIn == 'J')  
        {  
          determinant = 'J';
        }          
        else if (dataIn == 'G')
        {
          determinant = 'G';
        }    
        else if (dataIn == 'H')  
        {
          determinant = 'H';
        }   
        else if (dataIn == 'S')
        {
          determinant = 'S';
        }
        else if (dataIn == '0')
        {
          velocity = 0;    //"velocity" does not need to be returned.
           lcd.setCursor(3, 0);
           lcd.print("Speed ");
           lcd.setCursor(3, 0);
           lcd.print("       ");
           lcd.setCursor(3, 6);
           lcd.print("0 ");
           lcd.setCursor(3, 6);
           lcd.print("       ");
        }
        else if (dataIn == '1')
        {
          velocity = 25;
        }
        else if (dataIn == '2')
        {
          velocity = 50;
        }
        else if (dataIn == '3')
        {
          velocity = 75;
        }
        else if (dataIn == '4')
        {
          velocity = 100;
        }
        else if (dataIn == '5')
        {
          velocity = 125;
        }
        else if (dataIn == '6')
        {
          velocity = 150;
        }
        else if (dataIn == '7')
        {
          velocity = 175;
        }
        else if (dataIn == '8')
        {
          velocity = 200;
        }
        else if (dataIn == '9')
        {
          velocity = 225;
        }
        else if (dataIn == 'q')
        {
          velocity = 255;
        }
        else if (dataIn == 'U')
        {
          determinant = 'U';
        }
        else if (dataIn == 'u')
        {
          determinant = 'u';
        }
        else if (dataIn == 'W')
        {
          determinant = 'W';
        }
        else if (dataIn == 'w')
        {
          determinant = 'w';
        }
        else if (dataIn == 'X')
        {
          determinant = 'X';
        }
        else if (dataIn == 'x')
        {
          determinant = 'x';
        }
  }
return determinant;
}
