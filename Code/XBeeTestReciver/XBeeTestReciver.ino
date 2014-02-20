#include <Adafruit_NeoPixel.h>
#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
  delay(1000);
}

void loop() {
  if(Serial.available() > 0)
  {
    char inChar = Serial.read();
    while(Serial.available()<=0);
    if(inChar=='a')
    {
      strip.setPixelColor(0,155,155,155);
      strip.setPixelColor(1,155,155,155);
      strip.setPixelColor(2,155,155,155);
      strip.setPixelColor(3,0,0,0);
      strip.setPixelColor(4,0,0,0);
      strip.setPixelColor(5,0,0,0);
    }
    
    if(inChar == 'b')
    {
      strip.setPixelColor(0,0,0,0);
      strip.setPixelColor(1,0,0,0);
      strip.setPixelColor(2,0,0,0);
      strip.setPixelColor(3,155,155,155);
      strip.setPixelColor(4,155,155,155);
      strip.setPixelColor(5,155,155,155);
    }
  }
  
  strip.show();

  delay(10);
}



