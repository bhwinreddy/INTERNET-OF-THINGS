#include <ThingSpeak.h>
#ifdef __cplusplus
extern "C"
{
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();
#include <WiFi.h>
#include <HttpClient.h>      
#define SSID1 "Bhuvi"                                    
#define PASS "418418418"
#define CHANNEL 1183743
#define APIKEY "4RHJ9GFAC61ESIVI"
WiFiClient client;
void setup() 
{
    Serial.begin(115200);
    delay(1000);
    Serial.println("Connecting to ");
    Serial.println(SSID1);
    WiFi.begin(SSID1,PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(5000);
        Serial.print("connecting..");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    ThingSpeak.begin(client);
 
}
void loop() 
{
float t =0;
float f=0;
t = ((temprature_sens_read()-32)/1.8);
f= temprature_sens_read();               
String stringOne = String(t,2);
String stringTwo = String(f,2);
Serial.print("Temperature:");
Serial.print(t);
Serial.println("C");
Serial.println(f);     
ThingSpeak.setField(1,stringOne);
ThingSpeak.setField(2,stringTwo);
//ThingSpeak.writeField(CHANNEL,1,stringOne,APIKEY);
//ThingSpeak.setField(2,stringTwo);
ThingSpeak.writeFields(CHANNEL,APIKEY);
client.stop();
Serial.println("waiting..");
delay(15000);
}
