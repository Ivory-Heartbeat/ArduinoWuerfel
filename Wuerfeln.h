/*
  Wuerfeln.h - Library zum Wuerfelergebnis anzeigen in Wuerfelbildoptik
  Erstellt von Keri Nogarth, 15.Januar 2018.
*/

#ifndef Wuerfeln_h
#define Wuerfeln_h

#include "Arduino.h"

class Wuerfeln
{
	public:
		/*Methoden definition*/
		Wuerfeln(int button, int bottonRigth, int middleRigth, int middle, int bottonLeft, int middleLeft, int upperRigth, int upperLeft);
		int buttonState();
		void six();
		void five();
		void four();
		void three();
		void two();
		void one();
		void clearAll();

	private:
		/*
 		 * Variablendefinition
		*/

		// Anschluss Button
		int _button = 2;
		// Anschluss LEDs fuer Wuerfel
		int _bottonRigth = 6;
		int _middleRigth = 7;
		int _middle = 8;
		int _bottonLeft = 9;
		int _middleLeft = 10;
		int _upperRigth = 11;
		int _upperLeft = 12;
};

#endif