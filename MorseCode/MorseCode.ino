const int inLength = 250;
const int inTerminator = 13;
char inString[inLength+1];
int inCount;
int outCount;
const int buzzer = 13;
const int eolDelay = 250;
const int dashLength = 200;
const int dotLength = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  

}

void loop() {
  inCount = 0;
  outCount = 0;
  do {
    while (!Serial.available());             // wait for input
    inString[inCount] = Serial.read();       // get it
    if (inString [inCount] == inTerminator) break;
  } while (++inCount < inLength);
  inString[inCount] = 0;                     // null terminate the string
  
  Serial.print(inString);
  Serial.print("\n");
  outCount=0;
  while ( outCount < inLength)
  {
    encodeLetter(inString[outCount]);
    Serial.print("\n");
    outCount++;
  }


  
  for (int j=0; j < inLength ; j++)
  {
    inString[j]='0';
  } 
  
}

  void dot()
  {
    Serial.print(".");
    digitalWrite(buzzer, HIGH);
    delay(dotLength);
    digitalWrite(buzzer, LOW);
    delay(150);
    
  }
  
  void dash()
  {
    Serial.print("_ ");
        digitalWrite(buzzer, HIGH);
    delay(dashLength);
    digitalWrite(buzzer, LOW);
    delay(200);
  }
  
  void encodeLetter(char letter)
  {
    switch (inString[outCount])
    {
      case 'a':
        dot(); dash(); delay(eolDelay); 
        break;
      case 'b':
        dash(); dot(); dot(); dot(); delay(eolDelay); 
        break;
      case 'c':
        dash(); dot(); dash(); dot(); delay(eolDelay); 
        break;
      case 'd':
        dash(); dot(); dot(); delay(eolDelay); 
        break;
      case 'e':
        dot(); delay(eolDelay); 
        break;
      case 'f':
        dot(); dot(); dash(); dot(); delay(eolDelay); 
        break;
      case 'g':
        dash(); dash(); dot(); delay(eolDelay); 
        break;
      case 'h':
        dot(); dot(); dot(); dot(); delay(eolDelay); 
        break;
      case 'i':
        dot(); dot(); delay(eolDelay); 
        break;
      case 'j':
        dot(); dash(); dash(); dash(); delay(eolDelay); 
        break;
      case 'k':
        dash(); dot(); dash(); delay(eolDelay); 
        break;
      case 'l':
        dot(); dash(); dot(); dot(); delay(eolDelay); 
        break;
      case 'm':
        dash(); dash(); delay(eolDelay); 
        break;
      case 'n':
        dash(); dot(); delay(eolDelay); 
        break;
      case 'o':
        dash(); dash(); dash(); delay(eolDelay); 
        break;
      case 'p':
        dot(); dash(); dash(); dot(); delay(eolDelay); 
        break;
      case 'q':
        dash(); dash(); dot(); dash(); delay(eolDelay); 
        break;
      case 'r':
        dot(); dash(); dot(); delay(eolDelay); 
        break;
      case 's':
        dot(); dot(); dot(); delay(eolDelay); 
        break;
      case 't':
        dash(); delay(eolDelay); 
        break;
      case 'u':
        dot(); dot(); dash(); delay(eolDelay); 
        break;
      case 'v':
        dot(); dot(); dot(); dash(); delay(eolDelay); 
        break;
      case 'w':
        dot(); dash(); dash(); delay(eolDelay); 
        break;
      case 'x':
        dash(); dot(); dot(); dash(); delay(eolDelay); 
        break;
      case 'y':
        dash(); dot(); dash(); dash(); delay(eolDelay); 
        break;
      case 'z':
        dash(); dash(); dot(); dot(); delay(eolDelay); 
        break;
      case ' ':
        delay(800);
        break;
    }
  }
    

