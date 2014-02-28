#include <Adafruit_NeoPixel.h>
#include <Potentiometer.h>
#include <Lights>

#define PIN 6


Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);
int count;
int randLight;
long chaseDelay8th,chaseDelay6th,chaseDelay3rd,chaseDelay12th,chaseDelay;
void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(5);
  Serial.begin(9800);
  count = 1;
  randLight =1;
  int BPM = 100;
  int bpmMS = 60000/BPM+1;
  int bpm8thMS = bpmMS/2;
  int bpm12thMS = bpm8thMS/2;
  int bpm6thMS = bpmMS*2/3;
  int bpm3rdMS = bpmMS*4/3;
  chaseDelay8th = bpm8thMS/7;
  chaseDelay6th = bpm6thMS/7;
  chaseDelay3rd = bpm3rdMS/7;
  chaseDelay12th = bpm12thMS/7;  

}


void loop()
{

  int randLight = 0;
  if(Serial.available()>0)
  {
    randLight = Serial.read();
    count = 1;
    while(count !=10)
    {
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
      count++;
    }
  }
}




