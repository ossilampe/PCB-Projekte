void TurnRight() {
  int SLEEP=350;

  // Lift Leg1 leg3 leg5
  LEG1_B180();
  LEG1_C0();
  LEG3_B180();
  LEG3_C0();
  LEG5_B180();
  LEG5_C0();
  delay(SLEEP);

  // Turn leg1 leg3 and leg5 and body to the right (leg2 leg4 leg6)
  LEG1_A180();
  LEG3_A0();
  LEG5_A0();
  LEG2_A0();
  LEG4_A0();
  LEG6_A180();
  delay(SLEEP);

  // Drop down leg1 leg3 and leg5
  LEG1_B90();
  LEG1_C90();
  LEG3_B90();
  LEG3_C90();
  LEG5_B90();
  LEG5_C90();
  delay(SLEEP);

  // Lift Leg2 leg4 leg6
  LEG2_B180();
  LEG2_C0();
  LEG4_B180();
  LEG4_C0();
  LEG6_B180();
  LEG6_C0();
  delay(SLEEP);

  // Turn leg2 leg4 and leg6 and body to the right (leg1 leg3 leg5)
  LEG2_A180();
  LEG4_A180();
  LEG6_A0();
  LEG1_A0();
  LEG3_A180();
  LEG5_A180();
  delay(SLEEP);

  // Drop down leg2 leg4 and leg6
  LEG2_B90();
  LEG2_C90();
  LEG4_B90();
  LEG4_C90();
  LEG6_B90();
  LEG6_C90();
  delay(SLEEP);
}
