#include "SevSeg.h"
SevSeg sevseg; 
const char DOUT_TRIGGER = 7;
const char DIN_ECHO = 6;
float distance;

void setup() {
  pinMode(A0, INPUT);
  byte numDigits = 4;
  byte digitPins[] = {9, 10, 11, 12};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 13};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(100);
  pinMode(DOUT_TRIGGER, OUTPUT);
  pinMode(DIN_ECHO, INPUT);
}
  
void loop() {
  digitalWrite(DOUT_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(DOUT_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(DOUT_TRIGGER, LOW);
  distance= pulseIn(DIN_ECHO, HIGH) / 58.0;
  sevseg.setNumber(distance, 0);
  sevseg.refreshDisplay();
  delay(1000);
}
