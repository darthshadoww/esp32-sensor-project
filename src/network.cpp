#include "network.h"
#include <WiFi.h>
#include <WiFiClientSecure.h>

static WiFiClientSecure wifiClient;
PubSubClient mqttClient(wifiClient);

void setup_wifi() {
  Serial.print("Connecting to Wi-Fi: ");
  Serial.println(WIFI_SSID);
  WiFi.begin((char*)WIFI_SSID, (char*)WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250); Serial.print('.');
  }
  Serial.println("\nWi-Fi connected");
  Serial.print("IP: "); Serial.println(WiFi.localIP());
}

void reconnect_mqtt() {
  while (!mqttClient.connected()) {
    Serial.print("MQTT connecting…");
    if (mqttClient.connect("ESP32Client", MQTT_USER, MQTT_PASSWORD)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc="); Serial.print(mqttClient.state());
      Serial.println("; retrying in 5s");
      delay(5000);
    }
  }
}
