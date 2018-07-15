

#define lmF 6
#define lmR 5
#define rmF 11
#define rmR 10
#define trig 8
#define echo 7

void setup() {
  pinMode(lmF, OUTPUT);
  pinMode(lmR, OUTPUT);
  pinMode(rmF, OUTPUT);
  pinMode(rmR, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}


void motorG() {motorS(); digitalWrite(lmF, HIGH); digitalWrite(rmF, HIGH);}
void motorS() {digitalWrite(lmF, LOW); digitalWrite(rmF, LOW); digitalWrite(lmR, LOW); digitalWrite(rmR, LOW);}
void motorSL() {motorS(); digitalWrite(lmR, HIGH); digitalWrite(rmF, HIGH); delay(500);}
void motorSR() {motorS(); digitalWrite(lmF, HIGH); digitalWrite(rmR, HIGH); delay(500);}
void motorR() {motorS(); digitalWrite(lmR, HIGH); digitalWrite(rmR, HIGH); delay(500);}

float getdistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(3);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  float t  = pulseIn(echo, HIGH);
  return t*0.034/2;;
}

void loop() {
    motorG();
    if (getdistance < 10) {
      motorR();
      motorSL();
      
    }
    

    delay(50);
}
