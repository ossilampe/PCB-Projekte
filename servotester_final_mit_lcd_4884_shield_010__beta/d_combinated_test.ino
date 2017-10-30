void  cxtest()
{
  // menu header start    *********************************************


  sw = EEPROM.read(2);
  deli = EEPROM.read(3);


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

// lcd.LCD_write_string(0,  0, "Receiver  Test", MENU_HIGHLIGHT);
 lcd.LCD_write_string(0,  0, " Mixed    Test", MENU_HIGHLIGHT);


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


 if   (xray == 1){lcd.LCD_write_string(6,  2, "x", MENU_NORMAL);}
 else            {lcd.LCD_write_string(6,  2, " ", MENU_NORMAL);}
 if   (xray == 5){lcd.LCD_write_string(54, 2, "x", MENU_NORMAL);}
 else            {lcd.LCD_write_string(54, 2, " ", MENU_NORMAL);}
 if   (xray == 2){lcd.LCD_write_string(6,  3, "x", MENU_NORMAL);}
 else            {lcd.LCD_write_string(6,  3, " ", MENU_NORMAL);}
 if   (xray == 6){lcd.LCD_write_string(54, 3, "x", MENU_NORMAL);}
 else            {lcd.LCD_write_string(54, 3, " ", MENU_NORMAL);}
 if   (xray == 3){lcd.LCD_write_string(6,  4, "x", MENU_NORMAL);}
 else            {lcd.LCD_write_string(6,  4, " ", MENU_NORMAL);}
 if   (xray == 7){lcd.LCD_write_string(54, 4, "x", MENU_NORMAL);}
 else            {lcd.LCD_write_string(54, 4, " ", MENU_NORMAL);}
 if   (xray == 4){lcd.LCD_write_string(6,  5, "x", MENU_NORMAL);}
 else            {lcd.LCD_write_string(6,  5, " ", MENU_NORMAL);}
 if   (xray == 8){lcd.LCD_write_string(54, 5, "x", MENU_NORMAL);}
 else            {lcd.LCD_write_string(54, 5, " ", MENU_NORMAL);}


//************************************* x ray *************************
  
    z = analogRead(0);  

    //up & down
    if (z>150 && z<350) { xray = xray + 1;}     else
    if (z>510 && z<750){ xray = xray - 1;}           
    if (xray == 9) {xray = 1;}
    if (xray == 0) {xray = 8;} 
    // ok
    if (z>0 && z<150 && xray == 1)  
    {
    } 
    if (z>0 && z<150 && xray == 2)  
    {
    } 
    if (z>0 && z<150 && xray == 3)  
    {
    } 
    if (z>0 && z<150 && xray == 4)  
    {
    } 
    if (z>0 && z<150 && xray == 5)  
    {
    } 
    if (z>0 && z<150 && xray == 6)  
    {
    } 
    if (z>0 && z<150 && xray == 7)  
    {
    } 
    if (z>0 && z<150 && xray == 8)  
    {
    } 
/*   // display selected channel as number
 itoa(xray, xrayx, 10);
 lcd.LCD_write_string(76, 1, xrayx , MENU_NORMAL); 
*/

    z = analogRead(0);
    //left &  right
    if (z==0) { anna = anna - sw;}    
    if (z>350 && z<510){anna = anna + sw;}           
    if (anna > maxpulse) {anna = maxpulse;}
    if (anna < minpulse) {anna = minpulse;} 
   
   lcd.LCD_write_string(0, 1, "A     " , MENU_NORMAL);   
   itoa(anna, annax, 10);
   lcd.LCD_write_string(12, 1, annax , MENU_NORMAL); 
   
  
  

if (xray == 1) {pos = (pwmin1 + anna) / 2; }  // analog position summed as trim to value of channel 1    divided by 2
if (xray == 2) {pos = (pwmin2 + anna) / 2; }  
if (xray == 3) {pos = (pwmin3 + anna) / 2; }  
if (xray == 4) {pos = (pwmin4 + anna) / 2; }  
if (xray == 5) {pos = (pwmin5 + anna) / 2; }  
if (xray == 6) {pos = (pwmin6 + anna) / 2; }  
if (xray == 7) {pos = (pwmin7 + anna) / 2; }  
if (xray == 8) {pos = (pwmin8 + anna) / 2; }  

// integration against servo jitter  
if (iv == 1)  
{
  posx = pos * fac;		 // actuell VSWR value goes for x% to the old integration pool  fac = 0.1  10%   fac = 0.5 = 50%   0,1 = 10 loops 
  posy = posold *(1-fac);        // parts actuell und old must give 1
  posnew = posx + posy;		 // old * actuell = new
  posold = posnew;		 // actuell value will the old  in the next round     
  posz = posnew;
} 
else
{
posz = pos;
}  

  myservo.write(posz);  

// sets the servo position    
   xyz =  myservo.readMicroseconds();
   lcd.LCD_write_string(48, 1, "S     " , MENU_NORMAL);     
   itoa(xyz, xyzx, 10);
   lcd.LCD_write_string(60, 1, xyzx , MENU_NORMAL); 
 
 
 
// ****************************************************************************************** 
// menu leave start   *********************************************

 z = analogRead(0);
 if (z > 140 && z <= 145 ) { goto bailout;}
 {cxtest();} 
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
