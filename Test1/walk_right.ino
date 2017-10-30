void WalkRight() {
  int SLEEP=250;
  int SHORTSLEEP=100;

  // Lift leg2 leg4 leg6
  LEG2_B180();
  LEG2_C0();
  LEG4_B180();
  LEG4_C0();
  LEG6_B180();
  LEG6_C0();
  delay(SLEEP);

  // Side move leg1 leg3 leg5
  LEG1_C180();
  LEG3_C180();
  LEG5_C0();
  delay(SHORTSLEEP);

  // Drop down leg2 leg4 leg6
  LEG2_B90();
  LEG2_C90();
  LEG4_B90();
  LEG4_C90();
  LEG6_B90();
  LEG6_C90();
  delay(SLEEP);

  // Lift leg1 leg3 leg5
  LEG1_B180();
  LEG1_C0();
  LEG3_B180();
  LEG3_C0();
  LEG5_B180();
  LEG5_C0();
  delay(SLEEP);

  // Side move leg2 leg4 leg6
  LEG2_C180();
  LEG4_C0();
  LEG6_C0();
  delay(SHORTSLEEP);

  // Drop down leg1 leg3 leg5
  LEG1_B90();
  LEG1_C90();
  LEG3_B90();
  LEG3_C90();
  LEG5_B90();
  LEG5_C90();
  delay(SLEEP);
}
