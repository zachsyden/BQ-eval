
#include <Arduino.h>
#include <Wire.h>

// BattGuard - BQ25756 I2C Communication Test

#define SDA_PIN 21
#define SCL_PIN 22

void scanI2C() {
    Serial.println("\n----- I2C Device Scan -----");

    int devicesFound = 0;

    for (uint8_t address = 0x08; address <= 0x77; address++) {

        Wire.beginTransmission(address);
        uint8_t error = Wire.endTransmission();

        if (error == 0) {
            Serial.printf(
                "I2C Device Found at Address: 0x%02X\n",
                address
            );

            devicesFound++;
        }
    }

    if (devicesFound == 0) {
        Serial.println("No I2C devices detected.");
    }

    Serial.println("---------------------------");
}

void setup() {
    Serial.begin(115200);
    delay(1500);

    Wire.begin(SDA_PIN, SCL_PIN);
    Wire.setClock(100000);

    Serial.println("================================");
    Serial.println("      BattGuard I2C Scanner     ");
    Serial.println("================================");
    Serial.println("ESP32 I2C Initialized");
    Serial.println("SDA: GPIO21");
    Serial.println("SCL: GPIO22");
    Serial.println("Clock: 100 kHz");
}

void loop() {
    scanI2C();
    delay(3000);
}
