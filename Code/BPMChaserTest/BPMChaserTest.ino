#include <Adafruit_NeoPixel.h>
#include <Potentiometer.h>
#include <Lights>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
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


void loop()
{
  int val = analogRead(2);
  int BPM = 100;
  int bpmMS = 60000/BPM+1;
  int bpm8thMS = bpmMS/2;
  int bpm12thMS = bpm8thMS/2;
  int bpm6thMS = bpmMS*2/3;
  int bpm3rdMS = bpmMS*4/3;
 
  long chaseDelay = bpmMS/7;
  long chaseDelay8th = bpm8thMS/7;
  int chaseDelay6th = bpm6thMS/7;
  int chaseDelay3rd = bpm3rdMS/7;
  int chaseDelay12th = bpm12thMS/7;

  int totalRepeat = 10;
  count++;
  //Serial.println(count);
  if(count == totalRepeat)
  {
    //Serial.println("Here");
     randLight = random(1,6);
     Serial.write(randLight);
    count = 0;
  }
  
  switch(randLight)
  {
  case 1:
    chaseLED(chaseDelay8th,155,155,155);

    break;
  case 2:
    chaseBothWays(chaseDelay8th,155,155,155);

    break;
  case 3:
    singleOnOff(chaseDelay8th,155,155,155);
    singleOnOff(chaseDelay8th,155,155,155);
    singleOnOff(chaseDelay8th,155,155,155);

    break;
  case 4:
    singleOff(chaseDelay8th,155,155,155);
    singleOff(chaseDelay8th,155,155,155);
    singleOff(chaseDelay8th,155,155,155);

    break;
  case 5:
    chaseInvert(chaseDelay8th,155,155,155);

    break;
  case 6:
    chaseInvertBoth(chaseDelay8th,155,155,155);

    break;
  }

}







