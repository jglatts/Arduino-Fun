#include <LEDGame.h>

int btn = 4; // button connected to pin 4

LEDGame game(btn);  

void setup() {
  Serial.begin(9600);
  pinMode(btn, INPUT_PULLUP);
}

void loop() {
  game.playSpeedGame();
}