#define pir 8
#define led 13

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
}

void loop() {
  int ps = digitalRead(pir);
  if (ps == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  delay(20);
}
