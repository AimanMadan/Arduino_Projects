#include <Arduino.h>

// HC-SR04 
const int TRIG_PIN = 6;
const int ECHO_PIN = 5;

// LED pins 
const int LED_PINS[5] = { 8, 9, 10, 11, 12 };

// Distance thresholds in cm
const int thresholds[5] = { 10, 20, 40, 80, 160 };

long duration;

float distanceCm;

void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  for (int i = 0; i < 5; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }
}

void loop()
 {
  // Trigger a 10µs HIGH pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  //Measure echo pulse width
  duration = pulseIn(ECHO_PIN, HIGH);

  //Convert to centimeters (speed of sound ≈ 3485 m/s = 0.03485 cm/µs)
  distanceCm = (duration * 0.03485) / 2.0;


  //Closer more LED
  for (int i = 0; i < 5; i++) {

    if (distanceCm <= thresholds[i]) {
      digitalWrite(LED_PINS[i], HIGH);
    } 
    else {
      digitalWrite(LED_PINS[i], LOW);
    }
  }

  delay(100);  
}
