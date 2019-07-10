String nom;
void setup () {
  Serial . begin ( 9600 ) ;   
  Serial.println ( "Entrez votre nom: " ) ;

  while (nom == "") // Atendre l'entré de l'utilisateur
  {
    delay(3);
    nom = Serial.readString() ;
  }

  Serial.print ( "Vous vous appellez: " ) ;
  Serial.println(nom);

}

void loop () {
  
}
