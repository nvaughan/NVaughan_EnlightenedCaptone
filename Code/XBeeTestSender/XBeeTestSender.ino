//http://lab.guilhermemartins.net/2008/12/24/serial-comunication-between-arduinos-with-wire-wireless/

int analogValue5, val5;

void setup() {
// Serial port enable
Serial.begin(19200);
}

void loop() {
// read analog pin 5
analogValue5 = analogRead(5);

// remap values from the analogValue5 variable to 0 / 255
val5 = map(analogValue5, 0, 1023, 0, 255);

// send the value to the serial port
Serial.println(val5, BYTE);

}
