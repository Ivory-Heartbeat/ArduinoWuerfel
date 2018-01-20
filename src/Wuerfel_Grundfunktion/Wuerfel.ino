/*
Dieses Programm stellt einen Wuerfel dar. Durch betaetigen des Tasters wird gewuerfelt.
Das Ergebnis wird mit Hilfe von 7 LEDs angezeigt, die in Wuerfeloptik angeordnet sind.
*/


/*
 * Variablendefinition
*/
// Anschluss Button
  const int button = 2;
  // Anschluss LEDs fuer Wuerfel
  const int bottonRigth = 6;
  const int middleRigth = 7;
  const int middle = 8;
  const int bottonLeft = 9;
  const int middleLeft = 10;
  const int upperRigth = 11;
  const int upperLeft = 12;
// Status für Button 0 = gedrueckt, 1 = gedrueckt
int state = 0;
// Zufallszahl fuer Wuerfelergebnis
long randNumber;


/*
 * Initial setup
*/
void setup() {
  /*Die Pins an denen eine LED angeschlossen ist werden als Output definiert*/
  pinMode(bottonLeft, OUTPUT);
  pinMode(bottonRigth, OUTPUT);
  pinMode(middleLeft, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(middleRigth, OUTPUT);
  pinMode(upperLeft, OUTPUT);
  pinMode(upperRigth, OUTPUT);
  //Der Pin an dem der Button angeschlossen ist, wird als Input definiert
  pinMode(button, INPUT);
  //oeffnet serial port, setzt Datenrate auf 9600 bps
  Serial.begin(9600);
  //Setzt den Ausgangspunkt fuer die random Funktion 
  randomSeed(analogRead(0));
}

/*
 * Hauptprogramm (Endlosschleife)
*/
void loop() {
  /*Button lesen, wenn Higth dann wuerfeln*/
  if (buttonState() == 1 && state == 0) {
    state == 1;
    randomNumber(4000);
  }
  if (buttonState() == 0) {
    state == 0;
    delay(100);
  }
}


/* 
 * erzeugt eine zufallszahl zwischen 1 und 6 und ruft die entsprechene Funktion auf
 *
 * @par time Zeit die nach dem Anzeigen einer Zahl gewartet wird in Millisekunden
*/
void randomNumber(int time) {
  randNumber = random(1, 7);
    delay(100);
    // gibt die Zufallszahl an einem angeschlossenen Bildschirm aus (falls vorhanden)
    Serial.println(randNumber);
    
    /*Je nach Zufallszahl, wird das entsprechende Wuerfelbild aufgerufen*/
    switch(randNumber) {
      case 1: one();
            break;
      case 2: two();
            break;
      case 3: three();
            break;
      case 4: four();
            break;
      case 5: five();
            break;
      case 6: six();
            break;
    }
    delay(time);
    //Schaltet alle LEDs wieder aus
    clearAll();
    delay(100);
}

/* 
 * Ueberprueft, ob der Button gedrueckt ist oder nicht
 * 
 * @return 1 wenn gedrueckt, 0 wenn nicht gedrueckt
*/
int buttonState(){
  if(digitalRead(button)) {
    return 1;
  } else {
    return 0;
  }
}

/* 
 * Schaltet LEDs fuer Wuerfelergebis 6 ein
*/
void six() {
  digitalWrite(bottonLeft, HIGH);
  digitalWrite(middleLeft, HIGH);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(bottonRigth, HIGH);
  digitalWrite(middleRigth, HIGH);
  digitalWrite(upperRigth, HIGH);
}
/*
 * Schaltet LEDs fuer Wuerfelergebis 5 ein
*/
void five() {
  digitalWrite(bottonLeft, HIGH);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(bottonRigth, HIGH);
  digitalWrite(upperRigth, HIGH);
  digitalWrite(middle, HIGH);
}

/*
 * Schaltet LEDs fuer Wuerfelergebis 4 ein
*/
void four() {
  digitalWrite(bottonLeft, HIGH);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(bottonRigth, HIGH);
  digitalWrite(upperRigth, HIGH);
}

/*
 * Schaltet LEDs fuer Wuerfelergebis 3 ein
*/
void three() {
  digitalWrite(bottonLeft, HIGH);
  digitalWrite(middle, HIGH);
  digitalWrite(upperRigth, HIGH);
}

/*
 * Schaltet LEDs fuer Wuerfelergebis 2 ein
*/
void two() {
  digitalWrite(bottonLeft, HIGH);
  digitalWrite(upperRigth, HIGH);
}

/*
 * Schaltet LED fuer Wuerfelergebis 1 ein
*/
void one() {
  digitalWrite(middle, HIGH);
}


/*
 * Schaltet alle LEDs aus
*/
void clearAll() {
  digitalWrite(bottonLeft, LOW);
  digitalWrite(middleLeft, LOW);
  digitalWrite(upperLeft, LOW);
  digitalWrite(bottonRigth, LOW);
  digitalWrite(middleRigth, LOW);
  digitalWrite(upperRigth, LOW);
  digitalWrite(middle, LOW);
}