/*
 Program to blink 3 LEDs in a binary pattern
 */

const int ledpin1 = 2;
const int ledpin2 = 3;
const int ledpin3 = 4;

const int target_number = 8;

void setup() {
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
}

void loop() {
  // use binary sequence
  for (int i = 0; i < target_number; i++) {
    digitalWrite(ledpin1, i & 0x01);
    digitalWrite(ledpin2, i & 0x02);
    digitalWrite(ledpin3, i & 0x04);
    delay(500);
  }
}
