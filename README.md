# SentinelBoard Arduino Firmware - Branch main -> versione stabile

## Board Arduino usata
Arduino Uno (o board compatibile fornita dal docente)

## Obiettivo
Firmware Arduino per acquisire dati dai sensori ambientali e inviarli al PC via comunicazione seriale.
I dati vengono letti periodicamente, formattati secondo un protocollo testuale condiviso e inviati alla dashboard Qt.

## Elenco sensori
- DHT22 — temperatura e umidità
- HC-SR04 — distanza / presenza
- PIR — rilevamento movimento
- LDR — luminosità ambiente

## Baud rate
115200

## Protocollo seriale
Ogni campione viene inviato come una riga testuale terminata da newline.

Esempio:

```text
$TEL;TIME=12345;TEMP=24.6;HUM=51.2;DIST=38.4;MOTION=1;LIGHT=420;STATUS=OK