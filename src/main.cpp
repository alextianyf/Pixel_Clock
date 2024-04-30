#include <Arduino.h>
#include <Wire.h>
#include <myDS3231.h>
#include <ws2818b.h>




void setup() {
    Serial.begin(115200);
    //ds3231_init();
    ws2812b_init();
   
}

void loop() {
    //get_time();
    //delay(1000);
    test();


}