void WalkStop() {
  int SLEEP=500;
 
  // All legs back to ground whatever the coxa position
  FAST_LEG1_B90();
  FAST_LEG2_B90();
  FAST_LEG3_B90();
  FAST_LEG4_B90();
  FAST_LEG5_B90();
  FAST_LEG6_B90();
  FAST_LEG1_C90();
  FAST_LEG2_C90();
  FAST_LEG3_C90();
  FAST_LEG4_C90();
  FAST_LEG5_C90();
  FAST_LEG6_C90();

  // All legs nornal to body
  // Leg1 leg3 and leg5 at the same time
  FAST_LEG1_B180();
  FAST_LEG1_C0();
  FAST_LEG1_A90();
  FAST_LEG3_B180();
  FAST_LEG3_C0();
  FAST_LEG3_A90(); 
  FAST_LEG5_B180();
  FAST_LEG5_C0();
  FAST_LEG5_A90();  
  delay(SLEEP);
  FAST_LEG1_B90();
  FAST_LEG1_C90();
  FAST_LEG3_B90();
  FAST_LEG3_C90();
  FAST_LEG5_B90();
  FAST_LEG5_C90();
  delay(SLEEP);
  
  // Leg2 leg4 and leg6 at the same time
  FAST_LEG2_B180();
  FAST_LEG2_C0();
  FAST_LEG2_A90();
  FAST_LEG4_B180();
  FAST_LEG4_C0();
  FAST_LEG4_A90();
  FAST_LEG6_B180();
  FAST_LEG6_C0();
  FAST_LEG6_A90();
  delay(SLEEP);
  FAST_LEG2_B90();
  FAST_LEG2_C90();
  FAST_LEG4_B90();
  FAST_LEG4_C90();
  FAST_LEG6_B90();
  FAST_LEG6_C90();
  delay(SLEEP);
}

