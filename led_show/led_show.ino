#include <Arduino.h>

// LED pin assignments
const int LED1 = 8;
const int LED2 = 9;
const int LED3 = 10;
const int LED4 = 11;
const int LED5 = 12;



void setup() {
  // Initialize all LED pins as outputs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void allLights(int time) {
  // LED 1
  digitalWrite(LED1, HIGH);
  delay(time);
  digitalWrite(LED1, LOW);
  delay(time);
  // LED 2
  digitalWrite(LED2, HIGH);
  delay(time);
  digitalWrite(LED2, LOW);
  delay(time);
  // LED 3
  digitalWrite(LED3, HIGH);
  delay(time);
  digitalWrite(LED3, LOW);
  delay(time);
  // LED 4
  digitalWrite(LED4, HIGH);
  delay(time);
  digitalWrite(LED4, LOW);
  delay(time);
  // LED 5
  digitalWrite(LED5, HIGH);
  delay(time);
  digitalWrite(LED5, LOW);
  delay(time);

}

// Call this after declaring allLights and pin assignments:

void reverseAllLights(int time) {
  // LED 5
  digitalWrite(LED5, HIGH);
  delay(time);
  digitalWrite(LED5, LOW);
  delay(time);
  // LED 4
  digitalWrite(LED4, HIGH);
  delay(time);
  digitalWrite(LED4, LOW);
  delay(time);
  // LED 3
  digitalWrite(LED3, HIGH);
  delay(time);
  digitalWrite(LED3, LOW);
  delay(time);
  // LED 2
  digitalWrite(LED2, HIGH);
  delay(time);
  digitalWrite(LED2, LOW);
  delay(time);
  // LED 1
  digitalWrite(LED1, HIGH);
  delay(time);
  digitalWrite(LED1, LOW);
  delay(time);
}


void orderLights(int time) {
  // Turn LEDs on in sequence, then off, for 100 cycles
  digitalWrite(LED1, HIGH);
  delay(time);
  digitalWrite(LED2, HIGH);
  delay(time);
  digitalWrite(LED3, HIGH);
  delay(time);
  digitalWrite(LED4, HIGH);
  delay(time);
  digitalWrite(LED5, HIGH);
  delay(time);

  digitalWrite(LED1, LOW);
  delay(time);
  digitalWrite(LED2, LOW);
  delay(time);
  digitalWrite(LED3, LOW);
  delay(time);
  digitalWrite(LED4, LOW);
  delay(time);
  digitalWrite(LED5, LOW);
  delay(time);
  
}

void reverseOrderLights(int time) {
  // Turn LEDs on in reverse sequence 5→1
  digitalWrite(LED5, HIGH);
  delay(time);
  digitalWrite(LED4, HIGH);
  delay(time);
  digitalWrite(LED3, HIGH);
  delay(time);
  digitalWrite(LED2, HIGH);
  delay(time);
  digitalWrite(LED1, HIGH);
  delay(time);

  // Then turn them off in the same reverse sequence
  digitalWrite(LED5, LOW);
  delay(time);
  digitalWrite(LED4, LOW);
  delay(time);
  digitalWrite(LED3, LOW);
  delay(time);
  digitalWrite(LED2, LOW);
  delay(time);
  digitalWrite(LED1, LOW);
  delay(time);
}


void loop() {
  int t = 50;
  orderLights(t);
  reverseOrderLights(t);
  allLights(t);
  reverseAllLights(t);
}
