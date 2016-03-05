/*********************************************************************
  This example is for a 128x64 OLED I2C display from eBay
  2 pins are required to interface (SDA, SCL)

  This uses the AdaFruit SSD1306 and GFX Arduino libraries
  
  Adafruit invests time and resources providing open source libraries,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

 ********************************************************************/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "ESP8266WiFi.h"
void i2c_scan();

// cheap eBay SSD1306 displays don't have a RESET pin so set out of range
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  Serial.begin(115200);

  // These displays are marked on the back as having I2C address 
  // of either 0x7A or 0x7B. But they are not ...
  // So do a quick i2c scan to confrim the address is what we expect
  // 
  // On NodeMCU SDA is GPIO4, SCL is GPIO5
  Wire.begin(SDA,SCL);
  i2c_scan();

  uint8_t i2cAddress = 0x3C;  
  display.begin(SSD1306_SWITCHCAPVCC, i2cAddress);
  //display.clearDisplay();
  // display init done

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
  i2c_scan();
}

void loop() {

  display.clearDisplay();
  display.display();
  
  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.setCursor(0, 15);
  display.println("WiFi");
  display.setCursor(0, 45);
  display.println("Scanning...");
  display.display();
  
  Serial.println("Scanning...");

  int n = WiFi.scanNetworks();

  if (n == 0) {
    display.clearDisplay();
    display.display();
    display.setCursor(0, 15);
    display.println("No networks found");
    display.display();

    // Wait a bit before scanning again
    delay(3000);
  }

  else {

    display.clearDisplay();
    display.display();

    display.setCursor(0, 15);
    display.print(n);
    display.println(" networks found ");
    display.display();
    delay(2000);
    for (int i = 0; i < n; ++i) {
      display.clearDisplay();
      display.display();
      
      display.setTextSize(1);

      // Print SSID and RSSI for each network found
      display.setCursor(0, 0);
      display.print(i + 1);
      display.print("  ");
      display.print(WiFi.SSID(i));
      display.print((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : " (*)");

      display.setCursor(0, 15);
      display.print("   ");
      display.print(WiFi.BSSIDstr(i));

      display.setCursor(0, 30);
      display.print("   Strength: ");
      display.print(WiFi.RSSI(i));
      display.print("db");

      display.setCursor(0, 45);
      display.print("   Channel: ");
      display.print(WiFi.channel(i));

      display.display();

      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
      Serial.print(" : ");
      Serial.println(WiFi.BSSIDstr(i));
      Serial.print("   Strength: ");
      Serial.print(WiFi.RSSI(i));
      Serial.println("db");
      Serial.print("   Channel: ");
      Serial.println(WiFi.channel(i));
      
      delay(3000);
    }
  }
}

void i2c_scan() {
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++ ) {
    // The i2c_scanner uses the return value of
    // the Write.endTransmission to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("");

      nDevices++;
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("done\n");
  }
}

