void input() { //Function for allowing user input and checking input against the generated array

  for (int x=0; x <= turn;)
  { //Statement controlled by turn count

    for(int y=0; y<4; y++)
    {
     
      buttonstate = digitalRead(button[y]);
   
      if (buttonstate == LOW && button[y] == 2)
      { //Checking for button push
        digitalWrite(ledpin[0], HIGH);
        speakerpin.play(NOTE_G3, 100);
        delay(200);
        digitalWrite(ledpin[0], LOW);
        inputArray[x] = 1;
        delay(250);
        Serial.print(" ");
        Serial.print(1);
        if (inputArray[x] != randomArray[x]) { //Checks value input by user and checks it against
          fail();                              //the value in the same spot on the generated array
        }                                      //The fail function is called if it does not match
        x++;
      }
       if (buttonstate == LOW && button[y] == 3)
      {
        digitalWrite(ledpin[1], HIGH);
        speakerpin.play(NOTE_A3, 100);
        delay(200);
        digitalWrite(ledpin[1], LOW);
        inputArray[x] = 2;
        delay(250);
        Serial.print(" ");
        Serial.print(2);
        if (inputArray[x] != randomArray[x]) {
          fail();
        }
        x++;
      }

      if (buttonstate == LOW && button[y] == 4)
      {
        digitalWrite(ledpin[2], HIGH);
        speakerpin.play(NOTE_B3, 100);
        delay(200);
        digitalWrite(ledpin[2], LOW);
        inputArray[x] = 3;
        delay(250);
        Serial.print(" ");
        Serial.print(3);
        if (inputArray[x] != randomArray[x]) {
          fail();
        }
        x++;
      }

      if (buttonstate == LOW && button[y] == 5)
      {
        digitalWrite(ledpin[3], HIGH);
        speakerpin.play(NOTE_C4, 100);
        delay(200);
        digitalWrite(ledpin[3], LOW);
        inputArray[x] = 4;
        delay(250);
        Serial.print(" ");
        Serial.print(4);
        if (inputArray[x] != randomArray[x])
        {
          fail();
        }
        x++;
      }
    }
  }
  delay(500);
  turn++; //Increments the turn count, also the last action before starting the output function over again
}






void fail() { //Function used if the player fails to match the sequence

  for (int y=0; y<=2; y++)
  { //Flashes lights for failure
   
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[1], HIGH);
    digitalWrite(ledpin[2], HIGH);
    digitalWrite(ledpin[3], HIGH);
    speakerpin.play(NOTE_G3, 300);
    delay(200);
    digitalWrite(ledpin[0], LOW);
    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[2], LOW);
    digitalWrite(ledpin[3], LOW);
    speakerpin.play(NOTE_C3, 300);
    delay(200);
  }
  delay(500);
  turn = -1; //Resets turn value so the game starts over without need for a reset button
}

