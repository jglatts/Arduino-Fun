/*
	LED Speed Control
*/
#include "colors.h"

CRGB leds[NUM_LEDS];

int speed = 300, index = 0;

void setup() {
	pinMode(btnOne, INPUT_PULLUP);
	FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void bright() {
	for (int i = 0; i < NUM_LEDS; ++i) {
		leds[i] = Green;
		FastLED.show();
	}
	while (true) {} 
}

void turnOffPixel(int i) {
	delay(speed);
	leds[i] = CRGB::Black;
	FastLED.show();
}

void lightPixel(int i, CRGB c) {
	if (i < NUM_LEDS) {
		leds[i] = c;
		FastLED.show();
		if (speed < 0) bright();
		turnOffPixel(i);
	}
	else index = 0;
}

void loop() {
	if (digitalRead(btnOne) != HIGH) speed -= 50;
	lightPixel(index, Cyan);
	index++;
}
