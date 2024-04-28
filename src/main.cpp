#include <Arduino.h>
#include <FastLED.h>
#include <my_font.h>
#include <FastLED_NeoMatrix.h>
#include <Wire.h>
#include <myDS3231.h>

#define MATRIXWIDTH         8
#define MATRIXHEIGHT        8

#define LED_PIN             6
#define NUM_LEDS            ((MATRIXWIDTH)*(MATRIXHEIGHT))

#define BRIGHTNESS          60
#define CHIPSET             WS2812B
#define COLOR_ORDER         GRB

CRGB leds[NUM_LEDS];

//TODO: Need to update function so it could display the selected number
void display_message(int row, int col){
    int size = sizeof(digitBitmaps)/sizeof(digitBitmaps[0]);
    int index = 0;
    for (int i = col; i<(size+col); i++){
        uint8_t bitmap = pgm_read_byte(&digitBitmaps[index]);
        maps[i] = (bitmap << row);
        index = index + 1;
    }
}

void setup() {
    Serial.begin(115200);
    ds3231_init();
    FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(100);
    FastLED.clear();
}

void loop() {
    get_time();
    delay(1000);


    // display_message(2,4);
    // // Print digit0Bitmap at (0, 0)
    // int pixelIndex = 0;
    // for (int i = 0; i < 8; i++) {
    //     uint8_t byte = maps[i];
    //     for (int j = 0; j < 8; j++) {
    //         if (bitRead(byte, 7 - j)){
    //             leds[pixelIndex] = CRGB::White;
    //         } else {
    //             leds[pixelIndex] = CRGB::Black;
    //         }
    //     pixelIndex++;
    //     }
    // }


    // FastLED.show();
}