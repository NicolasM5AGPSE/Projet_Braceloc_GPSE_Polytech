# Projet_Braceloc_GPSE_Polytech

The GitHub repository contains all the necessary documents, files, and resources to replicate the project.

# Introduction
This project embodies a fusion of technology and practicality to ensure safety and connectivity for individuals in various outdoor scenarios, such as hiking in remote areas, school outings, or even leisure activities like mushroom foraging in dense forests.

These bracelets, when paired, allow users within a group to share and track each other's locations in real-time, even in the most challenging environments where traditional network signals fail.

Braceloc leverages state-of-the-art GPS technology embedded in wearable bracelets. Our vision is to provide peace of mind and enhance safety for our users, enabling them to locate their friends, family, or any group member instantly over considerable distances.


# Description of each folder

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
RSA and AES class, allowing testing of both encryption methods together.
### crypto3
RSA class implementing RSA encryption and the Diffie-Hellman method.
### crypto4_AES_RSA
AES class implementing AES encryption.

# ________________________________________________________

## Diagramme
File containing all the diagrams of the project.

# ________________________________________________________

## GPS et BLE/Code_GPS_BLE
This folder contains the code for BLE and GPS on the Arduino IDE. The code is fully commented in English.

# ________________________________________________________

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

# ________________________________________________________

## PowerPoint soutenance projet
Folder including project presentation slides.

# ________________________________________________________

## Répartition des taches
Folder containing the task distribution for each group member.

# ________________________________________________________

## Software and Libraries Used.txt
List of software and libraries used during the project.

# ________________________________________________________

## bibliographie.txt
List of useful documents for the project.
