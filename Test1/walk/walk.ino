void Walk() {

  int SLEEP=350;
  Head(); // Look for object
  // Lift leg2 leg4 leg6
  FAST_LEG2_B180();
  FAST_LEG2_C0();  
  FAST_LEG4_B180();
  FAST_LEG4_C0();
  FAST_LEG6_B180();
  FAST_LEG6_C0();
  delay(SLEEP);
  // Move body forward (leg1 leg 3 leg5)
  FAST_LEG1_A180();
  FAST_LEG3_A180();
  FAST_LEG5_A180();
  // Move forward leg2 leg4 and leg6
  FAST_LEG2_A0();
  FAST_LEG4_A0();
  FAST_LEG6_A0();
  delay(SLEEP);
  // Drop down leg2 leg4 and leg6
  FAST_LEG2_B90();
  FAST_LEG2_C90();
  FAST_LEG4_B90();
  FAST_LEG4_C90();
  FAST_LEG6_B90();
  FAST_LEG6_C90();
  delay(SLEEP);
  Head(); // Look for object
  // Lift leg1 leg3 and leg5
  FAST_LEG1_B180();
  FAST_LEG1_C0();
  FAST_LEG3_B180();
  FAST_LEG3_C0();
  FAST_LEG5_B180();  
  FAST_LEG5_C0();
  delay(SLEEP);
  // Move body forward (leg2 leg4 and leg6) move legs forward (leg1 leg3 and leg5)
  FAST_LEG2_A180();
  FAST_LEG4_A180();
  FAST_LEG6_A180();
  FAST_LEG1_A0();
  FAST_LEG3_A0();
  FAST_LEG5_A0();
  delay(SLEEP);
  // Drop down leg1 leg3 and leg5
  FAST_LEG1_B90();
  FAST_LEG1_C90();
  FAST_LEG3_B90();
  FAST_LEG3_C90();
  FAST_LEG5_B90();
  FAST_LEG5_C90();
  delay(SLEEP);
}
