/****************************************
 * Example Sound Level Sketch for the 
 * Adafruit Microphone Amplifier
 ****************************************/
//#include <BPMChaserTest.h>
#include <Adafruit_NeoPixel.h>



const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8,6, NEO_GRB + NEO_KHZ800);
int beatIntervals[60];
const unsigned long BPMAccuracy15Seconds = 15000;
const unsigned long BPMAccuracy10Seconds = 10000;
const unsigned long BPMAccuracy5Seconds = 5000;
unsigned long startMilli;
int count;
int roughBPM = 100;
unsigned long average = 0;
//BPMChaserTest ct = new BPMChaserTest();

// Every 5/10/15 second take average miliseconds between 'beats'
// 'Beats' are counted and then Multiplied by 4 (if taken by 15 seconds) 
//,6 if 10 and 12 if by 5 to get the BPM
// Pass BPM into BPM chaser test.
// When get a useable BPM put it in the the Chaser LEDs and wait for 2 minutes 
//and then survey agian.

void setup() 
{
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(5);
  count = 1;
  startMilli = millis();
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
  
  if((peakToPeak<160 && peakToPeak>100)|| peakToPeak >160)
  {
    strip.setPixelColor(0,0,0,0);
    strip.setPixelColor(1,0,0,0);
    strip.setPixelColor(2,0,0,0);
    strip.setPixelColor(3,0,0,0);
    strip.setPixelColor(4,0,0,0);
    strip.setPixelColor(5,0,0,0);
    strip.setPixelColor(6,0,0,0);
    strip.setPixelColor(7,0,0,0);
    strip.show(); 
    Serial.print("Since last 'beat' ");
    Serial.println(startMilli - millis());
    beatIntervals[count] =  millis()-startMilli;
    count +=1;  

  }
  else
  {
    
    strip.setPixelColor(0,155,155,155);
    strip.setPixelColor(1,155,155,155);
    strip.setPixelColor(2,155,155,155);
    strip.setPixelColor(3,155,155,155);
    strip.setPixelColor(4,155,155,155);
    strip.setPixelColor(5,155,155,155);
    strip.setPixelColor(6,155,155,155);
    strip.setPixelColor(7,155,155,155);
    strip.show(); 
    //startMilli = millis();  
    
    
//    if(count == 60)
//      count = 1;
  }

  if(startMillis -millis() == BPMAccuracy15Seconds || count ==60)
  {

    for(int i =0; i<60;i++)
    {
//      Serial.print("Interval ");
//      Serial.println(beatIntervals[i]);
      average +=beatIntervals[i];
    }
    average = average/60;
    Serial.print("Average: ");
    Serial.println(average);
    count = 1;
    
  }

//  while(startMillis-millis() <= 120000)
//  {
//    start(roughBPM);
//  }
}















