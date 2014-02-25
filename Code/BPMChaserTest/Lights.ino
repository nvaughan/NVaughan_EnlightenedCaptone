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
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}


