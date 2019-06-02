#include <Arduino.h>

#define ledPin 13

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()) {
    int message = Serial.read();
    /* faire des trucs cool ici */
  }
  delay(1000);
}
