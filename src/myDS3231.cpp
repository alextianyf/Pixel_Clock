#include <DS3231.h>
#include <Wire.h>

//NOTE: Pin connection(SDA with A4; SCL with A5)

DS3231 myRTC;
int hour, minute, second;
int hourTens, hourOnes;
int minuteTens, minuteOnes;
int secondTens, secondOnes;

#define DS3231_ADDRESS 0x68

bool century = false;
bool h12Flag;
bool pmFlag;

void ds3231_init(){
    Wire.begin();
}

void get_time(){
    hour = myRTC.getHour(h12Flag, pmFlag); // 24小时制
    minute = myRTC.getMinute();
    second = myRTC.getSecond();

    // 分解分钟
    minuteTens = minute / 10;   // 十位数
    minuteOnes = minute % 10;   // 个位数

    // 分解秒钟
    secondTens = second / 10;   // 十位数
    secondOnes = second % 10;   // 个位数

        // 分解小时
    hourTens = hour / 10;   // 十位数
    hourOnes = hour % 10;   // 个位数

      // 输出时间
    Serial.print("Hour: ");
    Serial.print(hour);
    Serial.print(" Minute: ");
    Serial.print(minute);
    Serial.print(" Second: ");
    Serial.println(second);
}
