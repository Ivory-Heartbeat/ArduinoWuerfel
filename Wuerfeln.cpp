/*
  Wuerfeln.cpp - Library zum Wuerfelergebnis anzeigen bei dem je eine LED für eine bestimmte Zahl steht.
  Erstellt von Keri Nogarth, 15.Januar 2018.
*/

#include "Arduino.h"
#include "WuerfelnLED.h"

/*Konstruktor*/
WuerfelnLED::WuerfelnLED(int button, int one, int two, int three, int four, int five, int six) {
	/*Die Pins an denen eine LED angeschlossen ist werden als Output definiert*/
	pinMode(one, OUTPUT);
	pinMode(two, OUTPUT);
	pinMode(three, OUTPUT);
	pinMode(four, OUTPUT);
	pinMode(five, OUTPUT);
	pinMode(six, OUTPUT);
	//Der Pin an dem der Button angeschlossen ist, wird als Input definiert
	pinMode(button, INPUT);
	_one = one;
	_two = two;
	_three = three;
	_four = four;
	_five = five;
	_six = six;
	_button = button;
}


/*Methopden Definition*/

/* 
 * Ueberprueft, ob der Button gedrueckt ist oder nicht
 * 
 * @return 1 wenn gedrueckt, 0 wenn nicht gedrueckt
*/
int WuerfelnLED::buttonState(){
	if(digitalRead(_button)) {
    return 1;
  } else {
    return 0;
  }
}

/* 
 * Schaltet LEDs fuer Wuerfelergebis 6 ein
*/
void WuerfelnLED::six(){
	digitalWrite(_six, HIGH);}

/*
 * Schaltet LEDs fuer Wuerfelergebis 5 ein
*/
void WuerfelnLED::five(){
	digitalWrite(_five, HIGH);
}

/*
 * Schaltet LEDs fuer Wuerfelergebis 4 ein
*/
void WuerfelnLED::four(){
	digitalWrite(_four, HIGH);
}

/*
 * Schaltet LEDs fuer Wuerfelergebis 3 ein
*/
void WuerfelnLED::three(){
	digitalWrite(_three, HIGH);
}

/*
 * Schaltet LEDs fuer Wuerfelergebis 2 ein
*/
void WuerfelnLED::two(){
	digitalWrite(_two, HIGH);
}

/*
 * Schaltet LED fuer Wuerfelergebis 1 ein
*/
void WuerfelnLED::one(){
	digitalWrite(_one, HIGH);
}


/*
 * Schaltet alle LEDs aus
*/
void WuerfelnLED::clearAll() {
  digitalWrite(_one, LOW);
  digitalWrite(_two, LOW);
  digitalWrite(_three, LOW);
  digitalWrite(_four, LOW);
  digitalWrite(_five, LOW);
  digitalWrite(_six, LOW);
}


