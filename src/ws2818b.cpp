#include <FastLED.h>
#include <my_font.h>
#include <FastLED_NeoMatrix.h>

#define MATRIXWIDTH         32
#define MATRIXHEIGHT        8

#define LED_PIN             6
#define NUM_LEDS            ((MATRIXWIDTH)*(MATRIXHEIGHT))

#define BRIGHTNESS          60
#define CHIPSET             WS2812B
#define COLOR_ORDER         GRB

CRGB leds[NUM_LEDS];

void ws2812b_init(){
    FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.clear();
}


void load_num(int num, int row, int col){
    /*
    * This function load the desired number into buffer's designated location and waiting for display
    NOTE: if col=0, and row=0, number will display at the top left corner
    @param num: desired number 
    @param row: selected row for displaying.
    @param col: selected col for displaying
    */

    //get the width of the number.
    //3x5 size of number is used, the width should be 3 in this case. 
    int num_width = sizeof(digitBitmaps[num])/sizeof(digitBitmaps[num][0]);

    int i = 0;

    //Load one number into buffer
    while(i<num_width){
        //get the one byte(0b00011111) from the desired number and store into the bitmap buffer
        uint8_t bitmap = pgm_read_byte(&digitBitmaps[num][i]);
        //transfer buffer byte into designated coloumn and row.
        maps[col] = (bitmap << row);
        //update col 3 times until all buffer has been transferred
        col++;
        //update i 3 times until all number byte has been loaded
        i++;
    }

}

//TODO: With the load_num function, create a display_num interface function.
//! The test() function only display number on the first 8x8 ws2818b, the code need to be polished.

void test(){
    load_num(0,1,4);
    // Print digit0Bitmap at (0, 0)
    int pixelIndex = 0;
    for (int i = 0; i < 8; i++) {
        uint8_t byte = maps[i];
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