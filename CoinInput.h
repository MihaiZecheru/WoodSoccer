#ifndef COIN_INPUT_H
#define COIN_INPUT_H

#include "CoinOled.h"
#include "Laser.h"
#include "Buzzer.h"
#include "Servo.h"

#define COIN_LASER_SHOOTER_PIN 4
#define COIN_LASER_RECEIVER_PIN 2

// (shooter pin, receiver pin)
Laser coin_laser(COIN_LASER_SHOOTER_PIN, COIN_LASER_RECEIVER_PIN);

void coin_input_setup()
{
  // Initialize the OLED with I2C address 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  // Show idle message
  ShowMessage_Insert2Coins();
  // Enable laser
  coin_laser.On();
  // Setup servo motor
  init_servo();
  delay(500);
}

void handle_pregame_coin_inputs()
{
  uint8_t coins_received = 0;

  while (true)
  {
    if (coin_laser.IsReceiving()) continue;
    
    coins_received++;
    if (coins_received == 1)
    {
      Beep();
      ShowMessage_Insert1Coin();
      coin_laser.Reset();
    }
    else if (coins_received == 2)
    {
      Beep();
      ShowMessage_GameOn();
      coin_laser.Off();
      break;
    }
  }
}

#endif
