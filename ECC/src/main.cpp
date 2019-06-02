#include <Arduino.h>
#include <LiquidCrystal.h>

#define ledPin 10
#define clock 11
#define frequence 5
#define TX_DATA 3
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D4 4
#define LCD_D7 7
#define LCD_RS 8
#define LCD_EN 9

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

int message;
String chaine;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(clock, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()) {
    message = Serial.read();

    for (int bit = 0; bit <= strlen(message); bit++) {
      bit 
  }
}
