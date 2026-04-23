# SentinelBoard Arduino Firmware - Branch main per versione stabile

## Descrizione
Questo repository contiene il firmware Arduino per il progetto SentinelBoard,
parte del Project Work di TPSIT (4ª ITIS A. Rossi, Vicenza).

Lo sketch legge i dati da più sensori ambientali (temperatura, umidità, distanza,
movimento, luminosità), li elabora e li invia al PC tramite comunicazione seriale,
utilizzando un protocollo testuale condiviso con la dashboard Qt.

---

## Board Arduino usata
- Arduino Uno

---

## Elenco sensori

Sensori previsti per SentinelBoard:

- DHT22 — misura temperatura e umidità
- HC-SR04 — misura distanza, usato anche come rilevatore di presenza
- PIR — rileva movimento
- LDR (fotoresistore) — misura la luminosità ambiente

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
$TEL;TIME=12345;TEMP=24.6;HUM=51.2;DIST=38.4;MOTION=1;LIGHT=420;STATUS=OK

## Pin usati (DA AGGIORNARE)

## Librerie necessarie (DA AGGIORNARE)

## Come caricare lo sketch
- Collegare Arduino al PC tramite cavo USB
- Aprire Arduino IDE
- Selezionare la board corretta in Tools > Board
- Selezionare la porta corretta in Tools > Port
- Aprire  sentinelboard/sentinelboard.ino 
- Cliccare su Verify per compilare
- Cliccare su Upload per caricare lo sketch sulla board
- (Opzionale) Aprire il Serial Monitor a  115200  baud per verificare l’output