#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}
void loop() {
  int value = analogRead(A0);
  lcd.setCursor(0, 0);
  lcd.print("alak Value :");
  lcd.print(value);
  lcd.print("   ");
  Serial.println(value);
  lcd.setCursor(0, 1);
  lcd.print("shot level :");


  if (value == 0) {
    lcd.print("Wala ");
  } else if (value > 1 && value < 350) {
    lcd.print("LOW   ");
  } else if (value > 350 && value < 510) {
    lcd.print("Medium");
  } else if (value > 510){
    lcd.print("HIGH  ");
  }
}