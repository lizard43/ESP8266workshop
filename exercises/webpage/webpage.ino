#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <FS.h>

const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 1, 1);
DNSServer dnsServer;
ESP8266WebServer webServer(80);

// wifi network name
String Wifi_Name = "MassControl";
char wifiNameBuf[50];

bool streamFileIfExists(String path)
{
    if (SPIFFS.exists(path)) {
        String contentType = "text/html";
        File f = SPIFFS.open(path, "r");
        webServer.sendHeader("Cache-Control", "max-age=36000");
        webServer.streamFile(f, contentType);
        f.close();
        return true;
    }
    return false;
}

void toggleLED()
{
    int value;
    
    value = digitalRead(2);
    
    digitalWrite(2, !(value)); //toogle the led
    
    if(!(value)) //value == 0
    {
        webServer.send(200, "text/plain", "OFF");
        Serial.println("LED OFF");
    }
    else //value == 1
    {
        webServer.send(200, "text/plain", "ON");
        Serial.println("LED ON");
    }

}

void responseHTML()
{
    String path = webServer.uri();
    path += "index";
  
    if (!streamFileIfExists(path) &&
        !streamFileIfExists(path + ".html")) {
        webServer.send(404, "text/plain",
            "File not found, in ESP8266FS flash.\n\n"
            "Did you run Tools -> ESP8266 Sketch Data Upload?");
    }
}

void setup() {

  Serial.begin(115200);                        //  start serial for debug
  Serial.println("Setting up ...");
  
  pinMode(2, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  digitalWrite(2, HIGH);  //Switch Off  LED

    
  Serial.println("Opening SPIFFS");
  SPIFFS.begin();
  Dir dir = SPIFFS.openDir("/");

  Serial.print("Creating AP for:");
  Serial.println(Wifi_Name);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  Wifi_Name.toCharArray(wifiNameBuf, 50);
  WiFi.softAP(wifiNameBuf);

  // if DNSServer is started with "*" for domain name, it will reply with
  // provided IP to all DNS request
  Serial.println("Starting DNS");
  dnsServer.start(DNS_PORT, "*", apIP);

  // replay to all requests with same HTML
  webServer.onNotFound(responseHTML);
  
  webServer.on("/toggle", HTTP_GET, toggleLED);
  
  Serial.println("Starting webserver");
  webServer.begin();
  
  digitalWrite(2, LOW); //Switch On LED
}

void loop() {
  dnsServer.processNextRequest();
  webServer.handleClient();  
} 
