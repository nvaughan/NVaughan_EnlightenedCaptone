#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
 
}

void loop()
{
  //lightpattern1();
  //stopLight();
// strip.setPixelColor(1,0,155,209);
// strip.setPixelColor(1,0,255,255);
//strip.show();
// delay(200);
//  strip.setPixelColor(1,0,0,0);
//  strip.show();
//  delay(500);
//int j = 0;
//int i =0;
// for(j; j >-1;j++)
//     {
//       strip.setPixelColor(j,0,0,0);
//       strip.setPixelColor(j,25,115,9);
//       strip.show();
//       if(j==8) j=-1;
//       delay(500);
//     }
//     delay(50);
//   for(i; i >-1;i++)
//     {
//       strip.setPixelColor(i,0,0,0);
//       //strip.setPixelColor(j,255,115,9);
//       strip.show();
//       if(i==8) i=-1;
//       delay(500);
//     }
}

void lightpattern1()
{
  int x = 1;
   for (int i = 0; i > -1; i = i + x){
     strip.setPixelColor(0,i,0,i);
     strip.setPixelColor(1,0,i,i);
     strip.setPixelColor(2,0,0,i);
     strip.setPixelColor(3,0,i,0);
     strip.setPixelColor(4,i,0,0);
     
//     for(int j =0; i >-1;i++)
//     {
//       strip.setPixelColor(i,255,115,9);
//       strip.show();
//       if(i==8) i=-1;
//       delay(50);
//     }
     strip.show();
      //analogWrite(PWMpin, i);
      if (i == 255) x = -1;             // switch direction at peak
      delay(50);
   } 

}

void stopLight()
{
      strip.setPixelColor(5,0,0,0);
    strip.setPixelColor(4,0,0,0);
        strip.setPixelColor(3,0,0,0);
strip.setPixelColor(7,255,0,0);
strip.setPixelColor(6,255,0,0);
strip.setPixelColor(5,255,0,0);
  strip.show();
  delay(600);

   strip.setPixelColor(2,0,204,0);
  strip.setPixelColor(1,0,204,0);
  strip.setPixelColor(0,0,204,0);
  strip.setPixelColor(7,0,0,0);
    strip.setPixelColor(6,0,0,0);
        strip.setPixelColor(5,0,0,0);
  strip.show();
    delay(700);
    strip.setPixelColor(5,255,255,0);
  strip.setPixelColor(4,255,255,0);
  strip.setPixelColor(3,255,255,0);
  strip.setPixelColor(0,0,0,0);
    strip.setPixelColor(1,0,0,0);
        strip.setPixelColor(2,0,0,0);
        strip.show();
        delay(500);
}


void pattern2()
{
 strip.setPixelColor(0,86,14,173); 
  
  
}
