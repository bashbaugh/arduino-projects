
#include <Servo.h>

#define servoPin 3
#define servo2Pin 9
#define servoCenter 70
const byte leftBtn = A0;
const byte rightBtn = A1;
const byte centerBtn = A2;
const byte fireBtn = A3;
const byte led = 13;

byte loopcount = 0;
int servoVal = 70;
int targetPos = 70;
bool left, right, center, fire;

Servo servo;
Servo servoTarget;

void setup()
{
  servo.attach(servoPin);
  servoTarget.attach(servo2Pin);
  servo.write(servoVal);
  servoTarget.write(targetPos);
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
    for(int i=0; i < 2; i++)
    {
      servo.write(pos);
      delay(15);
      servo.write(pos - 20);
      delay(15);
    }
    digitalWrite(led, LOW);
    servo.write(servoVal);
  } 


  loopcount ++;
  if(loopcount > 120)
  {
    targetPos = random(0, 180);
    servoTarget.write(targetPos);
    loopcount = 0;
  }
  delay(15);
}
