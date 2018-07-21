const byte enbAddOut = 4;
const byte enbSubtractOut = 5;
const byte S1 = 9;
const byte S2 = 10;
const byte cap1 = 7;
const byte cap2 = 6;
const byte resultIn = A0;

int switchDelay = 220;

void setup()
{
  pinMode(enbAddOut, OUTPUT);
  pinMode(enbSubtractOut, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(cap1, OUTPUT);
  pinMode(cap2, OUTPUT);
  pinMode(resultIn, INPUT);
}

void loop()
{
  pinMode(S2, INPUT);
  pinMode(S1, OUTPUT);
  digitalWrite(S1, LOW);
  delayMicroseconds(switchDelay);
  pinMode(S1, INPUT);
  pinMode(S2, OUTPUT);
  digitalWrite(S2, LOW);
  delayMicroseconds(switchDelay);
}
