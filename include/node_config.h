#define NODE_ID    4   // unique ID for this node

#define IS_SENSOR
// sensor specifics
// STATUS is for testing only - the emitter sends a bit (0,1) periodically
//#define STATUS
#define DHT11

// enable if repeater, disable if sender only
//#define IS_REPEATER

// enable the use of ESP-NOW protocol
#define USE_ESPNOW

// enable for debugging messages
#define DEBUG_ON

// gateway MAC address AA:AA:AA:AA:AA:AA - fill in your gateway MAC address
uint8_t gatewayAddress[] = {0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA};


#ifdef ESP8266
  #include <ESP8266WiFi.h>
  #include <espnow.h>
#endif
#ifdef ESP32
  #include <esp_now.h>
  #include <WiFi.h>
  #include <esp_wifi.h>
#endif