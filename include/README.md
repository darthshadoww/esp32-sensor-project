# ESP32 Sensor Project

[![PlatformIO Build Status](https://github.com/darthshadoww/esp32-sensor-project/actions/workflows/ci.yml/badge.svg)](https://github.com/darthshadoww/esp32-sensor-project/actions)  
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

**A PlatformIO-based ESP32 project to read sensor data and publish via MQTT, with OTA update support.**

---

## Table of Contents

1. [Features](#features)  
2. [Prerequisites](#prerequisites)  
3. [Installation](#installation)  
4. [Configuration](#configuration)  
5. [Building & Uploading](#building--uploading)  
6. [Usage](#usage)  
7. [Project Structure](#project-structure)  
8. [Testing](#testing)  
9. [Contributing](#contributing)  
10. [License](#license)  

---

## Features

- 🔋 Reads data from attached sensors (e.g., temperature, humidity)  
- 🌐 Connects to Wi-Fi and an MQTT broker  
- 📡 Publishes sensor readings to configurable MQTT topics  
- 🔄 Supports OTA (Over-The-Air) firmware updates via PlatformIO  
- 🔧 Simple configuration via `secrets.h`, keeping credentials out of source control  

---

## Prerequisites

- ESP32 development board  
- USB cable for power and USB uploads  
- [PlatformIO Core](https://docs.platformio.org/) installed  
- An MQTT broker (public or private)  
- (Optional) CLion with PlatformIO plugin or VS Code with PlatformIO extension  

---

## Installation

1. Clone the repository  
   ```bash
   git clone https://github.com/darthshadoww/esp32-sensor-project.git
   cd esp32-sensor-project
   ```
2. If starting from an existing local folder, initialize Git and link to remote  
   ```bash
   git init
   git remote add origin https://github.com/darthshadoww/esp32-sensor-project.git
   git branch -M main
   git add .
   git commit -m "Initial commit"
   git push -u origin main
   ```

---

## Configuration

1. Copy the example secrets file  
   ```bash
   cp include/secrets.example.h include/secrets.h
   ```
2. Open `include/secrets.h` and fill in your credentials:  
   ```cpp
   #pragma once

   // Wi-Fi settings
   #define WIFI_SSID    "your_ssid"
   #define WIFI_PASS    "your_password"

   // MQTT settings
   #define MQTT_SERVER  "broker.hivemq.com"
   #define MQTT_PORT    1883
   #define MQTT_USER    "mqtt_user"
   #define MQTT_PASS    "mqtt_pass"

   // OTA update
   #define OTA_PASSWORD "ota_update_password"
   ```
3. Ensure `include/secrets.h` is listed in `.gitignore` so it never gets committed.

---

## Building & Uploading

- **USB Upload**:  
  ```bash
  pio run --environment esp32dev --target upload
  ```
- **OTA Upload**:  
  ```bash
  pio run --environment ota --target upload
  ```

---

## Usage

1. After flashing, the ESP32 connects to your Wi-Fi network.  
2. It then connects to the MQTT broker.  
3. Sensor data is published periodically to topics such as:  
   - `sensors/temperature`  
   - `sensors/humidity`  
4. To view logs, run:  
   ```bash
   pio device monitor --environment esp32dev
   ```

---

## Project Structure

```
include/
├── secrets.example.h  # Template for credentials
└── secrets.h          # Your credentials (ignored by Git)

lib/                   # Optional custom libraries

src/
├── main.cpp           # Application entry point
├── actuator.cpp/.h    # Actuator control module
├── network.cpp/.h     # Wi-Fi & MQTT module
└── sensor.cpp/.h      # Sensor reading module

test/                  # Unity-based unit tests

platformio.ini         # Build configuration
.gitignore             # Files/folders to ignore
README.md              # This file
```

---

## Testing

Run unit tests with PlatformIO’s Unity framework:  
```bash
pio test --environment esp32dev
```

---

## Contributing

1. Fork this repository.  
2. Create a branch:  
   ```bash
   git checkout -b feature/your-feature
   ```
3. Commit your changes:  
   ```bash
   git commit -m "feat: describe your feature"
   ```
4. Push and open a Pull Request.

Please follow existing code style and include tests for new functionality.

---

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
