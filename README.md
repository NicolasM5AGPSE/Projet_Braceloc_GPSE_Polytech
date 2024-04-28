# Projet_Braceloc_GPSE_Polytech

The GitHub repository contains all the necessary documents, files, and resources to replicate the project.



## Application Mobile
Folder containing files for creating the Braceloc mobile application.

### Braceloc_App.aia
File to import into MIT App Inventor https://appinventor.mit.edu/ to modify the code.
### Braceloc_App.apk
Braceloc application software for Android.
### braceloc app screen.png
Image of the code for better visualization compared to the technical document Figure 14
### edu.mit.appinventor.ble-20230728.aix
File to import into the extensions of MIT App Inventor in order to use BluetoothLE.

# ________________________________________________________

## Braceloc_crypto
Folder containing files for the data security part.

### crypto1
Crypto 1: RSA and AES class, allowing testing of both encryption methods together.
### crypto3
Crypto 3: RSA class implementing RSA encryption and the Diffie-Hellman method.
### crypto4_AES_RSA
Crypto AES_RSA: AES class implementing AES encryption.

## Diagramme
## GPS et BLE/Code_GPS_BLE
## Lora et meshtastic
### Braceloc Firmware

### Overview

This repository hosts the device firmware for the Braceloc project, an innovative LoRa-based mesh network solution designed to enhance localization and communication capabilities in remote and challenging environments. The Braceloc firmware enables devices to maintain connectivity over extended distances with minimal power consumption, leveraging the unique properties of LoRa technology to facilitate reliable and secure communication.

### Features

- **Long Range Communication**: Utilizes LoRa technology to ensure robust communication over kilometers without the need for traditional network infrastructure.
- **Mesh Networking**: Employs a self-healing, self-configuring mesh network that increases redundancy and resilience.
- **Energy Efficiency**: Optimized for low power consumption to extend the battery life of wearable and portable devices.
- **Security**: Implements end-to-end encryption to safeguard data integrity and privacy during transmission.
- **Scalability**: Designed to seamlessly integrate a growing number of devices without significant impact on network performance.

### Getting Started

To get started with the Braceloc firmware:

1. **Clone the repository**: 
   ```bash
   git clone https://github.com/mickael458/Braceloc-mesh-.git

**Install the required libraries:**

Detailed steps to install each library are provided in the Installation section.
Configure your devices:
Follow the configuration instructions to set up your devices for your specific application needs.
Installation
Detailed instructions on setting up your development environment and installing the necessary libraries can be found in the docs directory. Ensure you have the latest version of PlatformIO and all dependent libraries installed.

Usage
To flash the firmware to your device, connect it via USB and use the following PlatformIO command:

bash
Copy code
platformio run --target upload
See the examples folder for usage scenarios and configuration examples.


## PowerPoint soutenance projet
## Répartition des taches
