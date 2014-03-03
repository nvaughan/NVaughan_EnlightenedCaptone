#include <Adafruit_NeoPixel.h>
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
byte colors[3] = {
  0,0,0};
byte lineEnding = 0x0A;
int bpm;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(5);
  Serial.begin(115200);
  count = 1;
  randLight =1;
}


void loop()
{

  if(Serial.available()>2)
  {
    byte tempColors[3]= {colors[0],colors[1],colors[2]};
    int bytesRead = Serial.readBytesUntil(lineEnding,(char*)colors,3);
    if(colors[0] == 1)
    {
      bpm = colors[1];
      colors[0]= tempColors[0];
   colors[1]=tempColors[1];
  colors[2]=tempColors[2];
    }
  }else
  {
   colors[0] = 155;   colors[1] = 155;   colors[2] = 155;
  }
  

  // int val = analogRead(2);
  //  long delayVal;
  //  delayVal = val*(.2)*1000;
  //  Serial.println(delayVal);
  bpm = 98;
  int bpmMS = 60000/bpm+1;
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
  //  for(uint16_t i = 0; i<strip.numPixels();i++)
  //    for(uint16_t j = 0; j<256;j++)
  //      chaseLEDRainbow(chaseDelay8th,i,j);
  switch(randLight)
  {
  case 1:
    chaseLED(chaseDelay8th,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));

    break;
  case 2:
    chaseBothWays(chaseDelay8th,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));

    break;
  case 3:
    singleOnOff(chaseDelay8th,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
    singleOnOff(chaseDelay8th,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
    singleOnOff(chaseDelay8th,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));

    break;
  case 4:
    singleOff(chaseDelay8th,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
    singleOff(chaseDelay8th,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
    singleOff(chaseDelay8th,155,155,155);

    break;
  case 5:
    chaseInvert(chaseDelay8th,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));

    break;
  case 6:
    chaseInvertBoth(chaseDelay8th,map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));

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
  //chaseBothWays(chaseDelay8th,val,0,256-val);    
  // chaseInvertBoth(chaseDelay,val,0,256-val);    
  // }
}











