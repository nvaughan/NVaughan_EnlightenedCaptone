#include <Adafruit_NeoPixel.h>
#include <Potentiometer.h>
#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);
int count;
int randLight;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(5);
  Serial.begin(9800);
  count = 1;
  randLight =1;
}
