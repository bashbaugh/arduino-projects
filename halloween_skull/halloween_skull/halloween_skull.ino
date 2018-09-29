// Motion-sensing Halloween skull code
// Written by Benjamin A., aka scitronboy

#include <Servo.h>
#define servoPin 6

Servo servo; // create servo class
int pos = 90; // servo position
// define pins
const byte LED1 = 9;
const byte LED2 = 11;
const byte GNDPIN1 = 8;
const byte GNDPIN2 = 12;
const byte pir = 7;
void setup() {
  // Setup pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(GNDPIN1, OUTPUT);
  pinMode(GNDPIN2, OUTPUT);
  digitalWrite(GNDPIN1, LOW);
  digitalWrite(GNDPIN2, LOW);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  pinMode(pir, INPUT);
  //digitalWrite(pir, LOW);
  servo.attach(servoPin);
  servo.write(pos);
  delay(10000); // wait 10 seconds for the PIR to adjust to it's surroundings.
  // flash one LED, to signal that the program is starting
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
}

void play() { // This function runs every time movement is detected.
  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED1, HIGH);
  servo.write(70);
  digitalWrite(LED1, LOW);
  delay(800);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  servo.write(100);
  delay(400);
  servo.write(110);
  delay(400);
  servo.write(90);
  for (int i=0; i<60; i++) {
    analogWrite(LED1, random(1, 224));
    analogWrite(LED2, random(1, 224));
    delay(25);
  }
  for (int i=0; i<4; i++) {
    pos = random(35, 145);
    servo.write(pos);
    digitalWrite(LED1, random(1, 2));
    digitalWrite(LED2, random(1, 2));
    delay(500);
  }
  digitalWrite(LED2, HIGH);
  delay(1000);
}

void loop() {
  if (digitalRead(pir) == HIGH) {
    play();
  } else {
    if (pos != 90) {
      pos = 90;
//      servo.write(pos);
//      for (int i=0; i < 30; i++) {
//        servo.write(88);
//        delay(15);
//        servo.write(92);
//        delay(15);
//      }
      servo.write(pos);
      delay(30);
    }
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  }
  delay(100);
}
