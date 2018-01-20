/*
  Wuerfeln.h - Library zum Wuerfelergebnis anzeigen in Wuerfelbildoptik
  Erstellt von Keri Nogarth, 15.Januar 2018.
*/

#ifndef WuerfelnLED_h
#define WuerfelnLED_h

#include "Arduino.h"

class WuerfelnLED
{
	public:
		/*Methoden definition*/
		WuerfelnLED(int button, int one, int two, int three, int four, int five, int six);
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
		const int _one = 6;
		const int _two = 7;
		const int _three = 8;
		const int _four = 9;
		const int _five = 10;
		const int _six = 11;
};

#endif