/*
RST/Reset   5
SPI SS      53
SPI MOSI    51
SPI MISO    50
SPI SCK     52
*/

#include <SPI.h>
#include <RFID.h>
#include <Wire.h>
#include <ArduinoHttpClient.h>
#include "wifiWrapper.h"

//variabili di appoggio
const int pinWiFiEnable = 3;
const int pinWiFiLedEmergency = 22;

char ssid[] = "Fablab-Ivrea";  //NOME DEL WIFI
char password[] = "FABLAB01"; //PASSWORD DEL WIFI

const char server[] = "ciao.com";//"script.google.com";
char type[] = "GET";
char endpoint[] = "/macros/s/AKfycbzvN-ltJwPAGaKHFitHI4CddGfaY2vXBQ-G65g9eQA/dev?uid=888";


// Vengono definiti PIN del RFID reader
#define SDA_DIO 53  // 53 per Mega
#define RESET_DIO 5
#define delayRead 1000 // Time of delay 

RFID RC522(SDA_DIO, RESET_DIO); 

String codiceLetto;
String url;
int i;
char urlar[100] = {};

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing SPI...");
  SPI.begin();
  Serial.println("Initializing RC522...");
  RC522.init();
  
  delay(3000);
  pinMode(pinWiFiEnable, OUTPUT);
  pinMode(pinWiFiLedEmergency, OUTPUT);
  delay(200);
  Serial.println("Turning LED ON...");
  digitalWrite(pinWiFiEnable, LOW);
  digitalWrite(pinWiFiLedEmergency, HIGH);

  //CONNESSIONE AL WIFI
  wifi.connectESP(ssid, password, pinWiFiEnable, pinWiFiLedEmergency);
  delay(3000);
  digitalWrite(pinWiFiLedEmergency, LOW);
  
  
}

void loop() {
  // Controlla se c'è un nuovo tag
  if (RC522.isCard()){

    Serial.println("C'è qualcuno!");

    wifi.printWifiStatus();
  
    // Viene letto il suo codice 
    RC522.readCardSerial();
    Serial.print("Codice delle tessera letto: ");
    codiceLetto = "";
    // Viene caricato il codice della tessera, all'interno di una Stringa
    for(i = 0; i <= 4; i++){
      codiceLetto+= String (RC522.serNum[i],HEX);
      codiceLetto.toUpperCase();
    }
    Serial.println(codiceLetto);

    digitalWrite(pinWiFiEnable, HIGH);
    delay(1000);

    url = endpoint + codiceLetto;

    url.toCharArray(urlar,100);

    Serial.println(urlar);
    wifi.apiCallHTTPS(server, type, urlar, 443);
    delay(2000);
    
    
  }
  wifi.apiCallHTTPS(server, type, urlar, 443);
  wifi.printWifiStatus();
  delay(1000);
}