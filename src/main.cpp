#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("test");
  delay(1000);
  Serial.println("test2");
  delay(1000);
}

