
int led1 = 1;
int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;
int led6 = 6;


void setup() {                
 
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);  
}


void loop() {
  
  
  digitalWrite(led1, HIGH);   
  delay(1000);              
  digitalWrite(led1, LOW);    
  delay(1000); 
  digitalWrite(led2, HIGH);   
  delay(1000);              
  digitalWrite(led2, LOW);    
  delay(1000); 
  digitalWrite(led3, HIGH);   
  delay(1000);              
  digitalWrite(led3, LOW);    
  delay(1000); 
  digitalWrite(led4, HIGH);   
  delay(1000);              
  digitalWrite(led4, LOW);    
  delay(1000); 
  digitalWrite(led5, HIGH);   
  delay(1000);              
  digitalWrite(led5, LOW);    
  delay(1000); 
  digitalWrite(led6, HIGH);   
  delay(1000);              
  digitalWrite(led6, LOW);    
  delay(1000);   
  
  
  digitalWrite(led1, HIGH);    
  delay(1000); 
  digitalWrite(led2, HIGH);   
  delay(1000);              
  digitalWrite(led3, HIGH);   
  delay(1000);              
  digitalWrite(led4, HIGH);   
  delay(1000);              
  digitalWrite(led5, HIGH);   
  delay(1000);               
  digitalWrite(led6, HIGH);   
  delay(1000);              

   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);  
   digitalWrite(led3, LOW); 
   digitalWrite(led4, LOW); 
   digitalWrite(led5, LOW); 
   digitalWrite(led6, LOW); 
   delay(1000);
}
