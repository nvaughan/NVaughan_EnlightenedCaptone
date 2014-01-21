#include <Adafruit_NeoPixel.h>
int sensorValue = 0;
float variance = 0.96;

int newHigh = 0;
int counter = 0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8,6, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(5);

  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(A5);

  if (sensorValue > newHigh) {
    newHigh = sensorValue * variance;
    counter = 0;

    Serial.println("beat");
    strip.setPixelColor(0,155,155,155);
    strip.show();
  } else {
    Serial.println(" ");
    strip.setPixelColor(0,0,0,0);
    strip.show();
  }

  counter = counter + 1;
  if (counter > 50) {
    counter = 0;
    newHigh = newHigh * variance;
  }

  delay(1);
}
