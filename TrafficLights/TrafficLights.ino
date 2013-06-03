int green = 13;
int amber = 12;
int red = 11;
int button = 10;
int stopLightOn = 0;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(amber, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(button, INPUT);
  
  digitalWrite(green, LOW); //Begin on red light 
  digitalWrite(amber, LOW);
  digitalWrite(red, HIGH); 
  stopLightOn = 1;
}

void loop() {
  while(digitalRead(button)==0) {}; //wait until button pressed

  if (stopLightOn == 1)
  { goSequence(); }
  else
  { stopSequence(); }  
}

void stopSequence() {
  digitalWrite(green, LOW);
  digitalWrite(amber, HIGH);
  delay(1000);
  digitalWrite(amber, LOW);
  digitalWrite(red, HIGH);  
  stopLightOn = 1;
}

void goSequence() {
  digitalWrite(amber, HIGH);
  delay(1000);
  digitalWrite(green, HIGH);
  digitalWrite(amber, LOW);
  digitalWrite(red, LOW);
  stopLightOn = 0;
}
