# ESP8266 Workshop

This is the repository for the ESP8266 workshop. You'll find all files and notes needed to complete the exercises.

Slides can be found on slideshare [here](http://www.slideshare.net/roadster43)

![NodeMCU](/images/nodemcu.jpg)

Provided with your workshop fee are the parts we'll be using: 
* NodeMCU v1.0 CP2102
* 0.96" 128x64 OLED I2C
* DHT11 Temperature & Humidity Sensor
* Micro USB data cable
* MB-102 Solderless Breadboard with 830 tie points and 2 buses
* 30 Dupont jumper wires (10 M-M, 10 F-F, 10 M-F)
* 3D printed NodeMCU case

You will need to bring your own laptop and the ability to install software (administrator password may be required).

Some software experience is recommended but we'll provide the code if needed. Experience with Arduinos (such as from our previous workshop) is also great but not essential. We can help you at each step. 

We'll do the following exercises:
* ESP8266 overview
* Setup development environment
* Build a Wifi client
* I2C and scanning for devices
* Display graphics and text on OLED
* WiFi Scanner and display OLED display
* Display temperature and humidity on OLED display
* Create a Web server
* Read temperature and humidity from sensor and serve on web page
* Create Wifi Access Point with SSID

Pre-Workshop:
* Install Arduino IDE 1.6.7 or better. [Arduino Software](https://www.arduino.cc/en/Main/Software)
* In File -> Preferences, set "Additional Boards Manager URL" to http://arduino.esp8266.com/staging/package_esp8266com_index.json
	+ Then install the ESP Board Package by going to Tool -> Board -> Board Manager and then install ESP at the bottom of the list
	+ [Github has a good description of this install] (https://github.com/esp8266/Arduino/blob/master/README.md)

* Download this [ESP8266workshop repository](https://github.com/lizard43/ESP8266workshop) either with git clone or by downloading the zip and extracting it on your PC.
* Copy the files in the libraries folder of this repository to your libraries folder of your arduino install.

Projects in this repostory include:
* I2C-Scanner : Scans the I2C in the range of 0 -127 to identify slave devices
* ssd1306_128x64_i2c : Using the [Adafruit libraries](https://learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples), demonstrates graphics capabilities of the OLED display
* ssd1306_i2c_wifiscan : Using the ESP8266 WiFi capability and the [Adafruit libraries](https://learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples), demonstrates scanning available WiFi Access Points and displaying their details on the OLED. 

![NodeMCU](/images/NODEMCU_DEVKIT_V1.0_PINMAP.png)

NodeMCU has weird pin mapping.
Pin numbers written on the board itself do not correspond to ESP8266 GPIO pin numbers. We have constants defined to make using this board easier:

// Analog
static const uint8_t A0 = 17;

// Digital
static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;

// On board LED
static const uint8_t BUILTIN_LED = 16;

// I2C
//    NodeMCU pins SDA => D2, SCL => D1
static const uint8_t SDA = 4;
static const uint8_t SCL = 5;

// SPI
//    NodeMCU pins SS => D8, MOSI => D7, MISO => D6, SCK => D5
static const uint8_t SS    = 15;
static const uint8_t MOSI  = 13;
static const uint8_t MISO  = 12;
static const uint8_t SCK   = 14;

These are defined in pins_arduino.h

If you want to use NodeMCU pin 5, use D5 for pin number, and it will be translated to 'real' GPIO pin 14.



D0 is shared with the onboard LED
