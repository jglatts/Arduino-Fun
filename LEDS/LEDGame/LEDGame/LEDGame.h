/*
	Library to implement some LED Games
	Uses FastLED
	Methods:
		playGame()
			- flashes the LEDs and the player trys to stop the LED on a given pixel
		playSpeedGame()
			- basically just toy the speed of the LEDs

----------------------ToDo----------------------
	- change the hard-code _numLEDS
		- make it so the user can define amount

	- overall clean-up

*/
#ifndef LEDGame_h
#define LEDGame_h

#include "Arduino.h"
#include "FastLED.h"
#include "colors.h"

#define _numLEDS    50
#define DATA_PIN    3

class LEDGame {
private:
	int _idx = 0, _speedIdx = 0;
	int _value = -1, _speed = 300, _btnOne;
	CRGB leds[_numLEDS];
public:
	LEDGame(int);
	bool checkIndices();
	void addLEDS(),
		 lightPixel(int, CRGB),
		 bright(),
		 buttonFlash(),
		 shutOffPixel(),
		 lightGamePixel(),
		 checkBtn(CRGB),
		 resetValues(),
		 playChaseGame(),
		 playSpeedGame(),
		 lightSpeedPixel(int, CRGB),
		 turnOffPixel(int);
};

#endif