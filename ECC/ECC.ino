#include <LiquidCrystal.h>

const char *message = "Hi!";
#define led 6
#define clk 7
#define rx_rate 5 // fréquence

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // réglage LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  // lcd.print(message);
  
  pinMode(led, OUTPUT);
  pinMode(clk, OUTPUT);

  for (int byte_idx = 0; byte_idx < strlen(message); byte_idx++) {
      char rx_byte = message[byte_idx];
      lcd.noCursor();
      lcd.setCursor(0, 1);
      lcd.print("        "); // efface la 2nde ligne pour laisser de la place au nouveau byte 
      lcd.setCursor(byte_idx, 0);
      lcd.cursor(); // affiche le curseur en dessous de la lettre en récepetion 
      for (int bit_idx = 0; bit_idx < 8; bit_idx++) {
        delay(1000 / rx_rate / 2);
        bool rx_bit = rx_byte & (0x80 >> bit_idx); // décale le 1 vers la droite à chaque itération 
        digitalWrite(led, rx_bit);
        lcd.noCursor();
        lcd.setCursor(bit_idx, 1);
        lcd.print(rx_bit ? "1" : "0"); // affiche 1 si true, 0 sinon
        lcd.setCursor(byte_idx, 0);
        lcd.cursor();
        digitalWrite(clk, HIGH);
        delay(1000 / rx_rate / 2);
        digitalWrite(clk, LOW);
      }
      lcd.setCursor(byte_idx, 0);
      lcd.print(rx_byte);
  }
  digitalWrite(led, LOW);
  digitalWrite(clk, LOW);
  lcd.setCursor(0, 1);
  lcd.print("        ");
  lcd.noCursor();

  for (int i = 0; i <16; i++) {
    // envoi des 16 zéros pour le CRC
    delay(1000 / rx_rate / 2);
    digitalWrite(clk, HIGH);
    delay(1000 / rx_rate / 2);
    digitalWrite(clk, LOW);
  }
}

void loop() {
   
}
