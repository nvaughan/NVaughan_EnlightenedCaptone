void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.write('a');
  delay(15000);
  Serial.write('b');
  delay(15000);
}

