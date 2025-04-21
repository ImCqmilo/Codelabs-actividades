#include <Arduino.h>
#include "libwifi.h"
#include <WiFi.h>

#define LED 2

const char * ssid = "TIGO-409F";
const char * password = "4NJ567300800";
const char * host = "codelab.denkitronik.com";
const int port = 80;


void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Iniciando cliente http");
  conectarWifi(ssid, password);

}

void loop() {
  WiFiClient cliente;
  if (!cliente.connect(host, port)) {
    delay(2000);
    return;
  }
  cliente.print("GET thingname/uceva230212009?presion=1013&altitud=300&temperatura=44.2 HTTP/1.1\r\nHost: " + String(host) + "\r\nConnetion: close\r\n\r\n");// el HTTP/1.1 es la version del protocolo

  //Agregamos un tiempo de espera para recibir los primeros caracteres enviados por el servidor
  unsigned long timeout = millis();
  while (cliente.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println("Tiempo de espera agotado");
      cliente.stop();
    }
  }

  while (cliente.available()) {
    String line = cliente.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println("Finando conexion");
  cliente.stop();
  delay(3000);

}

