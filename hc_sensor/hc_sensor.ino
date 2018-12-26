/*  HC-S904 Sensor mounted on servo
 *  Add new instructions for second motor
 *  Author: John Glatts
 *  Initial code from https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
 */
#include <Servo.h>

/* Declare pins */
const int trig_pin = 10;
const int echo_pin = 8;

/* Declare variables */
long duration;
int distance;

/* Setup pins */
void setup() {
    pinMode(trig_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
    Serial.begin(9600);
}


/* Enable the LED and start the servo cycles */
void ledServo() {
    Serial.print("\n");
    Serial.print("DANGEROUS OBJECT AT : ");
    Serial.print(distance);
    Serial.print(" cm");
    Serial.print("\n");
}


/* Serial print for object at safe distance */
void harmless() {
    Serial.print("\n");
    Serial.print("HARMLESS OBJECT AT : ");
    Serial.print(distance);
    Serial.print(" cm");
    Serial.print("\n");
}


/* Determine if object is too close */
void checkDistance(int distance) {
    if (distance < 10) {
        ledServo();
    }
    else {
        harmless();
    }
}

  
// main body of program
void loop() {
    digitalWrite(trig_pin, LOW); // clear the trig_pin
    delayMicroseconds(2);

    digitalWrite(trig_pin, HIGH); // Set trig_pin on HIGH for 10 micro seconds
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
    duration = pulseIn(echo_pin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds

    // Calculate distance
    distance= duration * 0.034/2;

    checkDistance(distance);

}
