#include <Wire.h>
#include <Adafruit_MotorShield.h>

 Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Motor port 2
Adafruit_DCMotor *myMotor = AFMS.getMotor(2);


void setup() {
  Serial.begin(9600);           
  AFMS.begin();   
  // 0(off) to 255(max speed)
  myMotor->setSpeed(200);
  myMotor->run(FORWARD);
  // turn on motor
  myMotor->run(RELEASE);
}

void loop() {
  uint8_t i;

  // look up run() and FORWARD in docs
  myMotor->run(FORWARD);
  for (i=0; i<255; i++) {
    myMotor->setSpeed(i);  
    delay(10);
  }
  delay(20);
  for (i=255; i!=0; i--) {
    myMotor->setSpeed(i);  
    delay(10);
  }
  delay(20);
  myMotor->run(BACKWARD);
  for (i=0; i<255; i++) {
    myMotor->setSpeed(i);  
    delay(10);
  }
  delay(20);
  for (i=255; i!=0; i--) {
    myMotor->setSpeed(i);  
    delay(10);
  }
  myMotor->run(RELEASE);
  delay(1000);

}
