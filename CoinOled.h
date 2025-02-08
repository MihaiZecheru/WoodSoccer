#ifndef COIN_OLED_H
#define COIN_OLED_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define COIN_OLED_DISPLAY_WIDTH 128
#define COIN_OLED_DISPLAY_HEIGHT 32

// No reset pin used for OLED (-1)
Adafruit_SSD1306 display(-1);

void ShowMessage_Insert2Coins()
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Insert 2");
  display.setCursor(0, 16);
  display.print("Coins");
  display.display();
}

void ShowMessage_Insert1Coin()
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Insert 1");
  display.setCursor(0, 16);
  display.print("Coin");
  display.display();
}

void ShowMessage_GameOn()
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Game On");
  display.display();
}

#endif