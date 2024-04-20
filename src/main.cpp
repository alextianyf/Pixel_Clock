#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN     6
#define NUM_LEDS    128

CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(60);
    FastLED.clear();
}

void loop() {
    // Turn on all LEDs to red

    // fill_solid(leds, NUM_LEDS, CRGB::Red);
    // FastLED.show();
    // delay(1000);

    // // Turn off all LEDs
    // fill_solid(leds, NUM_LEDS, CRGB::Black);
    // FastLED.show();
    // delay(1000);

    leds[1].setHSV(0,255,255);
    FastLED.show();
}