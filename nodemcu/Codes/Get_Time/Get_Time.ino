#include<ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
char ssid[] = "academia";
char pass[] = "academia500";
WiFiUDP udp;
NTPClient timeClient(udp,"time.nist.gov",7200);
void setup(){
  Serial.begin(115200);
  Serial.println("connecting");
  Serial.print(".");
  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println(" ");
  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());
  timeClient.begin();
  delay(1000);
}

void loop(){
  timeClient.update();
  Serial.println("Current time is : ");
  Serial.println(timeClient.getFormattedTime());
  delay(1000);
}
