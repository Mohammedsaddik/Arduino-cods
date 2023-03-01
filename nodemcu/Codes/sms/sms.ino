#include <ESP8266WiFi.h>
const char ssid[] = "Orange";
const char password[]="7519691am";
const char host[]= "maker.ifttt.com";
const char event[]= "sms";
const char privatekey[]= "bAHoYCQoy2GWcoyY5g0nQc";
void setup(){
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  Serial.println("connecting");
  Serial.println("."); 
  byte counter = 0;
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    counter++;
    Serial.print(".");
    Serial.println(WiFi.localIP());
}
void loop(){
  Serial.println("Connecting to host");
      WiFiClient client;
      if(!client.connect(host,80)){
        Serial.println("Connection Failed");
        delay(2000);
        return;
      }
      String url = "/trigger/";
             url = url + event + "/with/key/" + privatekey ;
      String http = "GET ";
             http = http + url + " HTTP/1.1\r\n";
             http = http + "Host: " + host +"\r\n";
             http = http + "Connection: close\r\n\r\n";
             client.print(http);
             client.stop();
             Serial.println("SMS Was Successfully Sent");
}
