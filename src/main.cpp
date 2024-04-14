#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


#define LED_PIN 6 // 将数据线连接到Arduino的6号引脚
#define LED_COUNT 64 // WS2812 8x8共有64个LED

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Serial.begin(9600);
  strip.begin();
  strip.show(); // 初始化所有LED为关闭状态
}

void loop() {
  // Serial.println("Hello World!");
  // delay(1000);
    // 设置每个LED的颜色为红色
  for(int i=0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 255)); // (R, G, B)
  }
  strip.show(); // 显示颜色
  delay(500); // 延迟500毫秒
}

