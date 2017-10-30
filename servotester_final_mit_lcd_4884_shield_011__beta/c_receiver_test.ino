


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

 lcd.LCD_write_string(0,  2, "1", MENU_NORMAL); 
 itoa(pwmin1, pwm1, 10);
 lcd.LCD_write_string(12, 2 , pwm1 , MENU_NORMAL);


// line  = zeile 0-5    
int linea = 2; 
int lineb = 3;
int linec = 4; 
int lined = 5;
int x = 1500; //center
int y = 25; //step


//build this array to show  graph 
float puls[] ={x-20*y,x-19*y,x-18*y,x-17*y,x-16*y,x-15*y,x-14*y,x-13*y, x-12*y,x-11*y,x-10*y,x-9*y,x-8*y,x-7*y,x-6*y,x-5*y,x-4*y,x-3*y,x-2*y,
               x-y, x, x+y, x+2*y, x+3*y, x+4*y, x+5*y, x+6*y, x+7*y, x+8*y, x+9*y, x+10*y, x+11*y, x+12*y, x+13*y, x+14*y, x+15*y, x+16*y, x+17*y, x+18*y, x+19*y, x+20*y };  // 16 channels every 20 mhz  + 4 channels from F band

    for (int i=0; i <= 40; i++){  // prints 20 bars

if (pwmin1 < x)    
{
if (pwmin1 > puls[i])                                      {lcd.LCD_set_XY(40+i,linea); lcd.LCD_write_byte(low,  1); }
if (pwmin1 < puls[i])                                      {lcd.LCD_set_XY(40+i,linea); lcd.LCD_write_byte(high, 1);}
if (x   == puls[i])                                        {lcd.LCD_set_XY(40+i,linea); lcd.LCD_write_byte(center,1);}
if (puls[i] > x )                                          {lcd.LCD_set_XY(40+i,linea); lcd.LCD_write_byte(low,1);}
if (pwmin1 + y/2 >= puls[i]  && pwmin1  - y/2  <= puls[i]) {lcd.LCD_set_XY(40+i,linea); lcd.LCD_write_byte(pulse,1);}
}
if (pwmin1 > x)    
{
if (pwmin1 > x && puls[i] < pwmin1)                        { lcd.LCD_set_XY(40+i,linea); lcd.LCD_write_byte(high,  1); }
if (pwmin1 > puls[i] && puls[i] < x)                       { lcd.LCD_set_XY(40+i,linea); lcd.LCD_write_byte(low, 1);}
if (x   == puls[i])                                        {lcd.LCD_set_XY(40+i,linea); lcd.LCD_write_byte(center,1);}
if (pwmin1 < puls[i]  )                                    {lcd.LCD_set_XY(40+i,linea); lcd.LCD_write_byte(low,1);}
if (pwmin1 + y/2 >= puls[i]  && pwmin1  - y/2  <= puls[i]) { lcd.LCD_set_XY(40+i,linea); lcd.LCD_write_byte(pulse,1);}

}

if (pwmin1 == x)    
{                                  lcd.LCD_set_XY(40+i,linea); lcd.LCD_write_byte(low, 1); 
if (x   == puls[i])               {lcd.LCD_set_XY(40+i,linea); lcd.LCD_write_byte(center,1);} 
}
}

 
 lcd.LCD_write_string(0,  3, "2", MENU_NORMAL);
 itoa(pwmin2, pwm2, 10);
 lcd.LCD_write_string(12, 3,  pwm2 , MENU_NORMAL);


    for (int i=0; i <= 40; i++){  // prints 20 bars

if (pwmin2 < x)    
{
if (pwmin2 > puls[i])                                      {lcd.LCD_set_XY(40+i,lineb); lcd.LCD_write_byte(low,  1); }
if (pwmin2 < puls[i])                                      {lcd.LCD_set_XY(40+i,lineb); lcd.LCD_write_byte(high, 1);}
if (x   == puls[i])                                        {lcd.LCD_set_XY(40+i,lineb); lcd.LCD_write_byte(center,1);}
if (puls[i] > x )                                          {lcd.LCD_set_XY(40+i,lineb); lcd.LCD_write_byte(low,1);}
if (pwmin2 + y/2 >= puls[i]  && pwmin2  - y/2  <= puls[i]) {lcd.LCD_set_XY(40+i,lineb); lcd.LCD_write_byte(pulse,1);}
}
if (pwmin2 > x)    
{
if (pwmin2 > x && puls[i] < pwmin2)                        { lcd.LCD_set_XY(40+i,lineb); lcd.LCD_write_byte(high,  1); }
if (pwmin2 > puls[i] && puls[i] < x)                       { lcd.LCD_set_XY(40+i,lineb); lcd.LCD_write_byte(low, 1);}
if (x   == puls[i])                                        {lcd.LCD_set_XY(40+i,lineb); lcd.LCD_write_byte(center,1);}
if (pwmin2 < puls[i]  )                                    {lcd.LCD_set_XY(40+i,lineb); lcd.LCD_write_byte(low,1);}
if (pwmin2 + y/2 >= puls[i]  && pwmin2  - y/2  <= puls[i]) { lcd.LCD_set_XY(40+i,lineb); lcd.LCD_write_byte(pulse,1);}

}

if (pwmin2 == x)    
{                                  lcd.LCD_set_XY(40+i,lineb); lcd.LCD_write_byte(low, 1); 
if (x   == puls[i])               {lcd.LCD_set_XY(40+i,lineb); lcd.LCD_write_byte(center,1);} 
}
}




 
 lcd.LCD_write_string(0,  4, "3", MENU_NORMAL); 
 itoa(pwmin3, pwm3, 10);
 lcd.LCD_write_string(12, 4 , pwm3 , MENU_NORMAL); 

    for (int i=0; i <= 40; i++){  // prints 20 bars

if (pwmin3 < x)    
{
if (pwmin3 > puls[i])                                      {lcd.LCD_set_XY(40+i,linec); lcd.LCD_write_byte(low,  1); }
if (pwmin3 < puls[i])                                      {lcd.LCD_set_XY(40+i,linec); lcd.LCD_write_byte(high, 1);}
if (x   == puls[i])                                        {lcd.LCD_set_XY(40+i,linec); lcd.LCD_write_byte(center,1);}
if (puls[i] > x )                                          {lcd.LCD_set_XY(40+i,linec); lcd.LCD_write_byte(low,1);}
if (pwmin3 + y/2 >= puls[i]  && pwmin3  - y/2  <= puls[i]) {lcd.LCD_set_XY(40+i,linec); lcd.LCD_write_byte(pulse,1);}
}
if (pwmin3 > x)    
{
if (pwmin3 > x && puls[i] < pwmin3)                        { lcd.LCD_set_XY(40+i,linec); lcd.LCD_write_byte(high,  1); }
if (pwmin3 > puls[i] && puls[i] < x)                       { lcd.LCD_set_XY(40+i,linec); lcd.LCD_write_byte(low, 1);}
if (x   == puls[i])                                        {lcd.LCD_set_XY(40+i,linec); lcd.LCD_write_byte(center,1);}
if (pwmin3 < puls[i]  )                                    {lcd.LCD_set_XY(40+i,linec); lcd.LCD_write_byte(low,1);}
if (pwmin3 + y/2 >= puls[i]  && pwmin3  - y/2  <= puls[i]) { lcd.LCD_set_XY(40+i,linec); lcd.LCD_write_byte(pulse,1);}

}

if (pwmin3 == x)    
{                                  lcd.LCD_set_XY(40+i,linec); lcd.LCD_write_byte(low, 1); 
if (x   == puls[i])               {lcd.LCD_set_XY(40+i,linec); lcd.LCD_write_byte(center,1);} 
}
} 
 lcd.LCD_write_string(0,  5, "4", MENU_NORMAL);
 itoa(pwmin4, pwm4, 10);
 lcd.LCD_write_string(12, 5,  pwm4 , MENU_NORMAL);
 
 
 for (int i=0; i <= 40; i++){  // prints 20 bars

if (pwmin4 < x)    
{
if (pwmin4 > puls[i])                                      {lcd.LCD_set_XY(40+i,lined); lcd.LCD_write_byte(low,  1); }
if (pwmin4 < puls[i])                                      {lcd.LCD_set_XY(40+i,lined); lcd.LCD_write_byte(high, 1);}
if (x   == puls[i])                                        {lcd.LCD_set_XY(40+i,lined); lcd.LCD_write_byte(center,1);}
if (puls[i] > x )                                          {lcd.LCD_set_XY(40+i,lined); lcd.LCD_write_byte(low,1);}
if (pwmin4 + y/2 >= puls[i]  && pwmin4  - y/2  <= puls[i]) {lcd.LCD_set_XY(40+i,lined); lcd.LCD_write_byte(pulse,1);}
}
if (pwmin4 > x)    
{
if (pwmin4 > x && puls[i] < pwmin4)                        { lcd.LCD_set_XY(40+i,lined); lcd.LCD_write_byte(high,  1); }
if (pwmin4 > puls[i] && puls[i] < x)                       { lcd.LCD_set_XY(40+i,lined); lcd.LCD_write_byte(low, 1);}
if (x   == puls[i])                                        {lcd.LCD_set_XY(40+i,lined); lcd.LCD_write_byte(center,1);}
if (pwmin4 < puls[i]  )                                    {lcd.LCD_set_XY(40+i,lined); lcd.LCD_write_byte(low,1);}
if (pwmin4 + y/2 >= puls[i]  && pwmin4  - y/2  <= puls[i]) { lcd.LCD_set_XY(40+i,lined); lcd.LCD_write_byte(pulse,1);}

}

if (pwmin4 == x)    
{                                  lcd.LCD_set_XY(40+i,lined); lcd.LCD_write_byte(low, 1); 
if (x   == puls[i])               {lcd.LCD_set_XY(40+i,lined); lcd.LCD_write_byte(center,1);} 
}
} 

 
 
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
 


