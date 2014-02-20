//http://lab.guilhermemartins.net/2013/08/01/new-basic-arduino-serial-communication/
// SENDER
int b1 = 7;
int b2 = 8;

void setup()
{
Serial.begin(9600);
pinMode(b1, INPUT);
pinMode(b2, INPUT);
digitalWrite(b1, HIGH);
digitalWrite(b2, HIGH);
}

void loop()
{
byte val1 = (byte)digitalRead(b1);
byte val2 = (byte)digitalRead(b2);
Serial.write(‘a’); //SYNC char

Serial.write(‘b’); //SYNC char

delay(50);
}
