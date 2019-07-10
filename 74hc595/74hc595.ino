const int verrou = 11;
const int horloge = 12;
const int data = 10;

void setup() {
  pinMode(verrou, OUTPUT);
  pinMode(horloge, OUTPUT);
  pinMode(data, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (char i = 0; i < 255; i++) {
    digitalWrite(verrou, LOW);
    envoi_ordre(data, horloge, 1, oi);
    // shiftOut(data, horloge, LSBFIRST, ~i);
    digitalWrite(verrou, HIGH);
    delay(1000);
  }
}

void envoi_ordre(int dataPin, int clockPin, boolean sens, char donnee) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(clockPin, LOW);
    if (sens) {
      digitalWrite(dataPin, donnee & 0x01 << i);
    }
    else {
      digitalWrite(dataPin, donnee & 0x80 >> i);
    }
    digitalWrite(clockPin, HIGH);
  }
}
