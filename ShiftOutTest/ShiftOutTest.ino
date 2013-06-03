int clock = 10;
int data = 12;
int reset = 11;

float clockDel = 0.01; //pulse width

void setup() {
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(reset, OUTPUT);
  
}

void loop() {

  
  lightSeq(0,0,0,0,200);
  lightSeq(0,0,0,1,200);
  lightSeq(0,0,1,0,200);
  lightSeq(0,1,0,0,200);
  lightSeq(1,0,0,0,200);
  lightSeq(0,1,0,0,200);
  lightSeq(0,0,1,0,200);
  lightSeq(0,0,0,1,200);
  lightSeq(0,0,1,1,200);
  lightSeq(0,1,1,1,200);
  lightSeq(1,1,1,1,200);
  lightSeq(0,1,1,1,200);
  lightSeq(0,0,1,1,200);
  lightSeq(0,0,0,1,200);
  lightSeq(0,0,0,0,200);
  lightSeq(1,0,0,1,200);
  lightSeq(0,1,1,0,200);
  lightSeq(0,1,1,0,10);
  lightSeq(0,0,0,0,20);
  lightSeq(0,1,1,0,10);
  lightSeq(0,0,0,0,20);
  lightSeq(1,0,0,1,200);
  
  for (int i = 0; i < 4; i++)
  {
    lightSeq(0,1,0,1,200);
    lightSeq(1,0,1,0,200);
  }
  
}

int clockCycle(int count)
{
  for (int n = 0; n < count; n++)
  {
    digitalWrite(clock, HIGH);
    delay(clockDel);
    digitalWrite(clock, LOW);
    delay(clockDel);
  }
}
  
void resetShift()
{
    digitalWrite(reset, HIGH);
    delay(clockDel);
    digitalWrite(reset, LOW);
    delay(clockDel);
}

void lightSeq(int a, int b, int c, int d, int del)
{
  digitalWrite(data, a); //1st led
  clockCycle(1);
  digitalWrite(data, b); //2nd led
  clockCycle(1);
  digitalWrite(data, c); //3rd led
  clockCycle(1);
  digitalWrite(data, d); //4th led
  clockCycle(1);
  
  delay(del);
}
