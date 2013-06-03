  /*
  LCD Timer
   
  Based on:

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int led = 0;
void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  lcd.clear();
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 1);
  // Print a message to the LCD.
  lcd.print("Detonation In:");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  if (millis()/1000 < 10)
  {
  delay(500);
  
  
  lcd.noDisplay();
  delay(500);
  lcd.clear();
  lcd.print("Detonation In:");
  lcd.display();

  // print the number of seconds since reset:
  lcd.setCursor(14,0);
  lcd.print((10 - millis()/1000));
    }
  else
  {
    lcd.clear();
    lcd.print("     <BANG>");
    
    digitalWrite(led, HIGH);
    delay(20000);
  }
}

