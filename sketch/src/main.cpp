#include <Arduino.h>

bool systemStarted = false;
String inputLine = "";
unsigned long lastSampleTime = 0;
unsigned long timeCounter = 0;

void setup() {
    Serial.begin(115200);
}

void handleCommand(const String& cmd) {
    if (cmd == "START") {
        systemStarted = true;
        timeCounter = 0;
        Serial.println("ACK_START");
    } else if (cmd == "STOP") {
        systemStarted = false;
        Serial.println("ACK_STOP");
    }
}

void loop() {
    while (Serial.available() > 0) {
        char c = (char)Serial.read();

        if (c == '\n') {
            inputLine.trim();
            if (!inputLine.length() > 0)
                handleCommand(inputLine);
            inputLine = "";
        } else {
            inputLine += c;
        }
    }

    if (systemStarted) {
        unsigned long now = millis();
        if (now - lastSampleTime >= 1000) {
            lastSampleTime = now;
            timeCounter += 1000;

            Serial.print("$TEL;TIME=");
            Serial.print(timeCounter);
            Serial.print(";TEMP=24.5;HUM=51.0;DIST=38.0;MOTION=0;LIGHT=420;STATUS=OK");
            Serial.println();
        }
    }
}