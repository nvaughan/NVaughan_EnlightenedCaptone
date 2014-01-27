/****************************************
 * Example Sound Level Sketch for the 
 * Adafruit Microphone Amplifier
 ****************************************/
//#include <BPMChaserTest.h>
#include <Adafruit_NeoPixel.h>



const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8,6, NEO_GRB + NEO_KHZ800);
unsigned long beatIntervals[60];
const unsigned long BPMAccuracy15Seconds = 15000;
const unsigned long BPMAccuracy10Seconds = 10000;
const unsigned long BPMAccuracy5Seconds = 5000;
unsigned long startMilli;
unsigned long averageArray[20];
int count,chaseCount,randLight;
int roughBPM = 100;
unsigned long average,averageAv = 0;
int countAverage;
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
  countAverage =1;
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

  if((peakToPeak<160 && peakToPeak>120)|| peakToPeak >160)
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
    //    Serial.print("Since last 'beat' ");
    //    Serial.println(startMilli - millis());
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
    averageArray[countAverage] = average;
    Serial.print("Average: ");
    Serial.println(average);
    count = 1;
    average = 0;
    startMilli = millis();
    countAverage +=1;

  }
  if(countAverage ==20)
  {
    for(int i =1; i <=20;i++)
    {
      averageAv += averageArray[i];
    }
    averageAv = averageAv/20;
    Serial.print("Average Average: ");
    Serial.println(averageAv);
    averageAv = 0;
  }

  //  while(startMillis-millis() <= 120000)
  //  {
  //    start(roughBPM);
  //  }
}


void start(int _BPM) {
  //  strip.begin();
  //  strip.show(); // Initialize all pixels to 'off'
  //  strip.setBrightness(5);
  Serial.begin(9800);
  chaseCount = 1;
  randLight =1;
  lightLoop(_BPM);
}


void lightLoop(int _BPM)
{
  int val = analogRead(2);
  //  long delayVal;
  //  delayVal = val*(.2)*1000;
  //  Serial.println(delayVal);
  int BPM = _BPM;
  int bpmMS = 60000/BPM+1;
  int bpm8thMS = bpmMS/2;
  int bpm12thMS = bpm8thMS/2;
  int bpm6thMS = bpmMS*2/3;
  int bpm3rdMS = bpmMS*4/3;
  //  Serial.println(bpm3rdMS);
  //  Serial.println(bpmMS);
  //  Serial.println(bpm6thMS);
  //  Serial.println(bpm8thMS);
  long chaseDelay = bpmMS/7;
  long chaseDelay8th = bpm8thMS/7;
  int chaseDelay6th = bpm6thMS/7;
  int chaseDelay3rd = bpm3rdMS/7;
  int chaseDelay12th = bpm12thMS/7;
  //chaseLED(chaseDelay8th);

  //chaseBothWays(chaseDelay);
  //chaseBothWays(chaseDelay8th);
  //chaseBothWays(chaseDelay8th);
  //int randLight =1;
  int totalRepeat = 10;
  count++;
  Serial.println(count);
  if(count == totalRepeat)
  {
    Serial.println("Here");
    randLight = random(1,6);
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


  //  if(val < 341)
  //  {
  //    val=(val*3)/4;
  //    //chaseBothWays(chaseDelay8th,(265-val),val,0);
  //    chaseInvertBoth(chaseDelay,(265-val),val,0);
  //  }
  //  else if(val < 682)
  //  {
  //    val=((val-341)*3)/4;
  //    // chaseBothWays(chaseDelay8th,0,256-val,val);    
  //    chaseInvertBoth(chaseDelay,0,256-val,val);    
  //  }
  //  else
  //  {
  //    val=((val-683)*3)/4;
  //    //chaseBothWays(chaseDelay8th,val,0,256-val);    
  //   chaseInvertBoth(chaseDelay,val,0,256-val);    
  //  }
}

void chaseLED(int chaseDelay,int red,int green,int blue)
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
}

void singleOnOff(int chaseDelay,int red, int green,int blue)
{
  int pixel = random(0,8);
  // int pixel2 = random(0,8);
  strip.setPixelColor(pixel,red,green,blue);
  // strip.setPixelColor(pixel2,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(pixel,0,0,0);
  //strip.setPixelColor(pixel2,0,0,0);
  strip.show();
  delay(chaseDelay);
}

void singleOff(int chaseDelay,int red, int green,int blue)
{
  int pixel = random(0,8);
  //  int pixel2 = random(0,8);
  strip.setPixelColor(0,red,green,blue);
  strip.setPixelColor(1,red,green,blue);
  strip.setPixelColor(2,red,green,blue);
  strip.setPixelColor(3,red,green,blue);
  strip.setPixelColor(4,red,green,blue);
  strip.setPixelColor(5,red,green,blue);
  strip.setPixelColor(6,red,green,blue);
  strip.setPixelColor(7,red,green,blue);
  strip.setPixelColor(pixel,0,0,0);
  //strip.setPixelColor(pixel2,0,0,0);
  strip.show();
  delay(chaseDelay);
}

void chaseInvert(int chaseDelay,int red, int green,int blue)
{
  strip.setPixelColor(0,red,green,blue);
  strip.setPixelColor(1,red,green,blue);
  strip.setPixelColor(2,red,green,blue);
  strip.setPixelColor(3,red,green,blue);
  strip.setPixelColor(4,red,green,blue);
  strip.setPixelColor(5,red,green,blue);
  strip.setPixelColor(6,red,green,blue);
  strip.setPixelColor(7,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(0,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(0,red,green,blue);
  strip.setPixelColor(1,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(1,red,green,blue);
  strip.setPixelColor(2,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(2,red,green,blue);
  strip.setPixelColor(3,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(3,red,green,blue);
  strip.setPixelColor(4,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(4,red,green,blue);
  strip.setPixelColor(5,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(5,red,green,blue);
  strip.setPixelColor(6,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(6,red,green,blue);
  strip.setPixelColor(7,0,0,0);
  strip.show();
  delay(chaseDelay);
}

void chaseInvertBoth(int chaseDelay,int red, int green,int blue)
{
  strip.setPixelColor(0,red,green,blue);
  strip.setPixelColor(1,red,green,blue);
  strip.setPixelColor(2,red,green,blue);
  strip.setPixelColor(3,red,green,blue);
  strip.setPixelColor(4,red,green,blue);
  strip.setPixelColor(5,red,green,blue);
  strip.setPixelColor(6,red,green,blue);
  strip.setPixelColor(7,red,green,blue);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(0,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(0,red,green,blue);
  strip.setPixelColor(1,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(1,red,green,blue);
  strip.setPixelColor(2,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(2,red,green,blue);
  strip.setPixelColor(3,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(3,red,green,blue);
  strip.setPixelColor(4,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(4,red,green,blue);
  strip.setPixelColor(5,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(5,red,green,blue);
  strip.setPixelColor(6,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(6,red,green,blue);
  strip.setPixelColor(7,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(7,red,green,blue);
  strip.setPixelColor(6,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(6,red,green,blue);
  strip.setPixelColor(5,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(5,red,green,blue);
  strip.setPixelColor(4,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(4,red,green,blue);
  strip.setPixelColor(3,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(3,red,green,blue);
  strip.setPixelColor(2,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(2,red,green,blue);
  strip.setPixelColor(1,0,0,0);
  strip.show();
  delay(chaseDelay);
  strip.setPixelColor(1,red,green,blue);
  strip.setPixelColor(0,0,0,0);
  strip.show();
  delay(chaseDelay);
}



uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}























