/*
Dieses Programm testet die Hardware des Würfels.
Jede Leuchtdiode wird einzeln angesteuert und der Taster wird ebenfalls überprüft
*/
  // Anschluss Button
  int button = 2;
  // Anschluss LEDs fuer Wuerfel
  int bottonRigth = 6;
  int middleRigth = 7;
  int middle = 8;
  int bottonLeft = 9;
  int middleLeft = 10;
  int upperRigth = 11;
  int upperLeft = 12;
  // Status für Button 0 = gedrueckt, 1 = gedrueckt
  int state = 0;
  
void setup() {
  /*Die Pins an denen eine LED angeschlossen ist werden als Output definiert*/
  pinMode(bottonLeft, OUTPUT);
  pinMode(bottonRigth, OUTPUT);
  pinMode(middleLeft, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(middleRigth, OUTPUT);
  pinMode(upperLeft, OUTPUT);
  pinMode(upperRigth, OUTPUT);
  
  /*Der Pin an dem der Button angeschlossen ist, wird als Input definiert*/
  pinMode(button, INPUT);
  /*oeffnet serial port, setzt Datenrate auf 9600 bps */
  Serial.begin(9600);
  
  /*Die LEDs werden nacheinander an und wieder ausgeschaltet
    links unten -> links Mitte -> links oben -> Mitte -> rechts unten -> rechts Mitte -> rechts oben */
  digitalWrite(bottonLeft, HIGH);
  delay(200);
  digitalWrite(bottonLeft, LOW);
  digitalWrite(middleLeft, HIGH);
  delay(200);
  digitalWrite(middleLeft, LOW);
  digitalWrite(upperLeft, HIGH);
  delay(200);
  digitalWrite(upperLeft, LOW);
  digitalWrite(middle, HIGH);
  delay(200);
  digitalWrite(middle, LOW);
  digitalWrite(bottonRigth, HIGH);
  delay(200);
  digitalWrite(bottonRigth, LOW);
  digitalWrite(middleRigth, HIGH);
  delay(200);
  digitalWrite(middleRigth, LOW);
  digitalWrite(upperRigth, HIGH);
  delay(200);
  digitalWrite(upperRigth, LOW);
  
}

void loop() {
  
  /*Button lesen, wenn Higth dann alle alle LEDs gleichzeitig an und wieder ausschalten*/
  if (digitalRead(button) && state == 0) {
    state = 1;
    digitalWrite(bottonLeft, HIGH);
    digitalWrite(middleLeft, HIGH);
    digitalWrite(upperLeft, HIGH);
    digitalWrite(middle, HIGH);
    digitalWrite(bottonRigth, HIGH);
    digitalWrite(middleRigth, HIGH);
    digitalWrite(upperRigth, HIGH);
    delay(400);
    digitalWrite(bottonLeft, LOW);
    digitalWrite(middleLeft, LOW);
    digitalWrite(upperLeft, LOW);
    digitalWrite(bottonRigth, LOW);
    digitalWrite(middleRigth, LOW);
    digitalWrite(upperRigth, LOW);
    digitalWrite(middle, LOW);
  }
  if (!digitalRead(button)) {
    state = 0;
    delay(100);
  }
  
}

