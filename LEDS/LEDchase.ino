#include <FastLED.h>

#define NUM_LEDS   50
#define DATA_PIN   3
#define btnOne     4
#define btnTwo     5
#define Red        CRGB::Red    
#define Black      CRGB::Black    
#define White      CRGB::White
#define Green      CRGB::Green  
#define Cyan       CRGB::LightCyan
#define MediumAqua CRGB::MediumAquamarine

CRGB leds[NUM_LEDS];

int idx = 0, value = -1, check = -1;

void setup() {
	pinMode(btnOne, INPUT_PULLUP);
	pinMode(btnTwo, INPUT_PULLUP);
	FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void lightPixel(int i, CRGB c) {
	// i != value || i != check try and do something like this 
	if (i != value) {
		leds[i] = c;
		FastLED.show();
		leds[i] = CRGB::Black;
		FastLED.show();
	}
}

void lightGamePixel(CRGB c, bool b) {
	leds[idx] = c;
	FastLED.show();
	value = idx;
	//(b == true) ? check = idx : value = idx;
}

void checkBtn(CRGB c) {
	idx = 0; // reset the iterator value
	while (digitalRead(btnOne) != LOW) {
		if (idx < NUM_LEDS) {
			lightPixel(idx, c);
			idx++;
		}
		else idx = 0;
	}
}

void shutOffPixel() {
	for (int i = 0; i < NUM_LEDS; ++i) {
		leds[i] = Black;
		FastLED.show();
	}
}

void loop() {
	checkBtn(Red);
	lightGamePixel(Green, false);
	delay(4000);
	checkBtn(MediumAqua);
	lightGamePixel(Green, true);
	delay(4000);
}