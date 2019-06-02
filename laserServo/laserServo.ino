#include <Servo.h>

Servo myservo1;
Servo myservo2;

long pot1 = A0;
long pot2 = A1;
int rot1;
int rot2;
int val1;
int val2;

void setup() {
  myservo1.attach(9, 1000, 2485);
  myservo2.attach(10, 1000, 2485);
  myservo1.write(0);
  myservo2.write(0);

}

void loop() {
  val1 = analogRead(pot1);
  val2 = analogRead(pot2);
  rot1 = map(val1, 0, 1023, 0, 180);
  rot2 = map(val2, 0, 1023, 0, 180);
  myservo1.write(rot1);
  myservo2.write(rot2);
  delay(1);
}
