#include <Arduino.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>
#include <my_font.h>

#define MATRIXWIDTH         32
#define MATRIXHEIGHT        8

#define LED_PIN             6
#define NUM_LEDS            ((MATRIXWIDTH)*(MATRIXHEIGHT))

#define BRIGHTNESS          60
#define CHIPSET             WS2812B
#define COLOR_ORDER         GRB

CRGB leds[NUM_LEDS];
FastLED_NeoMatrix *matrix;

void setup() {
    Serial.begin(115200);
    FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    matrix = new FastLED_NeoMatrix(leds,MATRIXWIDTH,MATRIXHEIGHT,NEO_MATRIX_BOTTOM + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS);
    matrix->setTextWrap(false);
    matrix->setBrightness(50);
    matrix->setFont(&Picopixel);
    matrix->clear();
    matrix->setBrightness(BRIGHTNESS);
}

void ShowMessage(char *message, int len, uint32_t color)
{
    matrix->clear();
    matrix->setTextColor(color);
    if (len < 1 || len > 8)
        return;
    matrix->setCursor(1 + (8 - len) * 2, 5); //设置鼠标光标的位置用以确定在哪里显示文字

    matrix->print(message);
    matrix->show();
}

void loop() {
    ShowMessage("BOOT", 4, matrix->Color(255, 0, 255) );
}