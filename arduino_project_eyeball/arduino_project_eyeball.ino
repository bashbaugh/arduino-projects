//arduino eyeball project

#include <Servo.h>
#define servoPin 10
#define up 100
#define down 0
Servo servo;

const byte pir = 7;
const byte led = 13;
const byte eyeLed = 12;

void setup(){
  pinMode(pir, INPUT);
  servo.attach(servoPin);
  pinMode(led, OUTPUT);
  pinMode(eyeLed, OUTPUT);
  digitalWrite(led, HIGH);
  servo.write(up);
  delay(15000);
  digitalWrite(led, LOW);
}

void loop() {
  servo.write(up);
  if (digitalRead(pir) == HIGH) {
    servo.write(down);
    delay(500);
    servo.write(20);
    delay(500);
    servo.write(down);
    delay(2000);
    servo.write(up);
    dealy(2000);
  }
  delay(50);
}
