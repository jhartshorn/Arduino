#include <Multiplex7Seg.h>

byte digitPins[] = {0, 1, 2, 3}; // LSB to MSB
byte segmentPins[] = {13, 12, 11, 10, 9, 8, 7}; // seg a to g
int time = 6;
long time_msec = time*3600000;
int buzz = 5;

void setup()
{
/* set(byte enableZB, byte _noOfDigits, byte digitPins, byte segmentPins)
   enableZB activates zero leading blanking on the digits. 1 == ON, 0 == OFF
   digitPins array stores the 7 segment digits from LSB (0 digit) to MSB (4 digit max)
   segmentPins array stores the segments of the digits from a to g
*/
  Multiplex7Seg::set(1, 4, digitPins, segmentPins); // initialize 
  pinMode(buzz, OUTPUT);
  
}

void loop()
{ 
  
  for (int i = 100; i >= 0; i--) // 9999 ~ 7hrs
  {
    Multiplex7Seg::loadValue(i); // load any int value
    delay(time_msec/100);
  }
  
  while(1)
  {
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(400);
  }

  
}


