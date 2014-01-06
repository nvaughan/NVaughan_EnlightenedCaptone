#include <Adafruit_NeoPixel.h>
#include <Potentiometer.h>

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
  strip.setBrightness(32);
  Serial.begin(9800);
 
}

void loop()
{
 int val = analogRead(2);
// Serial.println(val);
 int pixel = val? val/122 :val;
 Serial.println(pixel);
 strip.setPixelColor(pixel,255,255,255);
 strip.show();
 delay(50);
 if(pixel == 8 || pixel == 0)
 {
   if(pixel ==8)
   {
     strip.setPixelColor(0,0,0,0);
   }
   else if(pixel ==0)
   {
     strip.setPixelColor(7,0,0,0);
   }
 
   strip.setPixelColor(1,0,0,0);
   strip.setPixelColor(2,0,0,0);
   strip.setPixelColor(3,0,0,0);
   strip.setPixelColor(4,0,0,0);
   strip.setPixelColor(5,0,0,0);
   strip.setPixelColor(6,0,0,0);
//   strip.setPixelColor(7,0,0,0);
   strip.show();
 }
}
