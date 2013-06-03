//7 Segment Digital Display Counter

int a = 7; //define pins for 7S display
int b = 6;
int c = 5;
int d = 4;
int e = 3;
int f = 2;
int g = 0;

int counter = 0;
int pb = 12;

void setup()
{

  for (int i = 1; i < 8; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);  //using common cathode device, so HIGH turns sink off
    pinMode(pb, INPUT);
    digitalWrite(pb, HIGH);
    
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
  }
 
  
}

void loop()
{
  //Serial.println(counter);
  lightLed(counter+1);
  
  if (digitalRead(pb)==LOW)
  {

    counter++;

  }

  delay(200);
  
  
}

void lightLed(int n)
{
  switch(n)
  {
    case 0:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW); 
    digitalWrite(d, LOW); 
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    break;
 
        case 1:
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW); 
    digitalWrite(d, HIGH); 
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    break;
 
        case 2:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH); 
    digitalWrite(d, LOW); 
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    break;
        case 3:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW); 
    digitalWrite(d, LOW); 
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    break;
 
        case 4:
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW); 
    digitalWrite(d, HIGH); 
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
 
        case 5:
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW); 
    digitalWrite(d, LOW); 
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
 
        case 6:
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW); 
    digitalWrite(d, LOW); 
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    break;
 
        case 7:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW); 
    digitalWrite(d, HIGH); 
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    break;
 
        case 8:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW); 
    digitalWrite(d, LOW); 
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
 
        case 9:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW); 
    digitalWrite(d, LOW); 
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    break;
  }
}
