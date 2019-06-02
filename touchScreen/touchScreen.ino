void setup() {
  digitalWrite(2,LOW);
}

void loop() {
  
  pinMode(2, INPUT);
  delay(500);
  
  pinMode(2, OUTPUT);
  delay(500);
  
}

