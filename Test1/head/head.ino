void Head() {
  int DECISION=0;

  int SCAN90 = Infrared90(); // Execute Infrared90 function
  if (SCAN90 > 200) { // If an object is detected (200 = ~20cm)
    WalkStop();
    int SCAN45 = Infrared45(); // Check whats on the left
    if (SCAN45 < 100) { // If nothing on the left (120 = ~40cm)
      DECISION=1;
    }
    else {
      int SCAN135 = Infrared135(); // Check whats on the right
      if (SCAN135 < 100) { // If nothing on the right
        DECISION=2;
      }
      else {
        DECISION=3;
      }
    }
  }
  switch (DECISION) {
    case 0:
      break;
    case 1:
      HEAD90();
      BeepBlue();
      WalkLeft();
      WalkLeft();
      WalkLeft();
      WalkLeft();
      WalkStop();
      break;
    case 2:
      HEAD90();
      BeepBlue();
      WalkRight();
      WalkRight();
      WalkRight();
      WalkRight();
      WalkStop();
      break;
    case 3:
      HEAD90();
      BeepBlue();
      WalkBack();
      WalkBack();
      WalkBack();
      int RandNumber = random(0,2); // Randomly generate a 0 or a 1
      if(RandNumber == 0) {
        //Serial.println("-------------Im going left-------------");
        TurnLeft();
        TurnLeft();
        TurnLeft();
        TurnLeft();
        TurnLeft();
        TurnLeft();
      }
      if(RandNumber == 1) {
        //Serial.println("-------------Im going right-------------");
        TurnRight();
        TurnRight();
        TurnRight();
        TurnRight();
        TurnRight();
        TurnRight();
      }
      WalkStop();
      break;
  }
}

int Infrared90() {
    HEAD90(); // Move head to 90 degrees
    //delay(50); // Make sure servo had time to move before reading sensor
    int IRVALUE90 = analogRead(IRPIN); // Read value from IR sensor (large_value=close, small_value=far)
    return IRVALUE90; // Value returned by "Infrared90" function
}


int Infrared45() {
    HEAD45(); // Move head to 45 degrees
    delay(500); // Make sure servo had time to move before reading sensor
    int IRVALUE45 = analogRead(IRPIN); // Read value from IR sensor (large_value=close, small_value=far)
    return IRVALUE45; // Value returned by "Infrared45" function
}

int Infrared135() {
    HEAD135(); // Move head to 135 degrees
    delay(500); // Make sure servo had time to move before reading sensor
    int IRVALUE135 = analogRead(IRPIN); // Read value from IR sensor (large_value=close, small_value=far)
    return IRVALUE135; // Value returned by "Infrared135" function
}

