# ESP8266 Workshop

The best way to learn technology is to make something

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

You will need to bring your own laptop and the ability to install software (administrator password may be required).

Some software experience is recommended but we'll provide the code if needed. Experience with Arduinos (such as from our previous workshop) is also great but not essential. We can help you at each step. 

We'll do the following exercises:
* ESP8266 overview
* 01 - Hello Blinky World
* Build a Wifi client
* I2C and scanning for devices
* Display graphics and text on OLED
* WiFi Scanner and display OLED display
* Display temperature and humidity on OLED display
* Create a Web server
* Read temperature and humidity from sensor and serve on web page
* Create Wifi Access Point with SSID

Pre-Workshop:
Setup your development environment. Please perform these steps PRIOR to coming to the workshop. If you have questions or problems, use the meetup forum to ask for help so that you are ready when the workshop begins.
* Install the (CP2102 USB driver](https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx) for your OS. 
* Install Arduino IDE 1.6.9 or better. [Arduino Software](https://www.arduino.cc/en/Main/Software)
* Start the Arduino IDE. In the menu option File -> Preferences, set "Additional Boards Manager URL" to http://arduino.esp8266.com/staging/package_esp8266com_index.json
	+ Then install the ESP Board Package by going to menu option Tool -> Board -> Board Manager and then install ESP at the bottom of the list
	+ [Github has a good description of this install] (https://github.com/esp8266/Arduino/blob/master/README.md)

* Download the [ESP8266workshop repository](https://github.com/lizard43/ESP8266workshop) either with git clone or by downloading the zip and extracting it on your PC.
* Copy the folders in the setup/libraries folder of this repository to your libraries folder of your arduino install.

Projects in this repostory include:
* I2C-Scanner : Scans the I2C in the range of 0 -127 to identify slave devices
* ssd1306_128x64_i2c : Using the [Adafruit libraries](https://learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples), demonstrates graphics capabilities of the OLED display
* ssd1306_i2c_wifiscan : Using the ESP8266 WiFi capability and the [Adafruit libraries](https://learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples), demonstrates scanning available WiFi Access Points and displaying their details on the OLED. 
