#include <Arduino.h>

const int ledPin = 4;
unsigned long previousMillis = 0; 
const long interval = 1000;
int ledState = LOW;
unsigned long currentMillis = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    ledState = !ledState;

    digitalWrite(ledPin, ledState);
  }

}