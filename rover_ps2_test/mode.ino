void all_stop()
        {
          digitalWrite(9, HIGH);  
          digitalWrite(8, HIGH);  
        
        }



void vor()
        {
          //Motor A forward @ full speed
          digitalWrite(12, HIGH);  //Establishes backward direction of Channel A
          digitalWrite(9, LOW);   //Disengage the Brake for Channel A
          analogWrite(3, 255);    //Spins the motor on Channel A at half speed

          //Motor B forward @ full speed
          digitalWrite(13, LOW); //Establishes forward direction of Channel B
          digitalWrite(8, LOW);   //Disengage the Brake for Channel B
          analogWrite(11, 255);   //Spins the motor on Channel B at full spee

        }
        
void vor_slow()
        {
          //Motor A forward @ full speed
          digitalWrite(12, HIGH);  //Establishes backward direction of Channel A
          digitalWrite(9, LOW);   //Disengage the Brake for Channel A
          analogWrite(3, 150);    //Spins the motor on Channel A at half speed

          //Motor B forward @ full speed
          digitalWrite(13, LOW); //Establishes forward direction of Channel B
          digitalWrite(8, LOW);   //Disengage the Brake for Channel B
          analogWrite(11, 150);   //Spins the motor on Channel B at full spee

        }
        
        
void back()
        {
            //Motor A forward @ full speed
          digitalWrite(12, LOW); //Establishes forward direction of Channel A
          digitalWrite(9, LOW);   //Disengage the Brake for Channel A
          analogWrite(3, 255);   //Spins the motor on Channel A at full speed

          //Motor B backward @ half speed
          digitalWrite(13, HIGH);  //Establishes backward direction of Channel B
          digitalWrite(8, LOW);   //Disengage the Brake for Channel B
          analogWrite(11, 255);    //Spins the motor on Channel B at half speed
          
        }
        
void back_slow()
        {
            //Motor A forward @ full speed
          digitalWrite(12, LOW); //Establishes forward direction of Channel A
          digitalWrite(9, LOW);   //Disengage the Brake for Channel A
          analogWrite(3, 150);   //Spins the motor on Channel A at full speed

          //Motor B backward @ half speed
          digitalWrite(13, HIGH);  //Establishes backward direction of Channel B
          digitalWrite(8, LOW);   //Disengage the Brake for Channel B
          analogWrite(11, 150);    //Spins the motor on Channel B at half speed
          
        }
        
void rechts ()
        {
           //Motor A forward @ full speed
          digitalWrite(12, HIGH);  //Establishes backward direction of Channel A
          digitalWrite(9, LOW);   //Disengage the Brake for Channel A
          analogWrite(3, 150);    //Spins the motor on Channel A at half speed

          //Motor B forward @ full speed
          digitalWrite(13, HIGH); //Establishes forward direction of Channel B
          digitalWrite(8, LOW);   //Disengage the Brake for Channel B
          analogWrite(11, 150);   //Spins the motor on Channel B at full speed
        }
        
void links ()
        {
           //Motor A forward @ full speed
          digitalWrite(12, LOW);  //Establishes backward direction of Channel A
          digitalWrite(9, LOW);   //Disengage the Brake for Channel A
          analogWrite(3, 150);    //Spins the motor on Channel A at half speed

          //Motor B forward @ full speed
          digitalWrite(13, LOW); //Establishes forward direction of Channel B
          digitalWrite(8, LOW);   //Disengage the Brake for Channel B
          analogWrite(11, 150);   //Spins the motor on Channel B at full speed
        }
        
void rechts_voll ()
        {
           //Motor A forward @ full speed
          digitalWrite(12, HIGH);  //Establishes backward direction of Channel A
          digitalWrite(9, LOW);   //Disengage the Brake for Channel A
          analogWrite(3, 255);    //Spins the motor on Channel A at half speed

          //Motor B forward @ full speed
          digitalWrite(13, HIGH); //Establishes forward direction of Channel B
          digitalWrite(8, LOW);   //Disengage the Brake for Channel B
          analogWrite(11, 255);   //Spins the motor on Channel B at full speed
        }

void links_voll ()
        {
           //Motor A forward @ full speed
          digitalWrite(12, LOW);  //Establishes backward direction of Channel A
          digitalWrite(9, LOW);   //Disengage the Brake for Channel A
          analogWrite(3, 255);    //Spins the motor on Channel A at half speed

          //Motor B forward @ full speed
          digitalWrite(13, LOW); //Establishes forward direction of Channel B
          digitalWrite(8, LOW);   //Disengage the Brake for Channel B
          analogWrite(11, 255);   //Spins the motor on Channel B at full speed
        }

