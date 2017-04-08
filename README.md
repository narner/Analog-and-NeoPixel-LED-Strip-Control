# Analog-LED-Multiplexing-Example
Illustrating the use of a multiplexer to control multiple analog LED strips

## Background

<a href="https://github.com/commodorewafflejack">Ray Brooks </a> and I were recently working on prototyping a design project that invovled some analog LED strips.

We needed to be able to alter the color of the strips from Adafruit <a href="https://www.adafruit.com/products/285">strips from Adafruit </a>  between red and blue. Since we wanted to control 10 
LED strips, and there wasn't enough inputs in the Arduino for all of these strips, we decided to try
using two multiplexers so that we would be able to control all of the 10 required LED strips.

We used a <a href="https://www.sparkfun.com/products/9056">multiplexer from Sparkfun </a>, that 
ended up working quite well for our purpsoes. This <a href="http://bildr.org/2011/02/cd74hc4067-arduino/">guide from Bildr </a> was extremely helpful for getting the multiplexer setup. 

## Circuit

### Circuit Diagram

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/CircuitDiagram.png)


### Circuit Photos   

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Photo1.png)

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Photo2.png)

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Photo3.png)

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Photo4.png)







## Arduino Sketch







Here's a what this looks like in action:

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Circuit.gif)


## Parts list:

* 1 x <a href="https://www.arduino.cc/en/Main/ArduinoBoardUno">Arduino Uno </a>
* 1 x <a href="https://www.adafruit.com/products/285">RGB LED weatherproof flexi-strip </a>
* 2 x <a href="https://www.sparkfun.com/products/9056">Multiplexer from Sparkfun </a>
* 1 x <a href="https://www.adafruit.com/products/352">12V 5A Switching Supply </a>
* 20 x <a href="https://www.sparkfun.com/products/10213">N-Channel MOSFET 60V 30A </a>
* 20 x <a href="https://www.sparkfun.com/products/11508">10K Ohm Resitors </a>

## Admendum

We realized that for the particular project we're working on prototyping, we need more fine-grained
control over the individual LEDs, and will be moving to use digial LED strips rather than analog.
We hope this is helpful for anyone working with analog LED strips and Arduinos!
