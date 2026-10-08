#include <Arduino.h> // Inkluderar Arduino-funktionerna

#define LED1 1 // LED 1 är kopplad till pin 1
#define LED2 3 // LED 2 är kopplad till pin 3
#define BUTTON1 2 // Knapp 1 är kopplad till pin 2
#define BUTTON2 4 // Knapp 2 är kopplad till pin 4

const int length = 2; // Antalet knappar och LED:ar

int ledList[length] = {LED1, LED2}; // Array med LED-pinnarna
int buttonList[length] = {BUTTON1, BUTTON2}; // Array med knapp-pinnarna
int buttonStateList[length] = {HIGH, HIGH}; // Array med knapparnas tillstånd

void setup() {
    Serial.begin(115200);
    for (int i; i<length; i++){
        pinMode(ledList[i],OUTPUT);
    }
  
    for (int i; i<length; i++){
        pinMode(buttonList[i],INPUT_PULLUP);
    }
}

void tandLampa(int knapp, int lampa) { // Funktion som hanterar en knapp och en LED
  int reading = digitalRead(buttonList[knapp]); // Läser av knappen

  if (reading != buttonStateList[knapp]) { // Kollar om knappens tillstånd har ändrats
    delay(50); // Väntar 50 ms för att ta bort knappens studs
    reading = digitalRead(buttonList[knapp]); // Läser av knappen igen

    if (reading != buttonStateList[knapp]) { // Kollar igen om tillståndet har ändrats
      buttonStateList[knapp] = reading; // Sparar det nya tillståndet i arrayen

      if (buttonStateList[knapp] == LOW) { // Kollar om knappen är nedtryckt
        digitalWrite(ledList[lampa], !digitalRead(ledList[lampa])); // Växlar LED:ens tillstånd
      }
    }
  }
}

void loop() { // Körs om och om igen
  tandLampa(0, 0); // Hanterar knapp 1 och LED 1
  tandLampa(1, 1); // Hanterar knapp 2 och LED 2
}