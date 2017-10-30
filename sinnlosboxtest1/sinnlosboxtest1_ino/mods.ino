void handrausmodus(){
 
   {
     pos = 0; pos = 140;      // TÜr Öffnen                                
     tuerServo.write(pos);
     digitalWrite(ledred, LOW);
   } 
     delay(50); 
   {  
   pos = 0; pos = 10;      // Hand Schalter schalten                               
   handServo.write(pos);
   }  
   delay(400);
   {
   pos = 0; pos = 160;      // Hand Schalter Schalten zurück                       
   handServo.write(pos);               
   }  
   delay(200); 
   {
   pos = 0; pos = 60;      // Tür Schliessen                         
   tuerServo.write(pos);
   digitalWrite(ledred, HIGH);   
   }   
  }
 
 
  void handrausmodus1(){
    delay(5000);
   {
     pos = 0; pos = 140;      // TÜr Öffnen                                
     tuerServo.write(pos);
     digitalWrite(ledgrn, LOW);
   } 
     delay(50); 
   {  
   pos = 0; pos = 10;      // Hand Schalter schalten                               
   handServo.write(pos);
   }  
   delay(400);
   {
   pos = 0; pos = 160;      // Hand Schalter Schalten zurück                       
   handServo.write(pos);               
   }  
   delay(200); 
   {
   pos = 0; pos = 60;      // Tür Schliessen                         
   tuerServo.write(pos); 
   digitalWrite(ledgrn, HIGH);  
   }   
  }
 
  void handrausmodusslow(){
 
   {
     digitalWrite(ledred, LOW);
     digitalWrite(ledgrn, LOW);
     pos = 0; pos = 140;      // TÜr Öffnen                                
     tuerServo.write(pos);
   } 
     delay(50); 
 
   for(pos = 150; pos>=0; pos -= 3)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    handServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 0; pos<150; pos+=1)     // goes from 180 degrees to 0 degrees 
  {                                
    handServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
   delay(200); 
   {
   pos = 0; pos = 60;      // Tür Schliessen                         
   tuerServo.write(pos);
   digitalWrite(ledred, HIGH);
   digitalWrite(ledgrn, HIGH);   
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
 
 
  void fanwinkimodus(){
 
  {
     digitalWrite(ledblu, LOW);
     pos = 0; pos = 140;      // TÜr Öffnen                                
     tuerServo.write(pos);
   } 
   {
     pos = 0; pos = 20;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 20; pos = 70;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 70; pos = 20;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 20; pos = 70;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 20; pos = 70;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 70; pos = 20;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 20; pos = 70;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 20; pos = 70;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 70; pos = 20;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 20; pos = 70;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
  {  
   pos = 0; pos = 10;      // Hand Schalter schalten                                
   handServo.write(pos);
   } 
   delay(600);
   {
   pos = 0; pos = 160;      // Hand Schalter Schalten zurück                       
   handServo.write(pos);               
   }
   delay(200);
   {
   pos = 0; pos = 145;      // Fahne zurück                       
   fanServo.write(pos);               
   }  
   delay(200);
   {
   pos = 0; pos = 60;      // Tür Schliessen                         
   tuerServo.write(pos);              
   } 
   {
   pos = 0; pos = 160;      // Hand Schalter Schalten zurück                       
   handServo.write(pos);               
   }
   delay(200);
   {
   pos = 0; pos = 145;      // Fahne zurück                       
   fanServo.write(pos);               
   }  
   delay(200);
   {
   pos = 0; pos = 60;      // Tür Schliessen                         
   tuerServo.write(pos);
   digitalWrite(ledblu, HIGH);   
   }     
  }
 
   void fanwinkimodus1(){
 
  {
     digitalWrite(ledblu, LOW);
     pos = 0; pos = 140;      // TÜr Öffnen                                
     tuerServo.write(pos);
   } 
   {
     pos = 0; pos = 20;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 20; pos = 70;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 70; pos = 20;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 20; pos = 70;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 20; pos = 70;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 70; pos = 20;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 20; pos = 70;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 20; pos = 70;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 70; pos = 20;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
   {
     pos = 20; pos = 70;        //Fahne
     fanServo.write(pos);
   }
   delay(200);
 
   {
   pos = 0; pos = 145;      // Fahne zurück                       
   fanServo.write(pos);               
   }  
   delay(200);
   {
   pos = 0; pos = 60;      // Tür Schliessen                         
   tuerServo.write(pos);              
   } 
   {
   pos = 0; pos = 160;      // Hand Schalter Schalten zurück                       
   handServo.write(pos);               
   }
   delay(200);
   {
   pos = 0; pos = 145;      // Fahne zurück                       
   fanServo.write(pos);               
   }  
   delay(200);
   {
   pos = 0; pos = 60;      // Tür Schliessen                         
   tuerServo.write(pos);
   digitalWrite(ledblu, HIGH);
      
   } 
   delay(500);
   {
   digitalWrite(ledred, LOW);
   pos = 0; pos = 140;      // TÜr Öffnen                                
   tuerServo.write(pos);
   }
   {  
   pos = 0; pos = 10;      // Hand Schalter schalten                                
   handServo.write(pos);
   } 
   delay(400);
   {
   pos = 0; pos = 160;      // Hand Schalter Schalten zurück                       
   handServo.write(pos);               
   }
   delay(200);
   {
   pos = 0; pos = 60;      // Tür Schliessen                         
   tuerServo.write(pos);
   digitalWrite(ledred, HIGH);  
   } 
 
  }
 
  void tuermodus(){
 
     
    digitalWrite(ledgrn, LOW);
    for(pos = 60; pos<=90; pos+=3)     // Tuer offen 20% 
  {                                
    tuerServo.write(pos);              
    delay(50);                       
  } 
 delay(800); 
    for(pos = 90; pos<=110; pos+=1)    // Tuer offen 40%
    digitalWrite(ledred, LOW);
  {                                
    tuerServo.write(pos);              
    delay(50);                       
  }  
  delay(300);
  for(pos = 110; pos<=130; pos+=3)     // Tuer offen 60%
  digitalWrite(ledblu, LOW);
  {                                
    tuerServo.write(pos);               
    delay(50);                        
  } 
 
  for(pos = 130; pos > 60; pos -= 5)  // Tuer Schliessen
  digitalWrite(ledred, HIGH);
  digitalWrite(ledgrn, HIGH);
  digitalWrite(ledblu, HIGH);
  {                                  
    tuerServo.write(pos);              
    delay(100);  
  }
  for(pos = 60; pos<=90; pos+=3)  // Tuer offen 20% 
  digitalWrite(ledgrn, LOW);
  {                                
    tuerServo.write(pos);              
    delay(50);                       
  } 
 delay(800); 
    for(pos = 90; pos<=130; pos+=1)     // Tuer offen 40%
    digitalWrite(ledred, LOW);
  {                                
    tuerServo.write(pos);              
    delay(50);                       
  }  
    digitalWrite(ledred, HIGH);
    digitalWrite(ledgrn, HIGH);
    digitalWrite(ledblu, LOW);
    tuerServo.write(pos);               
    delay(50);                        
 
  {  
   
   pos = 0; pos = 10;      // Hand Schalter schalten                                
   handServo.write(pos);
   } 
   delay(400);
   {
   pos = 0; pos = 160;      // Hand Schalter Schalten zurück                       
   handServo.write(pos);               
   }
   delay(200);
 
  for(pos = 130; pos > 60; pos -= 20)  // Tuer Schliessen
  {                                  
    tuerServo.write(pos);              
    delay(50);
   digitalWrite(ledred, HIGH);
  digitalWrite(ledgrn, HIGH);
  digitalWrite(ledblu, HIGH);    
 
  }
  }
 
   void tuermodus1(){
 
    
    digitalWrite(ledred, LOW); 
    for(pos = 60; pos<=90; pos+=3)     // Tuer offen 20% 
  {                                
    tuerServo.write(pos);              
    delay(50);                       
  } 
 delay(800); 
    for(pos = 90; pos<=110; pos+=1)     // Tuer offen 40%
  {                                
    tuerServo.write(pos);              
    delay(50);                       
  }  
  delay(300);
  for(pos = 110; pos<=130; pos+=3)     // Tuer offen 60%
  {                                
    tuerServo.write(pos);               
    delay(50);                        
  } 
 
 
  {  
   digitalWrite(ledred, HIGH);
   digitalWrite(ledgrn, LOW); 
   pos = 0; pos = 10;      // Hand Schalter schalten                                
   handServo.write(pos);
   } 
   delay(400);
   {
   pos = 0; pos = 160;      // Hand Schalter Schalten zurück                       
   handServo.write(pos);               
   }
   delay(200);
  digitalWrite(ledgrn, HIGH);
  digitalWrite(ledblu, LOW);
  for(pos = 130; pos > 60; pos -= 20)  // Tuer Schliessen
  {                                  
    tuerServo.write(pos);              
    delay(50); 

  digitalWrite(ledblu, HIGH);   
 
  }
  }
 
 
 
 

