#include <WiFi.h>
#include "ThingSpeak.h"


//Channel and API keys
#define CHANNEL 1196279 
const char *WRITE_API = "JZDMB1NE9I3K9GSK";

//WiFi Details
#define SSID "Bhuvi"
#define Password "418418418"
#define WIFI_TIMEOUT_MS 2000
WiFiClient client;


#ifdef __cplusplus
extern "C"
{
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();



//Function for WiFi
void connecToWiFI(){
  Serial.print("Connecting to WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID,Password);

  unsigned long startAttemptTime = millis();

  while(WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS){
    Serial.print(".");
    delay(100);
  }

  if(WiFi.status() != WL_CONNECTED){
    Serial.println("Failed");
  }
  else{
    Serial.print("Connected");
    Serial.println(WiFi.localIP());
  }
}





void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  connecToWiFI();              //Calling WiFi function
  ThingSpeak.begin(client);    //Calling Client
}



void loop() {
  // put your main code here, to run repeatedly:
  float t = 0;
  t = ((temprature_sens_read()-32)/1.8);
  String st = String(t,2);
  Serial.print(st);
  ThingSpeak.writeField(CHANNEL,1,t,WRITE_API);
  delay(15000);
}
