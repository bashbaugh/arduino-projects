#include <Servo.h>

Servo servo;
int pos = 90;
const int yellow = 9;
const int red = 11;
const int pir = 7;
void setup() {
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  pinMode(pir, INPUT);
  digitalWrite(pir, LOW);
  servo.attach(6);
  servo.write(pos);
  delay(10000);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
}

void play() {
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(yellow, HIGH);
  servo.write(70);
  digitalWrite(yellow, LOW);
  delay(800);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
  servo.write(100);
  delay(400);
  servo.write(110);
  delay(400);
  servo.write(90);
  for (int i=0; i<60; i++) {
    analogWrite(yellow, random(1, 224));
    analogWrite(red, random(1, 224));
    delay(25);
  }
  for (int i=0; i<4; i++) {
    pos = random(35, 145);
    servo.write(pos);
    digitalWrite(yellow, random(1, 2));
    digitalWrite(red, random(1, 2));
    delay(500);
  }
  digitalWrite(red, HIGH);
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
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  }
  delay(100);
}
