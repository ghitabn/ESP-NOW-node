ESP-Now is a wireless communication protocol developed by Espressif Systems, primarily designed for low-power and low-latency communication between ESP8266 and ESP32 devices. It operates in the 2.4 GHz frequency range and utilizes a simple, peer-to-peer communication model, enabling devices to transmit data directly without the need for a traditional Wi-Fi network or access point. ESP-Now is well-suited for scenarios requiring quick and efficient communication, making it suitable for applications like sensor networks, home automation, and IoT devices where minimizing power consumption and latency are crucial.
Ref. https://www.espressif.com/en/solutions/low-power-solutions/esp-now

This project demonstrates sending messages from one ESP device to another over the ESP-Now protocol. 
One ESP is the “sender” and the other one is the “receiver” (generically called nodes). The receiver could act as a "repeater" as well (conditional compiling directive in node_config.h).

Data send/receive use a structure (node ID, payload and data payload type). The payload could be a sensor reading or a toggling boolean variable. Data payload types are defined in datatypes.h.
Structure definition and payload data types can be modified to send whichever variable types are suitable for a particular project.

The same code works for any node (sender, receiver or repeater) on bothe ESP8266 or ESP32 - configuration through conditional compiling directives in node_config.h. It has the following parts:

- Initialize the hardware (microcontroller board and/or sensors);
- Initialize ESP-NOW;
- Register callback functions for sending and/or receiving data;
- Add a peer device as the receiver - through its MAC address;
- Loop through which the sender reads and sens data, the receiver manipulates received data.

Files:
- node_config.h - generic configuration for the node
- node_espnow.h - ESP-NOW specific 
- node.h - node specific
- datatypes.h - payload data taypes
- main.cpp - main program
- platformio.ini - PlatformIO initialization

Tested boards:
- ESP8266 ESP-01 
- ESP8266 ESP-12E
- ESP32 DevKit v1
- M5StickC Plus (ESP32)
- M5Stack Core2 (ESP32)
