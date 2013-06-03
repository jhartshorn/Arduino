#include <Multiplex7Seg.h>

byte digitPins[] = { 3, 2}; // LSB to MSB
byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12}; // seg a to g

void setup() {
  Multiplex7Seg::set(0, 2, digitPins, segmentPins); // initialize 
  Serial.begin(9600);
  pinMode(A0, INPUT);

}

void loop() {
  printTemp();
  delay(1000);
}

double Thermister(int RawADC) {
  double Temp;
  // See http://en.wikipedia.org/wiki/Thermistor for explanation of formula
  Temp = log(((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 * Temp) + (0.0000000876741 * Temp * Temp * Temp));
  Temp = Temp - 273.15;           // Convert Kelvin to Celcius
  return Temp;
}

void printTemp(void) {

  double temp = Thermister(analogRead(A0));  // Read sensor
  Serial.println(analogRead(A0));
  Serial.println(temp);
  Multiplex7Seg::loadValue(temp);
 
}

