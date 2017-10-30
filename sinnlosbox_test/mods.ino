void handrausmodus(){
 
   {
     pos = 0; pos = 140;      // TÜr Öffnen                                
     tuerServo.write(pos);
     digitalWrite(ledred, LOW);
   } 
     delay(50); 
 
   for(pos = 150; pos>=80; pos -= 5)   
  {                                  
    handServo.write(pos);               
    delay(15);                       
  } 
    digitalWrite(ledred, HIGH);
    digitalWrite(ledgrn, LOW);
    for(pos = 80; pos<100; pos+=5)     
  {                                
    handServo.write(pos);              
    delay(15);
  } 
    digitalWrite(ledgrn, HIGH);
    digitalWrite(ledblu, LOW);
    for(pos = 100; pos>=60; pos -= 5)   
  {                                  
    handServo.write(pos);               
    delay(15);                       
  } 
    digitalWrite(ledblu, HIGH);
    digitalWrite(ledred, LOW);
    for(pos = 60; pos<100; pos+=5)     
  {                                
    handServo.write(pos);              
    delay(15);
  } 
    digitalWrite(ledred, HIGH);
    digitalWrite(ledgrn, LOW);
    for(pos = 100; pos>=45; pos -= 5) 
  {                                  
    handServo.write(pos);               
    delay(15);                       
  }  
    for(pos = 0; pos<150; pos+=10)     
  {                                
    handServo.write(pos);               
    delay(15);                       
  }     
    handServo.write(pos);               
    delay(15);   
   
   delay(15); 
   {
   pos = 0; pos = 60;      // Tür Schliessen                         
   tuerServo.write(pos);
   digitalWrite(ledgrn, HIGH);
   
   }   
  }







void handrausmodus1(){
 
   {
     pos = 0; pos = 140;      // TÜr Öffnen                                
     tuerServo.write(pos);
   } 
     delay(50); 
   {  
     pos = 0; pos = 60;      // Hand Schalter schalten                                
     handServo.write(pos);
   } 
     delay(600); 
   {
     pos = 0; pos = 90;      // Hand Schalter Schalten zurück                       
     handServo.write(pos);               
   }
     delay(600);  
   {  
     pos = 0; pos = 60;      // Hand Schalter schalten                                
     handServo.write(pos);
   } 
     delay(600);
   {
     pos = 0; pos = 90;      // Hand Schalter Schalten zurück                       
     handServo.write(pos);               
   }
     delay(600);  
   {  
     pos = 0; pos = 60;      // Hand Schalter schalten                                
     handServo.write(pos);
   } 
     delay(600);  
   {  
     pos = 0; pos = 30;      // Hand Schalter schalten                                
     handServo.write(pos);
   } 
     delay(600);
   {
     pos = 0; pos = 160;      // Hand Schalter Schalten zurück                       
     handServo.write(pos);               
   }
     delay(600); 
   {
     pos = 0; pos = 60;      // Tür Schliessen                         
     tuerServo.write(pos);              
   }   
  }
 
 
  

 
 
  void handreinmodus(){
 
   {
   pos = 0; pos = 160;      // Hand Schalter Schalten zurück                       
   handServo.write(pos);               
   }  
   delay(200); 
   {
   pos = 0; pos = 60;      // Tür Schliessen                         
   tuerServo.write(pos);              
   }     
  }
 
 
  
 
 
 

