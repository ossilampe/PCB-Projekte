const int sensor_rechts = 14;
const int sensor_mitte = 20;
const int sensor_links = 16;
const int buttonDown = 15;
const int buttonUp = 17;
const int buttonRight = 18;
const int buttonLeft = 19; 
int sensor_rechts_State = 0;
int sensor_mitte_State = 0;
int sensor_links_State = 0;
int buttonStateDown = 0;
int buttonStateUp = 0;
int buttonStateRight = 0;
int buttonStateLeft = 0;


void setup() {

          pinMode(buttonDown, INPUT);
          pinMode(buttonUp, INPUT);
          pinMode(buttonRight, INPUT);
          pinMode(buttonLeft, INPUT);
          pinMode(sensor_rechts, INPUT);
          pinMode(sensor_mitte, INPUT);
          pinMode(sensor_links, INPUT);
          //Setup Channel A
          pinMode(12, OUTPUT); //Initiates Motor Channel A pin
          pinMode(9, OUTPUT); //Initiates Brake Channel A pin

          //Setup Channel B
          pinMode(13, OUTPUT); //Initiates Motor Channel A pin
          pinMode(8, OUTPUT);  //Initiates Brake Channel A pin

        }
        
        
void loop(){
  
        buttonStateDown = digitalRead(buttonDown);
        buttonStateUp = digitalRead(buttonUp);
        buttonStateRight = digitalRead(buttonRight);
        buttonStateLeft = digitalRead(buttonLeft);


if (buttonStateUp == HIGH) {     
        
    vor(); 
  } 
  
if (buttonStateDown == HIGH) {     
       
    back(); 
  } 
  

if (buttonStateRight == HIGH) {     
       
    rechts_voll(); 
  } 
  
if (buttonStateLeft == HIGH) {     
        
    links_voll(); 
  } 
  else {
    delay(50);
    all_stop();
  }

  
}


   
   
   
   
   
   
   
   
   
   
   
     
   
          
          
          
          
 
