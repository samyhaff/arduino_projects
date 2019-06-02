#include <dht11.h>

dht11 DHT;
#define DHT11_PIN 7

void setup() {
  Serial.begin(9600);
}

void loop() {
  DHT.read(DHT11_PIN);
  Serial.println("Temperature: ");
  Serial.println(DHT.temperature,1);
  Serial.write((DHT.temperature,1));
  delay(1000);
}

