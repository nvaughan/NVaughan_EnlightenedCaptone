#include "LowPassFilter.c"

//The number of samples to buffer before analyzing them
int samplesN = 1000;
int micPin = 0;

LowPassFilter filter;

void setup(){
  Serial.begin(9600);
  filter = new LowPassFilter();
  LowPassFilter_init(filter);
}

void loop(){
  long pow = 0;
  long filtpow = 0;
  int peak = 0;
  long start = millis();
  for(int k=0; k<samplesN; k++){
    int val = analogRead(micPin);
    LowPassFilter_put(filter, val);

    int filtered = LowPassFilter_get(filter);

    pow += ((long)val*(long)val)/samplesN;
    filtpow += ((long)filtered*(long)filtered)/samplesN;
    peak = max(peak, filtered);
  }
  long end = millis(); 
  float freq = ((float)samplesN * (float)1000) / ((float)end - (float)start);

  Serial.print(freq);
  Serial.print(" ");
  Serial.print(pow);
  Serial.print(" ");
  Serial.print(filtpow);
  Serial.print(" ");
  Serial.println(peak);
}
