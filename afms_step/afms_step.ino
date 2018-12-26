/* 
Sketch using the 57HD5401-14S stepper motor and Adafruit motor shield
*/
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#define GROUPSIZE 6 

Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 
// add limit sensors/switches


// Connect a stepper motor with 200 steps per revolution (1.8 degree)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);


void setup() {
  Serial.begin(9600);           
  AFMS.begin();   
  myMotor->setSpeed(9000);  // shit_ton rpm   
}


/* Pre-Group Leaders */
void pre_group() {
  Serial.println("\nSpinning Leaders\n");
  myMotor->step(800, FORWARD, DOUBLE); 
  delay(5000);
}


/* Grouped Wires */
void group() {
  Serial.println("\nSpinning Group\n");
  myMotor->step(1600, FORWARD, DOUBLE); 
  delay(5000);
}


/* Cut Gap */
void cut_gap() {
  Serial.println("\nCUT GAP\n");
  myMotor->step(100, FORWARD, MICROSTEP); 
  delay(5000);
}


/* Final Leaders */
void post_group() {
  Serial.println("\nSpinning Final Leaders\n");
  myMotor->step(800, FORWARD, DOUBLE); 
  delay(25000); 
}


void loop() {
 /*
  for (int x = 0; x < GROUPSIZE; ++x) {
      if (x == 0) {
          pre_group();
          delay(5000); 
      } 
      else if (x == (GROUPSIZE - 1)) {
          post_group();
          delay(25000); 
      }
      else {
          group();     
          delay(5000);
          cut_gap();     
          delay(5000);
      }
  }
 */
  myMotor->step(800, FORWARD, DOUBLE); 
  delay(50000); 
  myMotor->step(150, FORWARD, MICROSTEP); 
  delay(50000);
}
