# SentinelBoard Arduino Firmware - Branch main per versione stabile

## Descrizione
Questo repository contiene il firmware Arduino per il progetto SentinelBoard,
parte del Project Work di TPSIT (4ª ITIS A. Rossi, Vicenza).

Lo sketch legge i dati da più sensori ambientali (temperatura, umidità, luminosità), li elabora e li invia al PC tramite comunicazione seriale, utilizzando un protocollo testuale condiviso con la dashboard Qt.

---

## Board Arduino usata
- Arduino

---

## Elenco sensori

Sensori previsti per SentinelBoard:

- 1 DHT22 — misura temperatura e umidità
- 2 Mini Panneelli fotovoltaici
- 1 Condensatore 25v ,2200uF
- 2 batterie 7.4V
- Tp5100
- 2S 20A BMS
- 2 Servo motori
- 4 LDR (fotoresistore) — misura la luminosità ambiente

Componenti di supporto:

- Breadboard
- Jumper maschio-maschio
- Resistenze (per LDR e pull‑up/pull‑down se necessari)
- Cavo USB per collegare Arduino al PC

---

## Baud rate
La comunicazione seriale con il PC avviene a:

- 115200 baud

```cpp
void setup() {
    Serial.begin(115200);
    // inizializzazione sensori...
}

## Formato protocollo seriale
$TEL;TIME=12345;TEMP=24.6;HUM=51.2;LIGHT=420;STATUS=OK

## Pin usati (DA AGGIORNARE)

## Librerie necessarie
DHT sensor library, Adafruit Unified Sensor, Servo.h

## Come caricare lo sketch
1.	Collegare l’Arduino via USB
2.	Aprire il progetto in CLion
3.	Selezionare l’environment giusto in  platformio.ini  (Arduino)
4.	Fare Upload del firmware
In alternativa, da terminale, posizionarsi nel path dello sketch, digitare 'pio run -t upload' e premere Invio.
Per attivare il monitor seriale da terminale, posizionarsi nel path dello sketch, digitare 'pio device monitor -b 115200' e premere Invio.