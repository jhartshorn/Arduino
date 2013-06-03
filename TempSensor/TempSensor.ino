/*Thermistor based temp sensor with 3 LED indicator */f

int green = 13;
int orange = 12;
int red = 11;
int greenTemp = 18;
int orangeTemp = 24;
int redTemp = 30;

void setup() {
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(red, OUTPUT);
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
  Serial.println("  ");
  if (temp > greenTemp)
  {
    digitalWrite(green, HIGH);
  }
  
  if (temp > orangeTemp)
  {
    digitalWrite(orange, HIGH);
  }
  
  if (temp > redTemp)
  {
    digitalWrite(red, HIGH);
  }
  
  
  if (temp < greenTemp)
  {
    digitalWrite(green, LOW);
  }
  
  if (temp < orangeTemp)
  {
    digitalWrite(orange, LOW);
  }
  
  if (temp < redTemp)
  {
    digitalWrite(red, LOW);
  }
}

