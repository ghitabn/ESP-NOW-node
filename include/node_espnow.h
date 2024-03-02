bool sendNodeData();

// set ESP-NOW send/receive callbacks for ESP8266 or ESP32
#ifdef ESP8266
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus)
{
    #ifdef DEBUG_ON
    Serial.println("sent: " + (String)currentDataReading.id + "," + (String)currentDataReading.type + "," + (String)currentDataReading.data);
    #endif
}
void OnDataRecv(uint8_t *mac, uint8_t *incomingData, uint8_t len)
{
#endif
#ifdef ESP32
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
{
     #ifdef DEBUG_ON
    Serial.println("sent: " + (String)currentDataReading.id + "," + (String)currentDataReading.type + "," + (String)currentDataReading.data);
    #endif
}
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
#endif
    memcpy(&currentDataReading, incomingData, sizeof(currentDataReading));
    #ifdef DEBUG_ON
    Serial.println("received: " + (String)currentDataReading.id + "," + (String)currentDataReading.type + "," + (String)currentDataReading.data);
    #endif
    #ifdef IS_REPEATER
    sendNodeData();
    #endif
}