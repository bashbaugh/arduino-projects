// Script to center a servo.
// Written by Benjamin A. aka scitronboy.

#include <Servo.h>
#define servopin 6
Servo servo;
void setup() {
  servo.attach(servopin);
  servo.write(0);
  delay(400);
  servo.write(90);
}
void loop() {delay(500);}
