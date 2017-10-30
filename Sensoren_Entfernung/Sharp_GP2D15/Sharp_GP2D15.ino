int LED =13;

void setup()
{
  pinMode(LED, OUTPUT);


  Serial.begin(9600);
}

void loop()


{
   int distance = analogRead(3);
   Serial.println(distance);
  delay(500);
   
   if ( distance > 1000 )
   {
      digitalWrite(LED,LOW); 
   } 
   else
   {
     digitalWrite(LED,HIGH); 
   } 
} 


