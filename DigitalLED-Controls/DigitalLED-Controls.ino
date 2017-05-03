#include <Adafruit_NeoPixel.h>

const int  switchPin = 3;    // the pin that the push-button is attached to
int switchState = 0;         // current state of the push-button
int lastSwitchState = 0;     // previous state of the push-button

const int potPin = 2;    // select the input pin for the potentiometer
uint16_t lastPotentiometerValue = 0;
String colorVal = "";

// Create a pixel strip instance. The numerical value argument depends on how many pixels are in your strip.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(180, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(57600);
  pinMode(switchPin, INPUT);
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  colorWipe(strip.Color(0, 0, 255)); // Set to Blue on startup
}

void loop() {
  delay(10);
  readAndSendSwitchDataIfChanged();
  readAndSendPotentiometerDataIfChanged();
}

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

void clearPixels(uint8_t numOfPixels) {
   uint16_t clearColor = (127, 127, 127);
   strip.setPixelColor(numOfPixels, clearColor);
   strip.show();
}

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

