int out = 7;
int in = 6;
int buzzer = 5;
int bouton = 4;
int rouge = 3;
int vert = 8;
float d;
long pot = A5;
long val;
long seuil;
int state = '1';

void setup() {
  pinMode(out, OUTPUT);
  pinMode(in, INPUT);
  pinMode(bouton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    state = Serial.read();
  }

  if (state == '1') {
    
    digitalWrite(out, LOW);
    delayMicroseconds(2);
    digitalWrite(out, HIGH);
    delayMicroseconds(10);
    digitalWrite(out, LOW);
  
    val = analogRead(pot);
    seuil = map(val, 0, 1023, 10, 200);
    Serial.write(seuil);
    d = pulseIn(in, HIGH) / 58.0; //distance en cm
    delay(200);
    digitalWrite(rouge, LOW);
  
    if (d < seuil) {
      for(int note = 700; note < 2000; note++) {
        tone(buzzer, note, 125);
      digitalWrite(rouge, HIGH);
      digitalWrite(vert, LOW);
      }
    }
    else {
      digitalWrite(vert, HIGH);
    }
  }
}
