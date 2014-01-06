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
  long delayVal;
  delayVal = val*(.2)*1000;
  Serial.println(delayVal);
  strip.setPixelColor(7,155,155,155);
  strip.show();
  delayMicroseconds(delayVal*100000);
  strip.setPixelColor(7,0,0,0);
  strip.show();
  delayMicroseconds(delayVal*100000);
  
}


