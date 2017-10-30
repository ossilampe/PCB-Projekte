const int sensor_rechts = 14;
const int sensor_mitte = 20;
const int sensor_links = 16;
int sensor_rechts_State = 0;
int sensor_mitte_State = 0;
int sensor_links_State = 0;


void setup() {

  
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
  
            sensor_rechts_State = digitalRead(sensor_rechts);
            sensor_mitte_State = digitalRead(sensor_mitte);
            sensor_links_State = digitalRead(sensor_links);
    
if (sensor_mitte_State == LOW)

{ 
all_stop();  
back_slow();      
delay(1000); 
}   

 else if (sensor_links_State == LOW)
 {
    all_stop();
    rechts();
    delay(500);
  }
  
    
  else if (sensor_rechts_State == LOW)
  {
     all_stop();
     links();
     delay(500);
   }
           
   

else
{
             
  vor_slow();
   
}                         
}


   
   
   
   
   
   
   
   
   
   
   
     
   
          
          
          
          
 
