void welcome()
{


                      //lcd.LCD_write_string(0,  0, "12345678901234" , MENU_NORMAL); 
  delay(dd);   
                        lcd.LCD_write_string(0,  0, "  PWM Tester  " , MENU_HIGHLIGHT);
                        
  if   (vertical == 1) {lcd.LCD_write_string(0,   2,">            <" , MENU_HIGHLIGHT);
                        lcd.LCD_write_string(6,  2," Servo Test "      , MENU_NORMAL);}
  else                 {lcd.LCD_write_string(0,  2, "  Servo Test   "      , MENU_NORMAL);}     

  if   (vertical == 2) {lcd.LCD_write_string(0,   3,">            <" , MENU_HIGHLIGHT);
                        lcd.LCD_write_string(6,  3," RX Test    "      , MENU_NORMAL);}
  else                 {lcd.LCD_write_string(0,  3, "  RX Test     " , MENU_NORMAL);}
  delay(dd);

              
  delay(dd);   
  
  if   (vertical == 3) {lcd.LCD_write_string(0,   4,">            <" , MENU_HIGHLIGHT);
                        lcd.LCD_write_string(6,  4," RX & Servo "       , MENU_NORMAL);}
  else                 {lcd.LCD_write_string(0,  4, "  RX & Servo  "       , MENU_NORMAL);}                   
  delay(dd);    




    z = analogRead(0);  

    if (z >= 0 && z < 750 )   { delay(350);}

    //down
    if (z>150 && z<350) { vertical = vertical + 1;  EEPROM.write(1, vertical );}     else
  
    //up 
    if (z>510 && z<750){ vertical = vertical - 1; EEPROM.write(1, vertical );}           
    if (vertical == 4) {vertical = 1; EEPROM.write(1, vertical );}
    if (vertical == 0) {vertical = 3; EEPROM.write(1, vertical );} 



    // ok
    if (z>0 && z<150 && vertical == 1)  
    {
     z=1023; 
    lcd.LCD_init(); // creates instance of LCD
    lcd.LCD_clear(); // blanks the display 
    delay(300); 
    sxtest();
    } 

    if (z>0 && z<150 && vertical == 2)  
    {
           z=1023; 
    lcd.LCD_init(); // creates instance of LCD
    lcd.LCD_clear(); // blanks the display 
    delay(300); 
    rxtest();
    } 
    if (z>0 && z<150 && vertical == 3)  
    {
           z=1023; 
    lcd.LCD_init(); // creates instance of LCD
    lcd.LCD_clear(); // blanks the display 
    delay(300); 
    cxtest();
    } 

}

/* ( THE END ) */
