# 01 - Hello Blinky World

* Make sure you have setup your development environment before beginning
   + Arduino IDE installed
   + ESP8266 Board Package
   + CP2102 USB driver

The first program that most people write to test a new language is Hello World. The first sketch used to test an Arduino compatible board is Blink. 

The Blink sketch simply turns on an LED on for one second, then off for one second, repeatedly. A blinking hello world.

![nodeMCU-blink](/images/nodeMCU-blink.gif)

The nodeMCU has a built in LED on the module. It is connected to GPIO16 which has been mapped to nodeMCU pin D0

![NodeMCU-pinout](/images/NODEMCU_DEVKIT_V1.0_PINMAP.png)

Take a minute to locate the nodeMCU's pins_arduino.h file that defines constants to help navigate the nodeMCU's pins. Look in your home folder. The exact path may differ based on the Arduino IDE version and the ESP8266 Board Package that you've installed. Mine is located here:
*/home/d/.arduino15/packages/esp8266/hardware/esp8266/2.3.0-rc2/variants/nodemcu/pins_aduino.h

The file contents look like this:
![NodeMCU-pins_arduino.h](/images/nodeMCU-pins_arduino.h.png)
