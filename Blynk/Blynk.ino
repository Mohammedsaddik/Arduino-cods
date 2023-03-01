#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "fTzYEd_wY4-BSD3iDjAQhrq0N-4Rw5pw";
#define BLYNK_PRINT Serial
char ssid[] = "Orange";
char pass[] = "7519691am";
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();

}
