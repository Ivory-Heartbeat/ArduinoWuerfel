/*
  Wuerfeln.cpp - Library zum Wuerfelergebnis anzeigen in Wuerfelbildoptik.
  Erstellt von Keri Nogarth, 15.Januar 2018.
*/

#include "Arduino.h"
#include "Wuerfeln.h"

/*Konstruktor*/
Wuerfeln::Wuerfeln(int button, int bottonRigth, int middleRigth, int middle, int bottonLeft, int middleLeft, int upperRigth, int upperLeft) {
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
	_bottonRigth = bottonRigth;
	_middleRigth = middleRigth;
	_middle = middle;
	_bottonLeft = bottonLeft;
	_middleLeft = middleLeft;
	_upperRigth = upperRigth;
	_upperLeft = upperLeft;
	_button = button;
}


/*Methopden Definition*/

/* 
 * Ueberprueft, ob der Button gedrueckt ist oder nicht
 * 
 * @return 1 wenn gedrueckt, 0 wenn nicht gedrueckt
*/
int Wuerfeln::buttonState(){
	if(digitalRead(_button)) {
    return 1;
  } else {
    return 0;
  }
}

/* 
 * Schaltet LEDs fuer Wuerfelergebis 6 ein
*/
void Wuerfeln::six(){
	digitalWrite(_bottonLeft, HIGH);
	digitalWrite(_middleLeft, HIGH);
	digitalWrite(_upperLeft, HIGH);
	digitalWrite(_bottonRigth, HIGH);
	digitalWrite(_middleRigth, HIGH);
	digitalWrite(_upperRigth, HIGH);
}

/*
 * Schaltet LEDs fuer Wuerfelergebis 5 ein
*/
void Wuerfeln::five(){
	digitalWrite(_bottonLeft, HIGH);
	digitalWrite(_upperLeft, HIGH);
	digitalWrite(_middle, HIGH);
	digitalWrite(_bottonRigth, HIGH);
	digitalWrite(_upperRigth, HIGH);
}

/*
 * Schaltet LEDs fuer Wuerfelergebis 4 ein
*/
void Wuerfeln::four(){
	digitalWrite(_bottonLeft, HIGH);
	digitalWrite(_upperLeft, HIGH);
	digitalWrite(_bottonRigth, HIGH);
	digitalWrite(_upperRigth, HIGH);
}

/*
 * Schaltet LEDs fuer Wuerfelergebis 3 ein
*/
void Wuerfeln::three(){
	digitalWrite(_bottonLeft, HIGH);
	digitalWrite(_middle, HIGH);
	digitalWrite(_upperRigth, HIGH);
}

/*
 * Schaltet LEDs fuer Wuerfelergebis 2 ein
*/
void Wuerfeln::two(){
	digitalWrite(_bottonLeft, HIGH);
	digitalWrite(_upperRigth, HIGH);
}

/*
 * Schaltet LED fuer Wuerfelergebis 1 ein
*/
void Wuerfeln::one(){
	digitalWrite(_middle, HIGH);
}


/*
 * Schaltet alle LEDs aus
*/
void Wuerfeln::clearAll() {
  digitalWrite(_bottonLeft, LOW);
  digitalWrite(_middleLeft, LOW);
  digitalWrite(_upperLeft, LOW);
  digitalWrite(_bottonRigth, LOW);
  digitalWrite(_middleRigth, LOW);
  digitalWrite(_upperRigth, LOW);
  digitalWrite(_middle, LOW);
}


