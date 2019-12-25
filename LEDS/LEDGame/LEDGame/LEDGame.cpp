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
#include "LEDGame.h"

/**
 * LEDGame Constructor
 * @param b, the button pin
 */
LEDGame::LEDGame(int b) {
	_btnOne = b;
	FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, _numLEDS);
	//CRGB leds[_numLEDS];
}

void LEDGame::addLEDS() {
	// add this
	// goal is the client can define the number of LEDs
	// so it wont be hard-coded to 50 LEDs
}

/**
 * Light a given LED with the given color
 * @param i, the LED to light
 * @param i, the color to display
 */
void LEDGame::lightPixel(int i, CRGB c) {
	if (i != _value) {
		leds[i] = c;
		FastLED.show();
		leds[i] = Black;
		FastLED.show();
		delay(40);
	}
}

/**
 * Light the LED that the player has landed on
 */
void LEDGame::lightGamePixel() {
	leds[_idx] = Green;
	FastLED.show();
	_value = _idx;
}

/**
 * Shut off all LEDs
 */
void LEDGame::shutOffPixel() {
	for (int i = 0; i < _numLEDS; ++i) {
		leds[i] = Black;
		FastLED.show();
	}
}

/**
 * Keep flashing LEDs until the button is pressed
 * @param c, the color to display
 */
void LEDGame::checkBtn(CRGB c) {
	_idx = 0; // reset the iterator value
	while (digitalRead(_btnOne) != LOW) {
		if (_idx < _numLEDS) {
			lightPixel(_idx, c);
			_idx++;
		}
		else _idx = 0;
	}
}

/**
 * Turn on all LEDs, then wait until the button is pressed to turn them off
 */
void LEDGame::bright() {
	for (int i = 0; i < _numLEDS; ++i) {
		leds[i] = Green;
		FastLED.show();
	}
	while (digitalRead(_btnOne) != LOW) {}
	_speed = 300;
}

/**
 * Check the indices of the LEDs that the player has landed on
 * If they are equal, then they have won
 */
bool LEDGame::checkIndices() {
	Serial.print("First Index = ");
	Serial.print(_value);
	Serial.print(", Second Index = ");
	Serial.println(_idx);
	Serial.println((_value == _idx) ? "You've Won!!\n" : "You've Lost :(\n");
	return _value == _idx;
}

/**
 * Reset all iterator/counting variables
 */
void LEDGame::resetValues() {
	leds[_value] = Black;
	leds[_idx] = Black;
	FastLED.show();
	_idx = -1;
	_value = -1;
}

/**
 * Start the led chasing game
 */
void LEDGame::playChaseGame() {
	checkBtn(Red);
	lightGamePixel();
	delay(4000);
	checkBtn(MediumAqua);
	if (checkIndices()) bright();
	lightGamePixel();
	delay(4000);
	resetValues();
}

/**
 * Turn off a given pixel and delay
 * @param i, the LED to turn off
 */
void LEDGame::turnOffPixel(int i) {
	delay(_speed);
	leds[i] = CRGB::Black;
	FastLED.show();
}

/**
 * Light a given pixel and delay
 * @param i, the LED to turn on
 * @param c, the color to display
 */
void LEDGame::lightSpeedPixel(int i, CRGB c) {
	if (i < _numLEDS) {
		leds[i] = c;
		FastLED.show();
		if (_speed < 0) bright();
		turnOffPixel(i);
	}
	else _speedIdx = 0;
}

/**
 * Start the speed game
 */
void LEDGame::playSpeedGame() {
	if (digitalRead(_btnOne) != HIGH) _speed -= 75;
	lightSpeedPixel(_speedIdx, Cyan);
	_speedIdx++;
}

/**
 * Turn a LED on everytime the button is pressed
 */
void LEDGame::buttonFlash() {
	shutOffPixel();
	while (_idx != _numLEDS) {
		if (digitalRead(_btnOne) != HIGH) {
			lightGamePixel();
			delay(200);
			_idx++;
		}
	}
	_idx = 0;
}