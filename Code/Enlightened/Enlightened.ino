#include <Adafruit_NeoPixel.h>
#include <Potentiometer.h>
#include <Lights>

#define PIN 6


Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

byte colors[3] = {
  0, 0, 0}; 
byte lineEnding = 0x0A;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
//  strip.setBrightness(5);
  Serial.begin(115200);
}

void loop()
{
  
}
