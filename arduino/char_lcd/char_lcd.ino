#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 8, 9, 10, 11);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Welcome to");
  lcd.setCursor(0,1);
  lcd.print("5P.IO");
}

void loop() {
 
}
