#include <IRremote.h>

const char pRec = 2;

IRrecv rec (pRec);

decode_results msg;

void setup()
{
 Serial.begin(9600);
 rec.enableIRIn();
 rec.blink13(true);
}

void loop()
{
  if (rec.decode(&msg))
  {
    Serial.println(msg.value,HEX);
    delay(500);
    rec.resume();
  }
  delay(1);
}
