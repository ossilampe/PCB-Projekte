


void rxtest()
{

   
  
  duration1 = pulseIn(pin1, HIGH, time); //reads rx channel in
  if (duration1 == 0){pwmin1 = 1500;} // if no input set to 1500us
  else {pwmin1 = duration1;}

  duration2 = pulseIn(pin2, HIGH, time); 
  if (duration2 == 0){pwmin2 = 1500;} 
  else {pwmin2 = duration2;}

  duration3 = pulseIn(pin3, HIGH, time ); 
  if (duration3 == 0){pwmin3 = 1500;} 
  else {pwmin3 = duration3;}

  duration4 = pulseIn(pin4, HIGH, time); 
  if (duration4 == 0){pwmin4 = 1500;} 
  else {pwmin4 = duration4;}

  duration5 = pulseIn(pin5, HIGH, time); //reads rx channel in
  if (duration5 == 0){pwmin5 = 1500;} // if no input set to 1500us
  else {pwmin5 = duration5;}

    duration6 = pulseIn(pin6, HIGH, time); 
  if (duration6 == 0){pwmin6 = 1500;} 
  else {pwmin6 = duration6;}

    duration7 = pulseIn(pin7, HIGH, time ); 
  if (duration7 == 0){pwmin7 = 1500;} 
  else {pwmin7 = duration7;}

    duration8 = pulseIn(pin8, HIGH, time); 
  if (duration8 == 0){pwmin8 = 1500;} 
  else {pwmin8 = duration8;}

                 //lcd.print("12345678901234");

 lcd.LCD_write_string(0,  0, "Receiver  Test", MENU_HIGHLIGHT);
//stick left 

 lcd.LCD_write_string(0,  2, "1       5", MENU_NORMAL); 
 itoa(pwmin1, pwm1, 10);
 lcd.LCD_write_string(12, 2 , pwm1 , MENU_NORMAL);
 itoa(pwmin5, pwm5, 10);
 lcd.LCD_write_string(60, 2 , pwm5 , MENU_NORMAL);  
 
 lcd.LCD_write_string(0,  3, "2       6", MENU_NORMAL);
 itoa(pwmin2, pwm2, 10);
 lcd.LCD_write_string(12, 3,  pwm2 , MENU_NORMAL);
 itoa(pwmin6, pwm6, 10);
 lcd.LCD_write_string(60, 3 , pwm6 , MENU_NORMAL); 
 
 lcd.LCD_write_string(0,  4, "3       7", MENU_NORMAL); 
 itoa(pwmin3, pwm3, 10);
 lcd.LCD_write_string(12, 4 , pwm3 , MENU_NORMAL); 
 itoa(pwmin7, pwm7, 10);
 lcd.LCD_write_string(60, 4 , pwm7 , MENU_NORMAL); 
 
 lcd.LCD_write_string(0,  5, "4       8", MENU_NORMAL);
 itoa(pwmin4, pwm4, 10);
 lcd.LCD_write_string(12, 5,  pwm4 , MENU_NORMAL);
 itoa(pwmin8, pwm8, 10);
 lcd.LCD_write_string(60, 5 , pwm8 , MENU_NORMAL); 

 
 
  // menu leave start   *********************************************
 z = analogRead(0);
 if (z > 140 && z <= 145 ) { goto bailout;}
 {rxtest();} 
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
 


