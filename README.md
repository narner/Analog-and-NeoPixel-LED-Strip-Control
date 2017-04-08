# Analog-LED-Multiplexing-Example
Illustrating the use of a multiplexer to control multiple analog LED strips

## Background

<a href="https://github.com/commodorewafflejack">Ray Brooks </a> and I were recently working on prototyping a design project that invovled some analog LED strips.

We needed to be able to alter the color of the strips from Adafruit <a href="https://www.adafruit.com/products/2856">strips from Adafruit </a>  between red and blue. Since we wanted to control 10 
LED strips, and there wasn't enough inputs in the Arduino for all of these strips, we decided to try
using two multiplexers so that we would be able to control all of the 10 required LED strips.

We used a <a href="https://www.sparkfun.com/products/9056">multiplexer from Sparkfun </a>, that 
ended up working quite well for our purpsoes. This <a href="http://bildr.org/2011/02/cd74hc4067-arduino/">guide from Bildr </a> was extremely helpful for getting the multiplexer setup. 

## Circuit


Circuit Photos


![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Photo1.png)


![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Photo2.png)

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Photo3.png)

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Photo4.png)




Circuit Schematic



## Arduino Sketch



Parts list:


Here's a video of what this looks like in action:
