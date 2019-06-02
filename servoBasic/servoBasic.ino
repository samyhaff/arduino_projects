#define servoPin 9

void setup() {
  pinMode(servoPin, OUTPUT);
}

void loop() {
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(1500); //90 deg
  digitalWrite(servoPin, LOW);
  delayMicroseconds(20000); // pulse toutes les 20 ms
}
