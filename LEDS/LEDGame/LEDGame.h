/*
	Library to implement some LED Games
	Uses FastLED
	Methods: 
		playGame()
			- flashes the LEDs and the player trys to stop the LED on a given pixel
		playSpeedGame() 
			- basically just toy the speed of the LEDs
		More on da way!!
*/
#ifndef LEDGame_h
#define LEDGame_h

#include "Arduino.h"
#include "FastLED.h"
#include "colors.h"

#define NUM_LEDS    50
#define DATA_PIN    3

class LEDGame {
	private: 
		int _idx = 0, _speedIdx = 0;
		int _value = -1, _speed = 300, _btnOne;
		CRGB leds[NUM_LEDS];
	public:
		LEDGame(int);
		bool checkIndices();
		void lightPixel(int, CRGB),
 			 bright(),
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
