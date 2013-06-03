/*Switch bounce visualisation

Pulled down switch connected to pin 13, when pressed 
produces output as below with ' representing open and
# representing closed. Visualises switch bounce.

''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''
''''''''''''''''''''''''''''''''''''''''
''''''''#''''#'##########

*/

const int button = 13;
int closedCount = 0;

void setup() {
  pinMode(button, OUTPUT);
  Serial.begin(115200); //High rate for better resolution?
}

void loop() {
  
  while(closedCount < 10){
    for (int i = 0; i<50 ; i++) //this for loop inserts new lines to wrap text
      {
        if (digitalRead(button))
        {
          Serial.print("#");
          closedCount++;
        }
        else
        {
          Serial.print("'");
          closedCount=0;
        } 
        if (closedCount==10)   //Is there a more elegant solution to this?
        {
          break;
        }
      }
      Serial.print("\n");
    }
}
