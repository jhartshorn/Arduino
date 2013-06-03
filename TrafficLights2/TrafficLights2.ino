int green1 = 11; //remember resistor!
int amber1 = 12;
int red1 = 13;
int green2 = 8;
int amber2 = 9;
int red2 = 10;

int button = 7; //pulled down

int stopLight1On = 0;
int stopLight2On = 0;

void setup() {
  pinMode(green1, OUTPUT);
  pinMode(amber1, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(amber2, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(button, INPUT);
  
  digitalWrite(green1, LOW); //Begin on with system 1 on red light 
  digitalWrite(amber1, LOW);
  digitalWrite(red1, HIGH); 
  digitalWrite(green2, HIGH); //Begin on with system 1 on red light 
  digitalWrite(amber2, LOW);
  digitalWrite(red2, LOW); 
  
  stopLight1On = 1;
  stopLight2On = 0;
}


void loop() {
  while(digitalRead(button)==0) {}; //wait until button pressed

  if (stopLight1On == 1)
  { 
    stopSequence2();
    delay(800);
    goSequence1();
  }
  else
  { 
    stopSequence1(); 
    delay(800);
    goSequence2();
  }  
}

void stopSequence1() {
  digitalWrite(green1, LOW);
  digitalWrite(amber1, HIGH);
  delay(1500);
  digitalWrite(amber1, LOW);
  digitalWrite(red1, HIGH);  
  stopLight1On = 1;
}

void goSequence1() {
  digitalWrite(amber1, HIGH);
  delay(1500);
  digitalWrite(green1, HIGH);
  digitalWrite(amber1, LOW);
  digitalWrite(red1, LOW);
  stopLight1On = 0;
}

void stopSequence2() {
  digitalWrite(green2, LOW);
  digitalWrite(amber2, HIGH);
  delay(1500);
  digitalWrite(amber2, LOW);
  digitalWrite(red2, HIGH);  
  stopLight2On = 1;
}

void goSequence2() {
  digitalWrite(amber2, HIGH);
  delay(1500);
  digitalWrite(green2, HIGH);
  digitalWrite(amber2, LOW);
  digitalWrite(red2, LOW);
  stopLight2On = 0;
}
