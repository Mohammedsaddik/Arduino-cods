#include "Ubidots.h"
#include <DHT.h>
#define DHTPIN 2     
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
float hum; 
float temp;
const char* UBIDOTS_TOKEN = "...";
const char* WIFI_SSID = "...";
const char* WIFI_PASS = "..."; 
Ubidots ubidots(UBIDOTS_TOKEN);
void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true);
  dht.begin();
}
void loop() {
  delay(5000);
  int gas = analogRead(A0);
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  unsigned long timestamp_seconds = 1571615253L;
  unsigned int timestamp_milliseconds = 0;
  ubidots.add("Temperature", temp, NULL, timestamp_seconds, timestamp_milliseconds);
  ubidots.add("Humedity", hum, NULL, timestamp_seconds, timestamp_milliseconds);
  ubidots.add("Gas", gas, NULL, timestamp_seconds, timestamp_milliseconds);
  bool bufferSent = false;
  bufferSent = ubidots.send();
  if (bufferSent) {
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.print(" Celsius");
    Serial.print("  , Gas: ");
    Serial.println(gas);    
    Serial.println("Values sent by the device");
  }
}
