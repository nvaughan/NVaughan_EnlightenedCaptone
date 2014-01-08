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
  strip.setBrightness(12);
  Serial.begin(9800);

}

void loop()
{
  int val = analogRead(2);
  //  long delayVal;
  //  delayVal = val*(.2)*1000;
  //  Serial.println(delayVal);
  int BPM = 137;
  int bpmMS = 60000/BPM+1;
  int bpm8thMS = bpmMS/2;
  int bpm6thMS = bpmMS*2/3;
  int bpm3rdMS = bpmMS*4/3;
  Serial.println(bpm3rdMS);
  Serial.println(bpmMS);
  Serial.println(bpm6thMS);
  Serial.println(bpm8thMS);
  long chaseDelay = bpmMS/7;
  long chaseDelay8th = bpm8thMS/7;
  int chaseDelay6th = bpm6thMS/7;
  int chaseDelay3rd = bpm3rdMS/7;
  //chaseLED(chaseDelay8th);

  //chaseBothWays(chaseDelay);
  //chaseBothWays(chaseDelay8th);
  //chaseBothWays(chaseDelay8th);
  if(val < 341)
  {
    val=(val*3)/4;
    chaseBothWays(chaseDelay3rd,(265-val),val,0);
  }
  else if(val < 682)
  {
    val=((val-341)*3)/4;
    chaseBothWays(chaseDelay3rd,0,256-val,val);    
  }
  else
  {
    val=((val-683)*3)/4;
    chaseBothWays(chaseDelay3rd,val,0,256-val);    
  }


}

void chaseLED(int chaseDelay)
{

  strip.setPixelColor(7,155,155,155);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(6,155,155,155);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(5,155,155,155);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(4,155,155,155);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(3,155,155,155);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(2,155,155,155);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(1,155,155,155);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(0,155,155,155);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(7,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(6,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(5,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(4,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(3,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(2,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(1,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(0,0,0,0);
  strip.show();
  delay(chaseDelay);

}





void chaseBothWays(int chaseDelay,int red,int green,int blue)
{
  strip.setPixelColor(7,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(6,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(5,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(4,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(3,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(2,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(1,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(0,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(7,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(6,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(5,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(4,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(3,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(2,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(1,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(0,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(0,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(1,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(2,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(3,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(4,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(5,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(6,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(7,red,green,blue);
  strip.show();
  delay(chaseDelay);

  strip.setPixelColor(0,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(1,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(2,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(3,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(4,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(5,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(6,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(7,0,0,0);
  strip.show();
  delay(chaseDelay);

  //  for(int i = 7 ; i>-1;i++)
  //  {
  //    strip.setPixelColor(i,155,155,155);
  //    strip.show(); 
  //    delay(chaseDelay);
  //  }
  //  for(int i =7;i>-1;i++)
  //  {
  //    strip.setPixelColor(i,0,0,0);
  //    strip.show(); 
  //    delay(chaseDelay);
  //  }
  //  for(int i =0;i<8;i++)
  //  {
  //    strip.setPixelColor(i,155,155,155);
  //    strip.show(); 
  //    delay(chaseDelay);
  //  }
  //  for(int i =0;i<8;i++)
  //  {
  //    strip.setPixelColor(i,0,0,0);
  //    strip.show(); 
  //    delay(chaseDelay);
  //  }


}










