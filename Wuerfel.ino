/*
Dieses Programm stellt einen Wuerfel dar. Durch betaetigen des Tasters wird gewuerfelt.
Das Ergebnis wird mit Hilfe von 7 LEDs angezeigt, die in Wuerfeloptik angeordnet sind.
Beim Einschalten wird eine kleine Wuerfelanimation abgespielt.
Beim Wuerfeln wird ebenfalls eine Animation abgespielt.
*/

/*Verwendete Bibliothek*/
#include <WuerfelnLED.h>


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
WuerfelnLED wuerfelnLED(2,6,7,8,9,10,11);

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
  if (wuerfelnLED.buttonState() == 1 && state == 0) {
    state == 1;
    animation();
    randomNumber(4000);
  }
  if (wuerfelnLED.buttonState() == 0) {
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
      case 1: wuerfelnLED.one();
            break;
      case 2: wuerfelnLED.two();
            break;
      case 3: wuerfelnLED.three();
            break;
      case 4: wuerfelnLED.four();
            break;
      case 5: wuerfelnLED.five();
            break;
      case 6: wuerfelnLED.six();
            break;
    }
    delay(time);
    //Schaltet alle LEDs wieder aus
    wuerfelnLED.clearAll();
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
