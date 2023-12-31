/*
 * Interactive nametag sketch for ATtiny85. Based on the Digispark
 * ATtiny LCD example and the Adafruit "Measuring Sound Levels" example.
 * Every 12000 milliseconds will change the display from my name to my website.
 * On the second line, will measure and display sound levels.
 * For more info check: https://platis.solutions/blog/2015/03/22/diy-interactive-name-tag/
 * ATtiny85 I2C pins:
 * ATtiny Pin 5 = SDA on DS1621  & GPIO
 * ATtiny Pin 7 = SCK on DS1621  & GPIO
 */

#include "TinyWireM.h"                  // I2C Master lib for ATTinys which use USI - comment this out to use with standard arduinos
#include <LiquidCrystal_attiny.h>          // for LCD w/ GPIO MODIFIED for the ATtiny85

#define GPIO_ADDR     0x27
LiquidCrystal_I2C lcd(GPIO_ADDR, 16, 2); // set address & 16 chars / 2 lines

const short micPin = A3;
const short sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
const unsigned long nameInterval = 12000;
unsigned long prevNameChange = 0;
short state = 1;
unsigned int sample;

int i = 0;

void setup() {
  lcd.init();                           // initialize the lcd
  lcd.backlight();                      // Print a message to the LCD.
}

void loop() {
  printName();
}

void printName() {

  int x = 113;
  
  String s = "platis";
  s += x;
  
  if (millis() - prevNameChange > 10) {
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.print(s[i]);
    
    prevNameChange = millis();
  }

  i ++;
  if (i > 16) i = 0;
}
