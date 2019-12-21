/*
	LED Speed Control
*/
#include <FastLED.h>

#define NUM_LEDS   50
#define DATA_PIN   3
#define btnOne     4
#define Red        CRGB::Red    
#define Black      CRGB::Black    
#define White      CRGB::White
#define Green      CRGB::Green  
#define Cyan       CRGB::LightCyan
#define MediumAqua CRGB::MediumAquamarine

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

void turnOffPixel() {
	delay(speed);
	leds[i] = CRGB::Black;
	FastLED.show();
}

void lightPixel(int i, CRGB c) {
	if (i < NUM_LEDS) {
		leds[i] = c;
		FastLED.show();
		if (speed < 0) bright();
		turnOffPixel();
	}
	else index = 0;
}

void loop() {
	if (digitalRead(btnOne) != HIGH) speed -= 50;
	lightPixel(index, Cyan);
	index++;
}
