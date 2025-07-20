#pragma once
#include "secrets.h"       // now lives under include/
#include <PubSubClient.h>

extern PubSubClient mqttClient;

void setup_wifi();
void reconnect_mqtt();
