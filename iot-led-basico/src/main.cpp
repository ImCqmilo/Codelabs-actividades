#include <Arduino.h>

#define LED 2

/**
 * Funcion que se ejecuta una vez inicie el programa
 */
void setup() {
  Serial.begin(115200);
  pinMode(LED,OUTPUT); //configuramos el pin numero 2 como salida
  digitalWrite(LED,LOW);
}

/**
 * Esta funcion es similar al main de C
 * Con la exepcion de que loop es un bucle infinito
 */
void loop() {
  Serial.println("hola mundo");
  delay(3000);
  digitalWrite(LED,HIGH);
  delay(3000); // Retardo bloqueante
  digitalWrite(LED,LOW);
}

