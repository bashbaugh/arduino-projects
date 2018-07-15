const int button = 12;
const int buzzer = 8;
int bp = 0;
int c = 0;
int m = 0;

void beep() {
  for(int x = 0; x < 5; x++) {
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(200);
  }
}
void setup() {
  pinMode(button, INPUT);
  digitalWrite(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  beep();
}

void loop() {
  if (c == 10000) {
    m = bp * 60;
    for(int x = 0; x < bp; x++) {
      digitalWrite(buzzer, HIGH);
      delay(150);
      digitalWrite(buzzer, LOW);
      delay(300); 
    }
    delay(m * 1000);
    beep();
  }
  if (digitalRead(button) == LOW) {
    bp++;
    delay(300);
  }
  
  c += 20;
  delay(20);
}



