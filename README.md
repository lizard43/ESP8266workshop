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
* 30 dupont jumper wires (10 M-M, 10 F-F, 10 M-F)

We'll do the following exercises:
* ESP8266 overview
* Setup development environment
* Build a Wifi client
* Learn how to display graphics and text on OLED
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

* Projects in this repostory include:
	+ I2C-Scanner : Scans the I2C in the range of 0 -127 to identify slave devices
	+ ssd1306_128x64_i2c : Using the [Adafruit libraries](https://learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples), demonstrates graphics capabilities of the OLED display 
