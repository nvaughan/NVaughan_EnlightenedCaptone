/****************************************
 * Example Sound Level Sketch for the 
 * Adafruit Microphone Amplifier
 ****************************************/
#include <Adafruit_NeoPixel.h>


const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8,6, NEO_GRB + NEO_KHZ800);
int beats[50];



void setup() 
{
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(5);
  Serial.begin(9600);
}


void loop() 
{
  unsigned long startMillis= millis();  // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
    sample = analogRead(2);
    if (sample < 1024)  // toss out spurious readings
    {
      if (sample > signalMax)
      {
        signalMax = sample;  // save just the max levels
      }
      else if (sample < signalMin)
      {
        signalMin = sample;  // save just the min levels
      }
    }
  }
  peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
  double volts = (peakToPeak * 3.3) / 1024;  // convert to volts

  Serial.println(peakToPeak);

  if(peakToPeak<60 && peakToPeak>35)
  {
    strip.setPixelColor(0,155,155,155);
    strip.show();
  }
  else
  {
   strip.setPixelColor(0,0,0,0);
   strip.show();
  }
}

