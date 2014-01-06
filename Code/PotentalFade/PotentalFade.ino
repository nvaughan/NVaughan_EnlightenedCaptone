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
  Serial.println(val);

  if(val < 341)
  {
    val=(val*3)/4;
    strip.setPixelColor(0,(256-val),val,0);
    strip.setPixelColor(1,(256-val),val,0);
    strip.setPixelColor(2,(256-val),val,0);
    strip.setPixelColor(3,(256-val),val,0);
    strip.setPixelColor(4,(256-val),val,0);
    strip.setPixelColor(5,(256-val),val,0);
    strip.setPixelColor(6,(256-val),val,0);
    strip.setPixelColor(7,(256-val),val,0);
    strip.show();
  }
  else if(val<682)
  {
    val=((val-341)*3)/4;
    strip.setPixelColor(0,0,256-val,val);
    strip.setPixelColor(1,0,256-val,val);
    strip.setPixelColor(2,0,256-val,val);
    strip.setPixelColor(3,0,256-val,val);
    strip.setPixelColor(4,0,256-val,val);
    strip.setPixelColor(5,0,256-val,val);
    strip.setPixelColor(6,0,256-val,val);
    strip.setPixelColor(7,0,256-val,val);
    strip.show();    
  }
  else
  {
    val=((val-683)*3)/4;
    strip.setPixelColor(0,val,0,256-val);
    strip.setPixelColor(1,val,0,256-val);
    strip.setPixelColor(2,val,0,256-val);
    strip.setPixelColor(3,val,0,256-val);
    strip.setPixelColor(4,val,0,256-val);
    strip.setPixelColor(5,val,0,256-val);
    strip.setPixelColor(6,val,0,256-val);
    strip.setPixelColor(7,val,0,256-val);
    strip.show(); 
  }
  delay(50);


  //int pixel = val? val/122 :val;
  //Serial.println(pixel);
  //strip.setPixelColor(pixel,255,255,255);
  //strip.show();
  //delay(50);


}

