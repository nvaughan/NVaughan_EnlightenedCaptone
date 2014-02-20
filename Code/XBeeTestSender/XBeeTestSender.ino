void setup()
{
Serial.begin(9600);
}

void loop()
{

Serial.write('a');
delay(50);
Serial.write('b');
delay(50);
}
