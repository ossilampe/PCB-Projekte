
/*     ______
----|6    3|----
    |      |
----|5    2|----
    |      |
----|4    1|----
    |______|
      Head

With
A: body servo
B: knie servo
C: fuss servo



 __________________________
|pos| body | knie  | fuss  |
|   |  A   |   B   |   C   |
|   |      |       |       |
| 1 |  0   |   1   |   3   |
| 2 |  5   |   6   |   7   |
| 3 |  8   |   9   |   10  |
| 4 |  16  |   17  |   18  |
| 5 |  20  |   21  |   22  |
| 6 |  24  |   25  |   26  |
 __________________________

*/

/************ HEAD ************************/
void HEAD45(){
  Serial.println("#31 P2400 T200");
}
void HEAD90(){
  Serial.println("#31 P1500 T200");
}
void HEAD135(){
  Serial.println("#31 P700 T200");
}


/************LEG 1*************************/
/************LEG 1A**************/
void LEG1_A0(){
  Serial.println("#0 P800 T500");
}
void LEG1_A90(){
  Serial.println("#0 P1300 T500");
}
void LEG1_A180(){
  Serial.println("#0 P1700 T500");
}
/************LEG 1B**************/
void LEG1_B0(){
  Serial.println("#1 P2500 T400");
}
void LEG1_B90(){
  Serial.println("#1 P2200 T400");
}
void LEG1_B180(){
  Serial.println("#1 P1800 T400");
}
/************LEG 1C**************/
void LEG1_C0(){
  Serial.println("#2 P1000 T400");
}
void LEG1_C90(){
  Serial.println("#2 P1400 T400");
}
void LEG1_C180(){
  Serial.println("#2 P1800 T400");
}

/************LEG 2*************************/
/************LEG 2A**************/
void LEG2_A0(){
  Serial.println("#4 P800 T500");
}
void LEG2_A90(){
  Serial.println("#4 P1450 T500");
}
void LEG2_A180(){
  Serial.println("#4 P1900 T500");
}
/************LEG 2B**************/
void LEG2_B0(){
  Serial.println("#5 P2300 T400");
}
void LEG2_B90(){
  Serial.println("#5 P2000 T400");
}
void LEG2_B180(){
  Serial.println("#5 P1600 T400");
}
/************LEG 2C**************/
void LEG2_C0(){
  Serial.println("6 P1000 T400");
}
void LEG2_C90(){
  Serial.println("#6 P1400 T400");
}
void LEG2_C180(){
  Serial.println("#6 P1800 T400");
}

/************LEG 3*************************/
/************LEG 3A**************/
void LEG3_A0(){
  Serial.println("#8 P1200 T500");
}
void LEG3_A90(){
  Serial.println("#8 P1500 T500");
}
void LEG3_A180(){
  Serial.println("#8 P1800 T500");
}
/************LEG 3B**************/
void LEG3_B0(){
  Serial.println("#9 P2300 T400");
}
void LEG3_B90(){
  Serial.println("#9 P2000 T400");
}
void LEG3_B180(){
  Serial.println("#9 P1600 T400");
}
/************LEG 3C**************/
void LEG3_C0(){
  Serial.println("#10 P1000 T400");
}
void LEG3_C90(){
  Serial.println("#10 P1400 T400");
}
void LEG3_C180(){
  Serial.println("#10 P1800 T400");
}
/************LEG 4*************************/
/************LEG 4A**************/
void LEG4_A0(){
  Serial.println("#16 P2100 T500");
}
void LEG4_A90(){
  Serial.println("#16 P1500 T400");
}
void LEG4_A180(){
  Serial.println("#16 P1200 T400");
}
/************LEG 4B**************/
void LEG4_B0(){
  Serial.println("#17 P600 T400");
}
void LEG4_B90(){
  Serial.println("#17 P850 T400");
}
void LEG4_B180(){
  Serial.println("#17 P1300 T400");
}
/************LEG 4C**************/
void LEG4_C0(){
  Serial.println("#18 P2000 T400");
}
void LEG4_C90(){
  Serial.println("#18 P1600 T400");
}
void LEG4_C180(){
  Serial.println("#18 P1200 T400");
}
/************LEG 5*************************/
/************LEG 5A**************/
void LEG5_A0(){
  Serial.println("#20 P2200 T500");
}
void LEG5_A90(){
  Serial.println("#20 P1550 T500");
}
void LEG5_A180(){
  Serial.println("#20 P1100 T500");
}
/************LEG 5B**************/
void LEG5_B0(){
  Serial.println("#21 P700 T400");
}
void LEG5_B90(){
  Serial.println("#21 P1000 T400");
}
void LEG5_B180(){
  Serial.println("#21 P1400 T400");
}
/************LEG 5C**************/
void LEG5_C0(){
  Serial.println("#22 P2000 T400");
}
void LEG5_C90(){
  Serial.println("#22 P1600 T400");
}
void LEG5_C180(){
  Serial.println("#22 P1200 T400");
}
/************LEG 6*************************/
/************LEG 6A**************/
void LEG6_A0(){
  Serial.println("#24 P1750 T500");
}
void LEG6_A90(){
  Serial.println("#24 P1400 T500");
}
void LEG6_A180(){
  Serial.println("#24 P1000 T500");
}
/************LEG 6B**************/
void LEG6_B0(){
  Serial.println("#25 P800 T400");
}
void LEG6_B90(){
  Serial.println("#25 P1100 T400");
}
void LEG6_B180(){
  Serial.println("#25 P1400 T400");
}
/************LEG 6C**************/
void LEG6_C0(){
  Serial.println("#26 P2000 T400");
}
void LEG6_C90(){
  Serial.println("#26 P1700 T400");
}
void LEG6_C180(){
  Serial.println("#26 P1400 T400");
}


