#include <LiquidCrystal.h>
#include <VirtualWire.h>
LiquidCrystal lcd(4, 9, 5, 13, 3, 2);

void setup() {


  
  vw_rx_start();
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(11);
  vw_set_tx_pin(8);
  vw_setup(2000);
  

  Serial.begin(9600);
  Serial.println("Start.");
  lcd.setCursor(0, 0);
  
}

void loop() {
  lcd.setCursor(0,1);
  uint8_t message_array[VW_MAX_MESSAGE_LEN];
  uint8_t laenge = VW_MAX_MESSAGE_LEN;
  vw_wait_rx();
  
  
  vw_get_message(message_array, &laenge);
  lcd.print((char)message_array[0]);
  lcd.print((char)message_array[1]);
  lcd.print("C");
  Serial.print((char)message_array[0]);
  Serial.println((char)message_array[1]);
  
}
