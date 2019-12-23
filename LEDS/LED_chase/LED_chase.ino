/*
  Implementing a 'LED-Chasing Game'
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
  delay(40);
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

void checkIndices() {
  Serial.print("First Index = ");
  Serial.print(value);
  Serial.print(", Second Index = ");
  Serial.println(idx);
  Serial.println((value == idx) ? "You've Won!!\n" : "You've Lost :(\n");
}

void loop() {
  checkBtn(Red);
  lightGamePixel();
  delay(4000);
  checkBtn(MediumAqua);
  checkIndices();
  lightGamePixel();
  delay(4000);
}
