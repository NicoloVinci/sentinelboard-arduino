#include <Arduino.h>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    delay(1000);
    Serial.println("SentinelBoard Arduino UNO avviato");
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

    Serial.println("$TEL;TIME=1000;TEMP=24.5;HUM=51.0;DIST=38.0;MOTION=0;LIGHT=420;STATUS=OK");
    delay(1000);
}