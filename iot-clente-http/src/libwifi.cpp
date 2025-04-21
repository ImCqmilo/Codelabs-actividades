#include <WIFI.h>
#include <libwifi.h>
void conectarWifi(const char * ssid, const char * password){
    WiFi.begin(ssid, password);
    Serial.println("Estableciendo vínculo con el AP.");
    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(1000);
    }
    Serial.println("\n\nConexion establecida");
    Serial.print("Numero IP asignado: ");
    Serial.println(WiFi.localIP()); // Imprime el número IP
}