/*Using a dual 4-bit SR as an 8-bit SR */

int clock = 10; //CLOCK A Pin
int data = 12; //DATA A Pin
int reset = 11; //RESET A Pin

//CLOCK B, and RESET B are pinned to corresponding A pins, DATA B is triggered by Q4A
//Effectively turning the chip into an 8-bit shift register

float clockDel = 0.01; //pulse width of clock signal



void setup() {
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(reset, OUTPUT);

}

void loop() {
  //cycle throught the varios demo loops
  diag(2);
  chase(2);
  wipe(2);
  expand(2);
  bounce(2);
  horiz(2);
  vert(2);
  

  
}

int clockCycle(int count) //Send 'count' clock pulses
{
  for (int n = 0; n < count; n++)
  {
    digitalWrite(clock, HIGH);
    delay(clockDel);
    digitalWrite(clock, LOW);
    delay(clockDel);
  }
}
  
void resetShift() //reset shift register
{
    digitalWrite(reset, HIGH);
    delay(clockDel);
    digitalWrite(reset, LOW);
    delay(clockDel);
}

void lightSeq(byte seq, int del) //display pattern corresponding to byte:
// 16   32   64   128
//
// 8    4    2    1
{
  
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(data, bitRead(seq, i)); //1st led
    clockCycle(1);
  }
  
  
  delay(del);
}


//Demo loops
void chase(int rep)
{
  for (int x = 0; x < rep; x++)
  {
    lightSeq(B10000000,100);
    lightSeq(B01000000,100);
    lightSeq(B00100000,100);
    lightSeq(B00010000,100);
    lightSeq(B00001000,100);
    lightSeq(B00000100,100);
    lightSeq(B00000010,100);
    lightSeq(B00000001,100);
  }
}

void wipe(int rep)
{
  for (int x = 0; x < rep; x++)
  {
    lightSeq(B00000000,100);
    lightSeq(B10000001,100);
    lightSeq(B11000011,100);
    lightSeq(B11100111,100);
    lightSeq(B11111111,100);
    lightSeq(B11100111,100);
    lightSeq(B11000011,100);
    lightSeq(B10000001,100);
  }
}

void expand(int rep)
{
  for (int x = 0; x < rep; x++)
  {
    lightSeq(B00000000,200);
    lightSeq(B01100110,200);
    lightSeq(B11111111,200);
    lightSeq(B01100110,200);

  }
}

void bounce(int rep)
{
  for (int x = 0; x < rep; x++)
  {
    lightSeq(B10000000,100);
    lightSeq(B01000000,100);
    lightSeq(B00100000,100);
    lightSeq(B00010000,100);
    lightSeq(B00001000,100);
    lightSeq(B00000100,100);
    lightSeq(B00000010,100);
    lightSeq(B00000001,100);
    lightSeq(B00000010,100);    
    lightSeq(B00000100,100);    
    lightSeq(B00001000,100);    
    lightSeq(B00010000,100);    
    lightSeq(B00100000,100);    
    lightSeq(B01000000,100);    
    lightSeq(B10000000,100);
  }
}

void horiz(int rep)
{
  for (int x = 0; x < rep; x++)
  {
    lightSeq(B11110000,500);
    lightSeq(B00001111,500);
  }
}

void vert(int rep)
{
  for (int x = 0; x < rep; x++)
  {
    lightSeq(B00111100,500);
    lightSeq(B11000011,500);
  }
}

void diag(int rep)
{
  for (int x = 0; x < rep; x++)
  {
    lightSeq(B00010001,200);
    lightSeq(B10111011,200);
    lightSeq(B11111111,200);
    lightSeq(B11101110,200);
    lightSeq(B01000100,200);
    lightSeq(B00000000,200);
  }
}


