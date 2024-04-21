#include <Arduino.h>
#include <FastLED.h>
#include <my_font.h>
#include <FastLED_NeoMatrix.h>

#define MATRIXWIDTH         8
#define MATRIXHEIGHT        8

#define LED_PIN             6
#define NUM_LEDS            ((MATRIXWIDTH)*(MATRIXHEIGHT))

#define BRIGHTNESS          60
#define CHIPSET             WS2812B
#define COLOR_ORDER         GRB

CRGB leds[NUM_LEDS];

int setCursor(int row, int col){
    int num_pix_each_col = 8;
    int adjust_row = row + 1;
    int adjust_col = col + 1;
    int index = adjust_col * num_pix_each_col - adjust_row;
    return index;
}

void setup() {
    Serial.begin(115200);
    FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(100);
    FastLED.clear();
}

void loop() {
    // Print digit0Bitmap at (0, 0)
    int pixelIndex = 0;
    for (int i = 0; i < 8; i++) {
        uint8_t byte = pgm_read_byte(digitBitmaps[0] + i);
        for (int j = 0; j < 8; j++) {
        if (bitRead(byte, 7 - j)){
            leds[pixelIndex] = CRGB::White;
        } else {
            leds[pixelIndex] = CRGB::Black;
        }
        pixelIndex++;
        }
    }

    FastLED.show();
}

