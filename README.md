Externe Komponente von TCL-Klimaanlagen und Analoga für Home Assistant mit ESPHome.
TAC-07CHSA und ähnliche Klimageräte werden unterstützt. Leider ist es fast unmöglich, genau zu erraten, ob es möglich sein wird, die Klimaanlage anzuschließen oder nicht, da die Konfigurationen sehr unterschiedlich sind.
Unmöglich wegen der großen Unterschiede in den Paketen: Sogar ein und dasselbe Modell, buchstäblich Buchstabe für Buchstabe, kann z.B. kein natives WiFI-Modul haben, hat kein
ein und dasselbe Modell kann beispielsweise kein natives WiFI-Modul haben, kein Kabel mit einem USB-Anschluss haben oder es kann überhaupt kein UART-Anschluss auf der Steuerplatine eingelötet sein.
Im Allgemeinen werden jedoch, mit oder ohne Lötung, die folgenden Aufbereiter getestet:
- Axioma ASX09H1/ASB09H1
- Daichi AIR20AVQ1/AIR20FV1
- Daichi AIR25AVQS1R-1/AIR25FVS1R-1
- Daichi AIR35AVQS1R-1/AIR35FVS1R-1
- Daichi DA35EVQ1-1/DF35EV1-1
- Dantex RK-12SATI/RK-12SATIE
- TCL TAC-07CHSA/TPG-W
- TCL TAC-09CHSA/TPG
- TCL TAC-09CHSA/DSEI-W
- TCL TAC-12CHSA/TPG

Die Komponente benötigt HomeAsistant und ESPHome ab Version 2023.3.0 !
____
Dies alles funktioniert AUSSCHLIESSLICH mit HomeAsistant und ESPHome. Wenn Sie an anderen Optionen oder der Möglichkeit interessiert sind, das Klimagerät
auf andere Weise mit anderen Systemen zu verbinden, habe ich etwas anzubieten:
[Option zur Verbindung über MQTT](https://github.com/pavel211/TCL-TAC-07-WiFi)
____
Der Artikel über das Projekt ist [in meinem Zen-Kanal](https://dzen.ru/a/ZmdoyUNswXWnulhg)


Alles funktioniert, sogar stabil. Welche Pannen ich sah - beseitigt, welche Wünsche ich hatte - realisiert. Natürlich nicht alle, ich möchte ein Sportauto haben....
Wenn Sie das Bauteil jetzt benutzen, riskieren Sie Ihre geistige Gesundheit nicht, aber plötzliche Störungen können durchaus auftreten. Wenn Ihnen das passiert.
passiert, lassen Sie es mich bitte auf Zen wissen, ich werde dann etwas unternehmen.
Eine detaillierte Beschreibung wird nach und nach [in meinem Kanal auf Zen] (https://dzen.ru/a/ZmdoyUNswXWnulhg) erscheinen, hier werde ich
die wichtigsten Dinge so gut ich kann.
____
Beispiel für ESPHome-Konfiguration in der Datei TCL-Conditioner.yaml , vereinfachte Version der Konfiguration - Sample_conf.yaml . Downloaden Sie sich
und verwenden Sie sie in ESPHome, oder kopieren Sie einfach die gesamte Konfiguration und fügen Sie sie anstelle Ihrer eigenen ein, aber vergessen Sie nicht, alle Felder zu bearbeiten.
alle Felder. In der Datei gibt es Hinweise für jedes Feld.

Die Frage kann sich bei 2 Dingen stellen: Plattform (Chip oder Modul) und herunterladbare Dateien. Lassen Sie mich versuchen, das zu erklären.

## Konfigurieren der Plattform
Die Plattform wird auf die gleiche Weise konfiguriert, wie sie in ESPHome konfiguriert werden soll. So sieht zum Beispiel ein Stück Code für ESP-01S aus:
```yaml

esp8266:
  board: esp01_1m
```
Und so sieht das Codestück für das Hommyn HDN/WFN-02-01 Modul aus dem ersten Artikel über die Klimaanlage aus:
```yaml
esp32:
  board: esp32-c3-devkitm-1
  framework:
    type: arduino
```
Sie können die Plattform auch über die Hauptkonfiguration verbinden. Hier, vorgeschlagen von [alpha tester](https://github.com/kai-zer-ru), ist ein Beispiel für Esp32 WROOM32:
```yaml
esphome:
  platform: ESP32
  board: nodemcu-32s
```
Und dies ist bereits ein Beispiel für Wemos D1 Mini nodemcu esp12f:
```yaml
esphome:
  platform: ESP8266
  board: esp12e
```
Im Allgemeinen - alles wie gehabt, die Variante für Ihre Plattform finden Sie leicht im Internet.

**!Es ist wichtig, nicht zu vergessen, Strings von anderen Plattformen auszukommentieren oder zu entfernen! **!!

## Anpassen der zu ladenden Dateien
Um bestimmte Teile der Konfiguration hinzuzufügen oder zu entfernen, habe ich mich für die Verwendung von Unterdateien entschieden - sie werden von ESPHome automatisch geladen,
wenn der Home Assistant Server Internetzugang hat. Auf diese Weise kann man nicht die gesamte Konfiguration in einem Stück bearbeiten und aktualisieren,
sondern Stück für Stück, ohne das, was bereits funktioniert, anzutasten.
Ein weiterer Pluspunkt: Sie müssen keine kilometerlangen Codestücke kommentieren oder entkommentieren, Sie müssen sich nicht mit Markup auskennen, Sie müssen keine
verdammte Leerzeichen zählen und so weiter. Alles wird durch das Hinzufügen oder Entfernen von Links zu Dateien erledigt. So sieht also der Block der hochgeladenen Dateien aus:
```yaml
packages:
  remote_package:
    url: https://github.com/I-am-nightingale/tclac.git
    ref: master
    files:
    # v - равнение строк с опциями вот по этой позиции, иначе глючить будет
      - packages/core.yaml # Ядро всего сущего
      # - packages/leds.yaml
    refresh: 30s
```
Alle hochgeladenen Dateien werden im Abschnitt **Dateien:** angegeben. Um zu funktionieren, ist es notwendig, mindestens
```yaml
- packages/core.yaml # Ядро всего сущего
```
Alle anderen Module sind optional (ihre Beschreibungen stehen in der gleichen Datei wie oben). **Es ist wichtig**, dass alle Dateizeilen mit der improvisierten Markierung, die ich extra angegeben habe, übereinstimmen, sonst wird ESPHome eine Menge Fragen an Sie haben.
die improvisierte Markierung, die ich angegeben habe, sonst wird ESPHome eine Menge Fragen an Sie haben. Zum Beispiel **sollte es so aussehen:**
```yaml
packages:
  remote_package:
    url: https://github.com/I-am-nightingale/tclac.git
    ref: master
    files:
    # v - равнение строк с опциями вот по этой позиции, иначе глючить будет
      - packages/core.yaml # Ядро всего сущего
      - packages/leds.yaml
    refresh: 30s
```
Das ist nicht richtig.
```yaml
packages:
  remote_package:
    url: https://github.com/I-am-nightingale/tclac.git
    ref: master
    files:
    # v - равнение строк с опциями вот по этой позиции, иначе глючить будет
      - packages/core.yaml # Ядро всего сущего
        - packages/leds.yaml
    refresh: 30s
```
