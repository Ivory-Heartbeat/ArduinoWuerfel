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
		const int _button = 2;
		// Anschluss LEDs fuer Wuerfel
		const int _bottonRigth = 6;
		const int _middleRigth = 7;
		const int _middle = 8;
		const int _bottonLeft = 9;
		const int _middleLeft = 10;
		const int _upperRigth = 11;
		const int _upperLeft = 12;
};

#endif