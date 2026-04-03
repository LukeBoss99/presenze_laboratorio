# Nome del Progetto

Una breve descrizione di una riga che spiega cosa fa questo progetto o qual è il suo scopo principale.

## 📂 Struttura del Repository

In questa sezione viene descritto il contenuto e la funzione di ogni file presente nel repository per facilitarne la comprensione a collaboratori e utenti.

| File / Cartella | Descrizione |
| :--- | :--- |
| `arduino_presenze` | Cartella che contiene il progetto. |
| `arduino_presenze.ino` | File da caricare su Arduino |
| `wifiWrapper.h`,`wifiWrapper_WiFi.cpp` | Libreria per utilizzare un esp8266 con un Arduino Mega |

---

## 🛠️ Descrizione Dettagliata dei File

### 🔹 Logica Principale
* Il codice che viene caricato sull'Arduino legge il tag RFID
* Il codice del tag, tramite ESP8266 che lancia un'API di google script, viene salvato su una tabella excel

---
