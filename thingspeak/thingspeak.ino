#include <ESP8266WiFi.h>;

#include <WiFiClient.h>;

#include <ThingSpeak.h>;

const char* ssid = "goddamnnoob97"; //Your Network SSID

const char* password = "123456789"; //Your Network Password

int val;

int LDRpin = A0; //LDR Pin Connected at A0 Pin



WiFiClient client;

unsigned long myChannelNumber = 801927; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "2U884GR5G8VWSEN1"; //Your Write API Key

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

val = analogRead(LDRpin); //Read Analog values and Store in val variable

Serial.print(val); //Print on Serial Monitor

delay(1000);

ThingSpeak.writeField(myChannelNumber, 2,val, myWriteAPIKey); 

ThingSpeak.writeField(myChannelNumber, 3,(val*2), myWriteAPIKey);

ThingSpeak.writeField(myChannelNumber, 4,(val*3), myWriteAPIKey);//Update in ThingSpeak





}
