#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
int led=D0;
const char ssid[] = "academia_space";
const char password[]="password";
IPAddress serverIP(192,168,1,210);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0); 
ESP8266WebServer server(80);
char htmlPage[700] = "<!DOCTYPE html>\
<html lang=\"en\">\
<head>\
<title>IOT</title>\
<meta charset=\"utf-8\">\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\
<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css\">\
<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js\"></script>\
<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js\"></script>\
</head>\
<body>\
<div class=\"container\">\
<h2>D0</h2>\
<a href=\"?LED=ON\" class=\"btn btn-info\" role=\"button\">LED ON</a>\
<a href=\"?LED=OFF\" class=\"btn btn-info\" role=\"button\">LED OFF</a>\
</div>\
</body>\
</html>\
";
void setup(){
  pinMode(led,OUTPUT);
  WiFi.config(serverIP,gateway,subnet);
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  Serial.println("connecting");
  Serial.println("."); 
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
server.on("/",handleRoot);
server.onNotFound(handleNotFound);
server.begin();
Serial.println(".");
Serial.println("Server Started");
Serial.println(WiFi.localIP());

}

void loop(){
 
server.handleClient();
}

void handleRoot(){
  if(server.argName(0) == "LED"){
    if(server.arg(0)=="ON"){
      Serial.println("led : HIGH ");
      digitalWrite(led,HIGH);
    }
  else if(server.arg(0)=="OFF"){
    Serial.println("led : LOW ");
      digitalWrite(led,LOW);

  }}

  
  server.send(200,"text/html",htmlPage);
}


void handleNotFound(){
  server.send(404,"text/html","<h1>Page Not Found!</h1>");
}
