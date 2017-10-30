/*
SCK   -  Pin3
SID   -  Pin9
CS    8  Pin8

*/


#include "LCD12864RSPI.h"  
 void setup()  
 {  
  LCDA.initialise();  
  delay(100);  
 }  
 int i = 1;  
 void loop()  
 {  
  LCDA.clear();  
  delay(10);  
  LCDA.printf(0, 0, "Es sind %d       s seit dem Start vergangen", i);  
  delay(1000);  
  i++;  
 }  
