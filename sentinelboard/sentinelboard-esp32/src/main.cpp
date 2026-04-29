#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("SentinelBoard ESP32 avviato");
}

void loop() {
    // pacchetto test nel formato del protocollo
    Serial.println("$TEL;TIME=1000;TEMP=24.5;HUM=51.0;DIST=38.0;MOTION=0;LIGHT=420;STATUS=OK");
    delay(1000);
}