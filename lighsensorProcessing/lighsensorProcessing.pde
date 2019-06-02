import processing.serial.*; 
 
Serial port;  // Create object from Serial class
int val;      // Data received from the serial port 
 
void setup() { 
  size(200, 200); 
  noStroke(); 
  frameRate(10);  // Run 10 frames per second
  // Open the port that the board is connected to and use the same speed (9600 bps) 
  port = new Serial(this, "/dev/cu.usbmodem14131", 9600); 
} 

void draw() { 
  if (0 < port.available()) {  
    val = port.read();
    println(val);
  } 
  background(204);                
  fill(val);                      
  rect(50, 50, 100, 100);        
} 
