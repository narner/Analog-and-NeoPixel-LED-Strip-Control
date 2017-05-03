# Digital-LED-Controls-Example
Illustrating how simple analog interface elements can be used control a digital LED strip.

## Overview	

This sketch shows how you can use a simple switch and potentiometer to control the colors and 
number of lit pixels on an Adafruit NeoPixel strip (digital LED strip.

The switch will toggle the strip between red and blue, and the potentiometer will control 
how many LEDs are lit-up on the strip. 


## Circuit

### Circuit Diagram

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/CircuitDiagram.png)


### Circuit Photos   

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Photo1.png)

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Photo2.png)

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Photo3.png)

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Photo4.png)



## Arduino Sketch

The sketch was modified from  <a href="https://github.com/adafruit/Adafruit_NeoPixel/blob/master/examples/strandtest/strandtest.ino">Adafruit's Strandtest example </a>.

Two new methods were added, `readAndSendSwitchDataIfChanged` and `readAndSendPotentiometerDataIfChanged`. The first method was used to toggle the NeoPixel strip's 
pixels between Red and Blue:

```
void readAndSendSwitchDataIfChanged(void) {
  // Read the switch input pin:
  switchState = digitalRead(switchPin);

  // Toggle between a red and blue colors
  if (switchState != lastSwitchState) {
    strip.show(); // Initialize all pixels to 'off'
      if (switchState == HIGH) {
        colorVal = "RED";
        colorWipe(strip.Color(255, 0, 0));
  } else {
    colorVal = "BLUE";
    colorWipe(strip.Color(0, 0, 255));
  }
  // Delay a little bit to avoid bouncing
  delay(50);  
  }
  // Save the current state as the last state, for next time through the loop 
  lastSwitchState = switchState;
}
```

You'll notice a call to `strip.show()` inside of the `if` statement. This is done to reset the 
pixel values before we change from one color to the next.

In the `readAndSendPotentiometerDataIfChanged` method, we get the value of `newPotentiometerValue` 
baed on the position of the analog potentiometer. This value is scaled to be between 0 and 180 (180
is the number of pixels that is on the strip we used). 

We first check the value of `colorVal`, which was set in the `readAndSendSwitchDataIfChanged` method
above. We also ensure that if `lastPotentiometerValue` is 0, then we should call `clearPixels`, and
reset every pixel on the strip. The number of pixels that should be lit up is stored in the global
`newPotentiometerValue` variable.

```
void readAndSendPotentiometerDataIfChanged(void) {
 // Scale the potentiometer value
 int newPotentiometerValue = analogRead(potPin) / 5.68;   
  if (newPotentiometerValue != lastPotentiometerValue) {
      lastPotentiometerValue = newPotentiometerValue;

      if (colorVal == "RED") {
        if (lastPotentiometerValue == 0) {
          clearPixels(180);
        } else {
          colorWipe(strip.Color(255, 0, 0)); // Red
        }
      } else if (colorVal == "BLUE") {
        if (lastPotentiometerValue == 0) {
          clearPixels(180);
        } else {
          colorWipe(strip.Color(0, 0, 255)); // Blue
        }
      }
   }
}
```

Now, the fun part - actually setting the NeoPixel strip's pixels to light up!

Here's the `colorWipe` method. It takes one parameter, which is the the RGB value corresponding to 
the color we want to use, as determined by our toggle switch's position. 

```
void colorWipe(uint32_t c) {

  // Reset the poteniometer value if we're at an "edge"
  for(uint16_t i = lastPotentiometerValue; i<180; i++){
      uint16_t clearColor = (0, 0, 0);
      strip.setPixelColor(i, clearColor);
  }

  // Fill the pixels based on the potentiometer value
  for(uint16_t i=0; i<lastPotentiometerValue; i++) {
    strip.setPixelColor(i, c);
    delay(0.5);
  }
  
   strip.show();
}
```

You'll see that there are two for loops in the method - the first one "clears out" the pixels' 
values before changing them. Since pixels's that aren't sent a new color retain their 
previous color value, if the user turned the potentiometer (see 
<a href="https://arduino.stackexchange.com/questions/37469/using-a-potentiometer-to-control-number-of-lit-pixels-on-an-neopixel-strip">this discussion on Stack Overflow </a>).

The second one is where we gradually turn pixels on and off as the potentiometer is turned. The 
loop looks to see what the value of `lastPotentiometerValue` is, and lights up the pixels up to
that value with the correct color. 


Here's a view of the circuit in operation:

![Alt Text](https://github.com/narner/Analog-LED-Multiplexing-Example/raw/master/ReadmeFiles/Circuit.gif)


## Parts list:

* 1 x <a href="https://www.arduino.cc/en/Main/ArduinoBoardUno">Arduino Uno </a>
* 1 x <a href="https://www.adafruit.com/product/1376 </a> (5 ft long)
* 1 Potentiometer
* 1 Toggle Switch
