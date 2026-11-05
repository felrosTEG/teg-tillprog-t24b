/*
En grön lysdiod sitter på pinne 7 och en knapp sitter på pinne 11. Knappen är kopplad till GND, så ställ in den med INPUT_PULLUP. Då ger digitalRead värdet LOW när knappen är nedtryckt.

Skriv ett program som fungerar som en trappbelysning.

Krav:

Lysdioden är släckt när programmet startar.
När knappen trycks ned tänds lysdioden.
Lysdioden lyser i 3 sekunder och släcks sedan av sig själv, även om knappen släpps direkt.
Efter det går det att tända lysdioden igen med knappen.

*/


#include <Arduino.h>

const int ledPin = 7;
const int knappPin = 11;

bool ledState = LOW;              // Håller koll på om lysdioden är tänd
unsigned long startTid = 0;         // Tidpunkt (ms) då lysdioden tändes
const unsigned long lystid = 3000;  // Lystid i millisekunder (3 sekunder)

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // LED är släckt från början
  pinMode(knappPin, INPUT_PULLUP);
}

void loop() {
  // 1. Om knappen trycks ned (LOW) och lysdioden inte redan är tänd
  if (digitalRead(knappPin) == LOW && ledState != LOW) {
    
    // Debouncer
    delay(50); 

    // Kontrollera igen att knappen faktiskt fortfarande är nedtryckt
    if (digitalRead(knappPin) == LOW) {
      digitalWrite(ledPin, HIGH); // Tänd LED
      ledState = HIGH;             // Markera att lysdioden är tänd
      startTid = millis();        // Spara starttiden för timern
    }
  }

  // 2. Timern: Kontrollera med millis() om 3 sekunder har passerat
  if (ledState == HIGH && (millis() - startTid >= lystid)) {
    digitalWrite(ledPin, LOW);  // Släck LED
    ledState = LOW;            // Återställ så knappen kan tända den igen
  }
}
