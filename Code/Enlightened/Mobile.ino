void mobile()
{
   if(Serial.available()>3)
  {
    int bytesRead = Serial.readBytesUntil(lineEnding,(char*)colors,3);
  }
  setAllPixels(map(colors[0],0,255,0,255),map(colors[1],0,255,0,255),map(colors[2],0,255,0,255));
  strip.show();
}

void setAllPixels(int red,int green,int blue)
{
  strip.setPixelColor(0,red,green,blue);
  strip.setPixelColor(1,red,green,blue);
  strip.setPixelColor(2,red,green,blue);
  strip.setPixelColor(3,red,green,blue);
  strip.setPixelColor(4,red,green,blue);
  strip.setPixelColor(5,red,green,blue);
  strip.setPixelColor(6,red,green,blue);
  strip.setPixelColor(7,red,green,blue);
}
