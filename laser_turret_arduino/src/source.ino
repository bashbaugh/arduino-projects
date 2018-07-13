
#include <Servo.h>

#define servoPin 3
#define servoCenter 70
const byte leftBtn = A0;
const byte rightBtn = A1;
const byte centerBtn = A2;
const byte fireBtn = A3;
const byte led = 13;

int servoVal = 70;
bool left, right, center, fire;

Servo servo;

void setup()
{
  servo.attach(servoPin);
  servo.write(servoVal);
  pinMode(leftBtn, INPUT);
  pinMode(rightBtn, INPUT);
  pinMode(centerBtn, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  left = not digitalRead(leftBtn);
  right = not digitalRead(rightBtn);
  center = not digitalRead(centerBtn);
  fire = not digitalRead(fireBtn);
  if(left)
    servoVal ++;
  if(right)
    servoVal --;
  if(center)
    servoVal = 70;
  servoVal = constrain(servoVal, -20, 160);
  servo.write(servoVal);

  if(fire)
  {
    int pos = constrain(servoVal, -10, 150) + 10;
    digitalWrite(led, HIGH);
    for(int i=0; i < 10; i++)
    {
      servo.write(pos);
      delay(15);
      servo.write(pos - 20);
      delay(15);
    }
    digitalWrite(led, LOW);
    servo.write(servoVal);
  } 

  delay(15);
}
