// TESTED EDIT  19 Feb 2022  14:44 UTC
#include <Arduino.h>
#include "LiquidCrystal_I2C.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(void) {
    // Serial.begin(9600);
    lcd.begin();
    lcd.backlight();
    lcd.print("Hello, world!");
}

void loop() {
    while(-1);
    // Serial.println("ERROR .. loop escape");
}
// END.
