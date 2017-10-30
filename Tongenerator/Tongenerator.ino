/* tone(): einfaches Beispiel (3 Töne)
   angeregt durch Tom Igoe, Greg Borenstein
   copyleft fribbe fuer macherzin.net 2011-04-07
   Lizenz: Creative Commons by-nc-sa
   
   Beschaltung: 8 Ohm-Lautsprecher an Pin 9  
*/

void setup() {} // habe nichts zu sagen ...

void loop()
{
  noTone(9); // schalten Ton ab		
  tone(9, 100, 100); // geben Ton 100 Hz, Dauer 100 ms an Pin 9 aus
  delay(500); // warten 500 ms
  noTone(9); // schalten Ton ab	
  tone(9, 500, 500); // geben Ton 500 Hz, Dauer 500 ms an Pin 9 aus
  delay(500); // 500 ms
  noTone(9); // schalten Ton ab	
  tone(9, 1000, 1000); // geben Ton 1000 Hz, Dauer 1 s an Pin 9 aus
  delay(500); // 500 ms 
  // usw.  
}

// haben fertig
