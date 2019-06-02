#include <IRremote.h>

// Codes:
// ON F0C41643
// OFF FFF807
// RED FFD827
// BLUE FF8877
// GREEN FFD827
// FADE DC0197DB

IRsend irsend ;

void setup( )
{
irsend.sendRaw(F0C41643, 32); 
}

void loop( ) {
  
}

