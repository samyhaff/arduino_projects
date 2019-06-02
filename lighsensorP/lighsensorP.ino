int val; 
int inputPin = A0;               
 
void setup() { 
  Serial.begin(9600);       
      
} 
 
void loop() { 
  val = analogRead(inputPin)/4;  
  Serial.write(val);         
  delay(100);                    
}
