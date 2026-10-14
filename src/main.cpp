
#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println("BattGuard ESP32 Initialized!");
}

void loop() {
    Serial.println("ESP32 Running Successfully");
    delay(2000);
}
