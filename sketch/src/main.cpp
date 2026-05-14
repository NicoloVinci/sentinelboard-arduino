#include <Arduino.h>      // obbligatorio in PlatformIO
#include <DHT.h>

#define DHTPIN    2
#define DHTTYPE   DHT22
#define LDRPIN    A0

DHT dht(DHTPIN, DHTTYPE);

unsigned long sampleInterval = 2000;
unsigned long lastSample     = 0;
unsigned long timeCounter    = 0;

void setup() {
    Serial.begin(115200);
    dht.begin();
}

void loop() {
    unsigned long now = millis();

    if (now - lastSample >= sampleInterval) {
        lastSample   = now;
        timeCounter += sampleInterval;

        float  temp  = dht.readTemperature();
        float  hum   = dht.readHumidity();
        int    light = analogRead(LDRPIN);

        String status = "OK";
        if (isnan(temp) || isnan(hum)) {
            status = "ERR";
            temp = 0.0;
            hum  = 0.0;
        }

        Serial.print("$TEL;TIME=");
        Serial.print(timeCounter);
        Serial.print(";TEMP=");
        Serial.print(temp, 1);
        Serial.print(";HUM=");
        Serial.print(hum, 1);
        Serial.print(";LIGHT=");
        Serial.print(light);
        Serial.print(";STATUS=");
        Serial.println(status);
    }
}