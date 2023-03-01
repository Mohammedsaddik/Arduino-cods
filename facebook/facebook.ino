#include <ESP8266WiFi.h>
const char ssid[] = "academia";
const char password[]="academia@#$%";
const char host[]= "maker.ifttt.com";
const char event[]= "email";
const char privatekey[]= "ojIZ2g7uEmknrz30ejJQ3mqrlDLGWKvn4uSWHEAXmYR";

void setup(){
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  Serial.println("connecting");
  Serial.println("."); 
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    Serial.println(WiFi.localIP());

  }
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
             Serial.println("your post Was Successfully posted");
}
