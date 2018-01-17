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
		int _button = 2;
		// Anschluss LEDs fuer Wuerfel
		int _one = 6;
		int _two = 7;
		int _three = 8;
		int _four = 9;
		int _five = 10;
		int _six = 11;
};

#endif