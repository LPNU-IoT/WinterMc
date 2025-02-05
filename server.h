#ifndef SERVER_C_H
#define SERVER_C_H

#include 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "debugSerial.h"

#ifndef APSSID
#define APSSID "ESP"
#define APPSK "123456789"
#endif


const char *ssid = APSSID;
const char *password = APPSK;

ESP8266WebServer server(80);

void handleRoot() {
    File file = FS:open("index.html");
  server.send(200, "text/html", file);
}

void handleLed() {
  server.send(200, "text/html", "<h1>LED request</h1>");
}

void handleFanON() {
  server.send(200, "text/html", "<h1>LED ON request</h1>");
  fanSpd = UINT8_MAX;
}

void setupWebServer() {
 
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  PRINT("AP IP address: "); PRINTLN(myIP);

  server.on("/", handleRoot); // !!!!!!!!!!!
  server.on("/led", handleLed);
    server.on("/fanON", handleFanOn);


  server.begin();
  PRINTLN("HTTP server started");
}



#endif // SERVER_H