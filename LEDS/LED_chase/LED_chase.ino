/*
  Implementing a 'LED-Chasing Game'
  LEDS a little dim but it's looking nice
  -------BUG-------
  - when light is switching from white -> red, it looses the green color
*/
#include "colors.h"

CRGB leds[NUM_LEDS];

int idx = 0, value = -1;

void setup() {
  Serial.begin(9600);
  pinMode(btnOne, INPUT_PULLUP);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void lightPixel(int i, CRGB c) {
  if (i != value) {
    leds[i] = c;
    FastLED.show();
    leds[i] = Black;
    FastLED.show();
  }
}

void lightGamePixel() {
  leds[idx] = Green;
  FastLED.show();
  value = idx;
}

void shutOffPixel() {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = Black;
    FastLED.show();
  }
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

void bright() {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = Green;
    FastLED.show();
  }
  while (digitalRead(btnOne) != LOW) {}
}

void loop() {
  checkBtn(Red);
  lightGamePixel();
  delay(4000);
  checkBtn(MediumAqua);
  Serial.println((value == idx) ? "You've Won!!" : "You've Lost :(");
  lightGamePixel();
  delay(4000);
}
