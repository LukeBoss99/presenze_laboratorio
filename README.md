# 🚪 Sistema Presenze RFID (Arduino R4 WiFi + Google Sheets)

Un sistema IoT semplice ed efficace per la gestione degli accessi e delle presenze. Il progetto utilizza un **Arduino Mega con ESP8266** per leggere i tag RFID e invia i dati in tempo reale a un **Foglio Google**, che funge da database cloud gratuito.

## ✨ Funzionalità
- **Riconoscimento Automatico:** Associa l'ID del tag a Nome e Cognome salvati in anagrafica.
- **Registro Cloud:** Salva data, ora e generalità nel foglio "Presenze".
- **Gestione Manuale:** Pulsanti integrati nel foglio Google per:
  - Registrare nuovi utenti nell'anagrafica.
  - Segnare presenze manuali (per chi dimentica il badge).
- **Connessione Sicura:** Gestione delle richieste HTTPS verso Google Script.

## 🛠️ Hardware Necessario
- **Arduino UNO R4 WiFi**
- **Modulo RFID-RC522**
- **Tag/Card RFID** (13.56 MHz)
- Cavi Jumper (Maschio-Maschio o Maschio-Femmina)

## 🚀 Configurazione

### 1. Google Sheets & Apps Script
1. Crea un nuovo Foglio Google.
2. Crea due schede nominate esattamente: `Anagrafica` e `Presenze`.
3. Vai su **Estensioni > Apps Script** e inserisci il codice fornito per gestire le richieste `doGet` e le funzioni manuali.
4. Clicca su **Distribuisci > Nuova distribuzione**.
   - Tipo: Applicazione Web
   - Esegui come: Me
   - Chi ha accesso: **Chiunque**
5. Copia l'**URL dell'applicazione web** generato.

### 2. Arduino IDE
1. Installa le librerie: `MFRC522`
2. Apri lo sketch `.ino` fornito.
3. Inserisci il tuo `SSID` e `PASSWORD` del Wi-Fi.
4. Incolla l'ID del tuo script Google nella variabile `scriptPath`.
5. Carica il codice sulla scheda.

---
*Sviluppato con ❤️ per semplificare la gestione degli accessi.*
