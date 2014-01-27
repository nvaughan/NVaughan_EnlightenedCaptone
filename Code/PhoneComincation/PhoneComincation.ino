#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, 6, NEO_GRB + NEO_KHZ800);

byte colors[3] = {
  0,0,0};
byte lineEnding = 0x0A;

void setup()
{
  strip.begin();
  strip.show();
  Serial.begin(115200);
}


void loop()
{
  if(Serial.available()>2)
  {
    int bytesRead = Serial.readBytesUntil(lineEnding,(char*)colors,3);
  }
  strip.setPixelColor(0,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
  strip.setPixelColor(1,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
  strip.setPixelColor(2,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
  strip.setPixelColor(3,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
  strip.setPixelColor(4,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
  strip.setPixelColor(5,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
  strip.setPixelColor(6,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
  strip.setPixelColor(7,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
  strip.show();

}


