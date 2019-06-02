#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(9);
  servo.write(100);
  delay(5000);
  servo.write(90);
  delay(200);
  servo.write(100);
  delay(750);
}

void loop() {
  servo.write(0);
  delay(200);
  servo.write(100);
  delay(600);
}


