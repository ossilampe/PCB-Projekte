//MaxSonar anschluss von hinten pin1 neben schraube links
// GND, 5V, frei, frei, Analog, Digital, frei
const int analog_pin = A0;  // Аналоговый сигнал датчика
const int pwm_pin    = 3;   // ШИМ-сигнал датчика

int analog_val = 0; // значение аналогового сигнала
int pwm_val    = 0; // значение ШИМ-сигнала

void setup() {
  Serial.begin(9600); 
  pinMode(pwm_pin, INPUT);     
}

void loop() {
  // Прочитать значения сигналов
  analog_val = analogRead(analog_pin);            
  pwm_val    = pulseIn(pwm_pin, HIGH);
  
  // Перевести значение в сантиметры
  int analog_val_cm = analog_val/0.78;
  
  // Из Datasheet: PW – This pin outputs a pulse width representation of range.
  // To alculate distance use the scale factor of 147mS per inch.
  // следовательно, 57.87 per cm.
  int pwm_val_cm    = pwm_val/57.87;
  
  // Вывод результатов
  Serial.print("analog_val = " );  Serial.print(analog_val);
  Serial.print("/cm = ");          Serial.print(analog_val_cm);
  
  Serial.print("\t\tpwm_val = " ); Serial.print(pwm_val);
  Serial.print("/cm = ");          Serial.print(pwm_val_cm);
  
  Serial.println();

  delay(200);                     
}