/* This is another set of position, also moving faster */
/************FAST_LEG 1*************************/
/************FAST_LEG 1A**************/
void FAST_LEG1_A0(){
Serial.println("#0 P1275 T450");
}
void FAST_LEG1_A90(){
Serial.println("#0 P1200 T450");
}
void FAST_LEG1_A180(){
Serial.println("#0 P1125 T450");
}
/************FAST_LEG 1B**************/
void FAST_LEG1_B0(){
Serial.println("#1 P1325 T150");
}
void FAST_LEG1_B90(){
Serial.println("#1 P1625 T150");
}

void FAST_LEG1_B180(){
Serial.println("#1 P1925 T150");
}
/************FAST_LEG 1C**************/
void FAST_LEG1_C0(){
Serial.println("#2 P1700 T150");
}
void FAST_LEG1_C90(){
Serial.println("#2 P1400 T150");
}
void FAST_LEG1_C180(){
Serial.println("#2 P1150 T150");
}

/************FAST_LEG 2*************************/
/************FAST_LEG 2A**************/
void FAST_LEG2_A0(){
Serial.println("#4 P1500 T450");
}
void FAST_LEG2_A90(){
Serial.println("#4 P1425 T450");
}
void FAST_LEG2_A180(){
Serial.println("#4 P1350 T450");
}
/************FAST_LEG 2B**************/
void FAST_LEG2_B0(){
Serial.println("#5 P1325 T150");
}
void FAST_LEG2_B90(){
Serial.println("#5 P1625 T150");
}

void FAST_LEG2_B180(){
Serial.println("#5 P1925 T150");
}
/************FAST_LEG 2C**************/
void FAST_LEG2_C0(){
Serial.println("#6 P2050 T150");
}
void FAST_LEG2_C90(){
Serial.println("#6 P1750 T150");
}
void FAST_LEG2_C180(){
Serial.println("#26 P1500 T150");
}

/************FAST_LEG 3*************************/
/************FAST_LEG 3A**************/
void FAST_LEG3_A0(){
Serial.println("#8 P1575 T450");
}
void FAST_LEG3_A90(){
Serial.println("#8 P1500 T450");
}
void FAST_LEG3_A180(){
Serial.println("#8 P1425 T450");
}
/************FAST_LEG 3B**************/
void FAST_LEG3_B0(){
Serial.println("#9 P950 T150");
}
void FAST_LEG3_B90(){
Serial.println("#9 P1250 T150");
}
void FAST_LEG3_B180(){
Serial.println("#9 P1550 T150");
}
/************FAST_LEG 3C**************/
void FAST_LEG3_C0(){
Serial.println("#10 P1950 T150");
}
void FAST_LEG3_C90(){
Serial.println("#10 P1650 T150");
}
void FAST_LEG3_C180(){
Serial.println("#10 P1400 T150");
}
/************FAST_LEG 4*************************/
/************FAST_LEG 4A**************/
void FAST_LEG4_A0(){
Serial.println("#16 P1825 T450");
}
void FAST_LEG4_A90(){
Serial.println("#16 P1900 T450");
}
void FAST_LEG4_A180(){
Serial.println("#16 P1975 T450");
}
/************FAST_LEG 4B**************/
void FAST_LEG4_B0(){
Serial.println("#17 P1675 T150");
}
void FAST_LEG4_B90(){
Serial.println("#17 P1375 T150");
}
void FAST_LEG4_B180(){
Serial.println("#17 P1075 T150");
}
/************FAST_LEG 4C**************/
void FAST_LEG4_C0(){
Serial.println("#18 P1200 T150");
}
void FAST_LEG4_C90(){
Serial.println("#18 P1500 T150");
}
void FAST_LEG4_C180(){
Serial.println("#18 P1750 T150");
}
/************FAST_LEG 5*************************/
/************FAST_LEG 5A**************/
void FAST_LEG5_A0(){
Serial.println("#20 P1525 T450");
}
void FAST_LEG5_A90(){
Serial.println("#20 P1600 T450");
}
void FAST_LEG5_A180(){
Serial.println("#20 P1675 T450");
}
/************FAST_LEG 5B**************/
void FAST_LEG5_B0(){
Serial.println("#21 P1775 T150");
}
void FAST_LEG5_B90(){
Serial.println("#21 P1475 T150");
}

void FAST_LEG5_B180(){
Serial.println("#21 P1175 T150");
}
/************FAST_LEG 5C**************/
void FAST_LEG5_C0(){
Serial.println("#22 P1300 T150");
}
void FAST_LEG5_C90(){
Serial.println("#22 P1600 T150");
}
void FAST_LEG5_C180(){
Serial.println("#22 P1850 T150");
}
/************FAST_LEG 6*************************/
/************FAST_LEG 6A**************/
void FAST_LEG6_A0(){
Serial.println("#24 P1125 T450");
}
void FAST_LEG6_A90(){
Serial.println("#24 P1200 T450");
}
void FAST_LEG6_A180(){
Serial.println("#24 P1275 T450");
}
/************FAST_LEG 6B**************/
void FAST_LEG6_B0(){
Serial.println("#25 P1850 T150");
}
void FAST_LEG6_B90(){
Serial.println("#25 P1550 T150");
}

void FAST_LEG6_B180(){
Serial.println("#25 P1250 T150");
}
/************FAST_LEG 6C**************/
void FAST_LEG6_C0(){
Serial.println("#26 P1600 T150");
}
void FAST_LEG6_C90(){
Serial.println("#26 P1850 T150");
}
void FAST_LEG6_C180(){
Serial.println("#26 P2100 T150");
}
