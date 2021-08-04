#include <ESP8266WiFi.h>;

#include <WiFiClient.h>;

#include <ThingSpeak.h>;

const char* ssid = "PAWAR"; //Your Network SSID

const char* password = "02102007"; //Your Network Password

int val;

int buzzer = A0; //Buzzer Pin Connected at A0 Pin



WiFiClient client;

unsigned long myChannelNumber = 1247254; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "3YA9R30P778WEKRS"; //Your Write API Key

void setup()

{

Serial.begin(9600);

delay(10);

// Connect to WiFi network

WiFi.begin(ssid, password);



ThingSpeak.begin(client);

}



void loop()

{

val = analogRead(buzzer); //Read Analog values and Store in val variable

Serial.print(val); //Print on Serial Monitor

delay(1000);

ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak



delay(100);

}
