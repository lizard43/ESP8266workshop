# 01 - Hello Blinky World

Make sure you have setup your development environment before beginning
   * Arduino IDE installed
   * ESP8266 Board Package
   * CP2102 USB driver

The first program that most people write to test a new language is Hello World. The first sketch used to test an Arduino compatible board is Blink. 

The Blink sketch simply turns on an LED on for one second, then off for one second, repeatedly. A blinking hello world.

![nodeMCU-blink](/images/nodeMCU-blink.gif)

The nodeMCU has a built in LED on the module. It is connected to GPIO16 which has been mapped to nodeMCU pin D0

![NodeMCU-pinout](/images/NODEMCU_DEVKIT_V1.0_PINMAP.png)

Take a minute to locate the nodeMCU's pins_arduino.h file that defines constants to help navigate the nodeMCU's pins. Look in your home folder. The exact path may differ based on the Arduino IDE version and the ESP8266 Board Package that you've installed. Mine is located here:
* /home/d/.arduino15/packages/esp8266/hardware/esp8266/2.3.0-rc2/variants/nodemcu/pins_aduino.h

The pins_arduino.h file contents look like this:

![NodeMCU-pins_arduino.h](/images/nodeMCU-pins_arduino.h.png)

Now we're ready to start Blinking!

* Carefully insert your nodeMCU module onto your breadboard
* Connect your PC to the nodeMCU with the micro USB cable
* Start the Arduino IDE
* Use the menu option File->Examples->ESP8266->Blink to open the Blink sketch

![arduino-example-blink](/images/arduino-example-blink.png)

Notice that the comments in the Blink sketch say "The blue LED on the ESP-01 module is connected to GPIO1". We know this is incorrect for the nodeMCU because the LED is connected to GPIO16. But all is not lost because notice that the sketch uses a constant called LED_BUILTIN. Look back above to the pins_arduino.h file and note that LED_BUILTIN has been defined to GPIO16.

* Use the menu option Tools->Board to select NodeMCU 1.0 (ESP-12E Module)

![arduino-board-selection](/images/arduino-board-selection.png)




