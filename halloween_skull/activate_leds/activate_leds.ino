const byte LED1 = 9;
const byte LED2 = 11;
const byte GNDPIN1 = 8;
const byte GNDPIN2 = 12;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(GNDPIN1, OUTPUT);
  pinMode(GNDPIN2, OUTPUT);
  digitalWrite(GNDPIN1, LOW);
  digitalWrite(GNDPIN2, LOW);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
}
void loop() {delay(100);}
