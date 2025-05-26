#include <FastLED.h>
#include <stdint.h>
#include "main.h"

CRGB leds[NUM_LEDS];

void wait_for_serial_connection() {
  uint32_t timeout_end = millis() + 2000;
  Serial.begin(115200);
  while(!Serial && timeout_end > millis()) {}  //wait until the connection to the PC is established
  
}

void setup() {
  wait_for_serial_connection(); // Optional, but seems to help Teensy out a lot.
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
 for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red; // Set all LEDs to red
  FastLED.show(); // Update the LEDs
  delay(50); // Wait for half a second
leds[i] = CRGB::Green; // Set all LEDs to green
  FastLED.show(); // Update the LEDs
  delay(50); // Wait for half a second
   leds[i] =CRGB::Black;
FastLED.show(); // Update the LEDs
  delay(50); // Wait for half a second
}
//fill_rainbow
}
