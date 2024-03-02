#include <Arduino.h>
#include <node_config.h>
#include <node.h>
#include <datatypes.h>

#ifdef IS_SENSOR
// sensor specific
#include <DHT.h>

#ifdef DHT11
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#endif // DHT11
#endif // IS_SENSOR

void setup() {
  beginNode();
  #ifdef IS_SENSOR
  // sensor specific initializations
  currentDataReading.id = NODE_ID;
  
  #ifdef STATUS
  currentDataReading.data = 0;
  currentDataReading.type = STATUS_T;
  #endif // STATUS

  #ifdef DHT11
  pinMode(DHTPIN,INPUT);
  dht.begin();
  #endif // DHT11
  #endif // IS_SENSOR
  }
 
void loop() {
  #ifdef IS_SENSOR
  // sensor specific actions
  #ifdef STATUS
  currentDataReading.data = 1 - currentDataReading.data;
  #endif // STATUS

  #ifdef DHT11
  currentDataReading.data = dht.readTemperature();
  if (!isnan(currentDataReading.data))
  {
    currentDataReading.type = TEMP_T;
    sendNodeData();
    delay(500);
  }
  currentDataReading.data = dht.readHumidity();
  if (!isnan(currentDataReading.data))
  {
    currentDataReading.type = HUMIDITY_T;
    sendNodeData();
  }
  #endif // DHT11
  
  delay(2000);
  #endif // iS_SENSOR
}