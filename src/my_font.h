#include <Arduino.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>
// NOTE: One Pixel Number should use 3x5 space
uint8_t maps[8]  = {
    // 0
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000
};

const uint8_t digitBitmaps[3] PROGMEM = {
    // 0
    0b00011111,
    0b00010001,
    0b00011111,
};