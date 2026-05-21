#include <Arduino.h>
#include <DHT.h>

#define DHTPIN   2
#define DHTTYPE  DHT22
#define LDRPIN   A0
#define LEDPIN   13

DHT dht(DHTPIN, DHTTYPE);

bool        systemActive   = false;
unsigned long lastSample   = 0;
unsigned long timeCounter  = 0;
const unsigned long INTERVAL = 2000;

void setup() {
    Serial.begin(115200);
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, LOW);
    dht.begin();
}

void loop() {
    // Leggi comandi in arrivo da Qt
    if (Serial.available()) {
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();

        if (cmd == "LED_ON") {
            systemActive = true;
            digitalWrite(LEDPIN, HIGH);
            Serial.println("ACK_LED_ON");
        }
        else if (cmd == "LED_OFF") {
            systemActive = false;
            digitalWrite(LEDPIN, LOW);
            Serial.println("ACK_LED_OFF");
        }
    }

    // Invia telemetria solo se sistema attivo
    if (systemActive) {
        unsigned long now = millis();
        if (now - lastSample >= INTERVAL) {
            lastSample    = now;
            timeCounter  += INTERVAL;

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
}