import processing.serial.*; 

Serial port;                            
int temp;                                 
 
void setup() { 
  size(200, 200); 
  frameRate(10); 
  port = new Serial(this, "/dev/cu.usbmodem14131", 9600); 
} 

void draw() { 
  if (0 < port.available()) {         // If data is available,
    temp = port.read();                   // read it and store it in val
  } 
  background(0, temp, 0);                       // Set background to white
} 
