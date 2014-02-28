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
  strip.setBrightness(5);
  Serial.begin(9800);
}

void loop()
{
  if(Serial.available()>3)
  {
    int bytesRead = Serial.readBytesUntil(lineEnding,(char*)colors,3);
  }
  setAllPixels(map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
  strip.show();
}


void setAllPixels(int red,int green,int blue)
{
  strip.setPixelColor(0,red,green,blue);
  strip.setPixelColor(1,red,green,blue);
  strip.setPixelColor(2,red,green,blue);
  strip.setPixelColor(3,red,green,blue);
  strip.setPixelColor(4,red,green,blue);
  strip.setPixelColor(5,red,green,blue);
  strip.setPixelColor(6,red,green,blue);
  strip.setPixelColor(7,red,green,blue);
}



