/*
Dieses Programm stellt einen Wuerfel dar. Durch betaetigen des Tasters wird gewuerfelt.
Das Ergebnis wird mit Hilfe von 7 LEDs angezeigt, die in Wuerfeloptik angeordnet sind.
Beim Einschalten wird eine kleine Wuerfelanimation abgespielt.
Beim Wuerfeln wird ebenfalls eine Animation abgespielt.
*/

/*Verwendete Bibliothek*/
#include <Wuerfeln.h>


/*
 * Variablendefinition
*/

// Status für Button 0 = gedrueckt, 1 = gedrueckt
int state = 0;
// Zufallszahl fuer Wuerfelergebnis
long randNumber;
// Zufallszahl fuer Animationslaenge
long randCount;


/*Objekt erzeugen*/
Wuerfeln wuerfeln(2,6,7,8,9,10,11,12);

/*
 * Initial setup
*/
void setup() {
  //oeffnet serial port, setzt Datenrate auf 9600 bps
  Serial.begin(9600);
  //Setzt den Ausgangspunkt fuer die random Funktion
  randomSeed(analogRead(0));
  // startet die Animation
  animation();
}

/*
 * Hauptprogramm (Endlosschleife)
*/
void loop() {
  /*Button lesen, wenn Higth dann wuerfeln*/
  if (wuerfeln.buttonState() == 1 && state == 0) {
    state == 1;
    animation();
    randomNumber(4000);
  }
  if (wuerfeln.buttonState() == 0) {
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
      case 1: wuerfeln.one();
            break;
      case 2: wuerfeln.two();
            break;
      case 3: wuerfeln.three();
            break;
      case 4: wuerfeln.four();
            break;
      case 5: wuerfeln.five();
            break;
      case 6: wuerfeln.six();
            break;
    }
    delay(time);
    //Schaltet alle LEDs wieder aus
    wuerfeln.clearAll();
    delay(100);
}


/* 
 * erzeugt eine Animation von zufaelligen Wuerfelergebnissen, die hintereinander angezeigt werden
*/
void animation() {
  randCount = random(10, 25);
  for (randCount = randCount; randCount > 0; randCount--) {
    randomNumber(100);
  }
  
}
