void WalkBack() {
  int SLEEP=400;
  
  // Lift leg2 leg4 leg6
  FAST_LEG2_B180();
  FAST_LEG4_B180();
  FAST_LEG6_B180();
  FAST_LEG2_C0();
  FAST_LEG4_C0();
  FAST_LEG6_C0();
  delay(SLEEP);
  // Move body backward (leg1 leg 3 leg5)
  FAST_LEG1_A0();
  FAST_LEG3_A0();
  FAST_LEG5_A0();
  // Move backward leg2 leg4 and leg6
  FAST_LEG2_A180();
  FAST_LEG4_A180();
  FAST_LEG6_A180();
  delay(SLEEP);
  // Drop down leg2 leg4 and leg6
  FAST_LEG2_C90();
  FAST_LEG4_C90();
  FAST_LEG6_C90();
  FAST_LEG2_B90();
  FAST_LEG4_B90();
  FAST_LEG6_B90();
  delay(SLEEP);
  // Lift leg1 leg3 and leg5
  FAST_LEG1_B180();
  FAST_LEG3_B180();
  FAST_LEG5_B180();  
  FAST_LEG1_C0();
  FAST_LEG3_C0();
  FAST_LEG5_C0();
  delay(SLEEP);
  // Move body backward (leg2 leg4 and leg6) and legs backward (leg1 leg3 leg5)
  FAST_LEG2_A0();
  FAST_LEG4_A0();
  FAST_LEG6_A0();
  // Move backward leg2 leg4 and leg6
  FAST_LEG1_A180();
  FAST_LEG3_A180();
  FAST_LEG5_A180();
  delay(SLEEP);
  // Drop down leg1 leg3 and leg5
  FAST_LEG1_C90();
  FAST_LEG3_C90();
  FAST_LEG5_C90();
  FAST_LEG1_B90();
  FAST_LEG3_B90();
  FAST_LEG5_B90();
  delay(SLEEP);
}
