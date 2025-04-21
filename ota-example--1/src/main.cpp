#define ESP32_RTOS  // Uncomment this line if you want to use the code with freertos only on the ESP32
                    // Has to be done before including "OTA.h"

#include "OTA.h"
#include "credentials.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");
  Serial.println("Nueva version");
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  setupOTA("ESP32-Camilo-Cardona", MI_WIFI, MI_PASS);
}

void loop() {
#ifdef defined(ESP32_RTOS) && defined(ESP32)
#else // If you do not use FreeRTOS, you have to regulary call the handle method.
  ArduinoOTA.handle();
#endif
  delay(1500);
  digitalWrite(2,HIGH);
  delay(1300);
  digitalWrite(2,LOW);
}