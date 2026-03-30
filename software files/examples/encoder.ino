#include "EC1101S.h"

#define TERMINAL_A 33
#define TERMINAL_B 21
#define SW         22

EC1101S encoder(TERMINAL_A, TERMINAL_B, SW);

void setup() {
  Serial.begin(115200);

  encoder.begin();

  // Set the maximum count value (optional)
  encoder.setMaxCount(100);
}

void loop() {
  // The update method must be called in every loop iteration
  encoder.update();

  // Read the current count value
  static uint8_t oldCount = 0;
  uint8_t currentCount = encoder.getCount();

  // Print only when the value changes
  if (currentCount != oldCount) {
    Serial.print("Count: ");
    Serial.println(currentCount);
    oldCount = currentCount;
  }

  // Check the button state
  if (!digitalRead(SW)) {
    Serial.println("Button pressed!");
    delay(200); // Simple debounce for the serial print
  }
}