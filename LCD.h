#ifndef LCD_H_
#define LCD_H_


#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4
// LiquidCrystal_I2C lcd(0x27, 20, 4);

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);


void LCD_init()
{   
  lcd.begin(20, 4);
  lcd.init();
  lcd.backlight();
  }
#endif
