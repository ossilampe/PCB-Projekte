


void  sxtest()
{
  

     z = analogRead(0);  
    //down & up 
    if (z>150 && z<350) { alma = alma + 1; delay(150);}     else
    if (z>510 && z<750){ alma = alma - 1; delay(150);}           
    if (alma == 4) {alma = 1;}
    if (alma == 0) {alma = 3;} 
    

    // step
    if (alma == 1)  
    {
    if (z==0) { sw = sw - 1; EEPROM.write(2, sw );}    
    if (z>350 && z<510){sw = sw + 1; EEPROM.write(2, sw );}           
    if (sw > 255) {sw = 255; EEPROM.write(2, sw );}
    if (sw < 1) {sw = 1; EEPROM.write(2, sw );}  
    } 
    
    // delay
    if (alma == 2)  
    {
    if (z==0) { deli = deli - 1; EEPROM.write(3, deli );}    
    if (z>350 && z<510){deli = deli + 1; EEPROM.write(3, deli );}           
    if (deli > 255) {deli= 255; EEPROM.write(3, deli );}
    if (deli < 1) {deli = 1; EEPROM.write(3, deli );}  
    } 
        
    // PWM   // EEPROM write - aktivieren um servo mit Stellung aus EEPROM anzufahren, zusätzlich im x in out  setup entsprechende passage aktivieren
    if (alma == 3)  
    {
    if (z==0) { anna = anna - sw; 
    //EEPROM.write(4, anna/10 );
    }    
    if (z>350 && z<510){anna = anna + sw; 
    //EEPROM.write(4, anna/10 );
    }           
    if (anna > maxpulse) {anna = maxpulse; 
    //EEPROM.write(4, anna/10 );
    }
    if (anna < minpulse) {anna = minpulse; 
    //EEPROM.write(4, anna/10 );
    } 
    } 


// ************************************************
    
   lcd.LCD_write_string(0, 0,"  SERVO TEST  " , MENU_HIGHLIGHT);   

   /*nur zum test anzeigen lassen - start
   itoa(alma, almax, 10);
   lcd.LCD_write_string(0, 1, almax , MENU_NORMAL);
   */  
   
//***    
   //step 
   itoa(sw, swx, 10);
   if   (alma == 1)  {lcd.LCD_write_string(0,   2,">            <" , MENU_HIGHLIGHT); 
                         lcd.LCD_write_string(6, 2,"step      us" , MENU_NORMAL);   
                         lcd.LCD_write_string(42, 2, swx , MENU_NORMAL);  }
   else    
                        {lcd.LCD_write_string(0, 2," step      us " , MENU_NORMAL);   
                         lcd.LCD_write_string(42, 2, swx , MENU_NORMAL);  }   
   //delay     
   itoa(deli, delix, 10);
    if   (alma == 2) {lcd.LCD_write_string(0,   3,">            <" , MENU_HIGHLIGHT);  
                         lcd.LCD_write_string(6, 3,"delay     ms" , MENU_NORMAL);   
                         lcd.LCD_write_string(42, 3, delix , MENU_NORMAL);}      
   else    
                        {lcd.LCD_write_string(0, 3," delay     ms " , MENU_NORMAL);   
                         lcd.LCD_write_string(42, 3, delix , MENU_NORMAL); }    
   // PWM                         
   itoa(anna, annax, 10);
    if   (alma == 3) {lcd.LCD_write_string(0,   4,">            <" , MENU_HIGHLIGHT);     
                         lcd.LCD_write_string(6, 4,"pwm       us" , MENU_NORMAL);     
                         lcd.LCD_write_string(36, 4, annax , MENU_NORMAL);}
    else
                        {lcd.LCD_write_string(0, 4," pwm       us " , MENU_NORMAL);     
                         lcd.LCD_write_string(36, 4, annax , MENU_NORMAL);}
//***      



   delay(deli); 
   posz = map(anna, minpulse, maxpulse, 0, 179);  // mappes varistor value to +- 90° left/right  
   posa = map (posz, 0, 179, -90, +90);     // generates output position display values    
   itoa(posa, posax, 10);
   lcd.LCD_write_string(0, 5," servo     deg" , MENU_NORMAL);   
   lcd.LCD_write_string(42, 5, posax , MENU_NORMAL); 
   myservo.writeMicroseconds(anna);

//*****************************************************************
/* 
  if   (vertical == 3) {lcd.LCD_write_string(0,   4,">            <" , MENU_HIGHLIGHT);
                        lcd.LCD_write_string(6,  4," Combinada  "       , MENU_NORMAL);}
  else                 {lcd.LCD_write_string(0,  4, "  Combinada    "       , MENU_NORMAL);}     
 
*/
 
  // menu leave start   *********************************************

 z = analogRead(0);
 if (z > 140 && z <= 145 ) { goto bailout;}
 {sxtest();} 
 return; 

bailout:
  z = 1023; 
  lcd.LCD_init(); // creates instance of LCD
  lcd.LCD_clear(); // blanks the display  
  delay(150);  
  welcome();
// menu leave end   ********************************************* 
}
 
 /* ( THE END ) */
