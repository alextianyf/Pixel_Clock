#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


#define LED_PIN 6 // 将数据线连接到Arduino的6号引脚
#define LED_COUNT 64 * 4 // WS2812 8x8共有64个LED

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Serial.begin(9600);
  strip.begin();
  strip.show(); // 初始化所有LED为关闭状态
}

void loop() {
  for(int i=0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 255)); // 设置当前LED为白色
    strip.show(); // 显示当前LED的颜色
    delay(50); // 延迟一段时间，让LED保持亮起状态
    strip.setPixelColor(i, strip.Color(0, 0, 0)); // 关闭当前LED
    strip.show(); // 显示关闭当前LED
    delay(50); // 延迟一段时间，让LED保持熄灭状态
  }
}

