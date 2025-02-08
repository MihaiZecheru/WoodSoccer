#ifndef COIN_SERVO_H
#define COIN_SERVO_H

#include <Servo.h>
#define COIN_SERVO_DATA_PIN 5

coin_servo coin_servo;

// Note: gate position is 165 when lowered
void lower_gate()
{
  // Move from 120 to 165 degrees in 1-degree steps
  for (int pos = 120; pos <= 165; pos++)
  {
    coin_servo.write(pos);
    delay(15);
  }
}

// Note: gate position is 120 when lifted
void lift_gate()
{
  // Move from 165 to 120 degrees in 1-degree steps
  for (int pos = 165; pos >= 120; pos--)
  {
    coin_servo.write(pos);
    delay(15);
  }
}

void release_coins()
{
  lift_gate();
  delay(1000);
  lower_gate();
}

void init_coin_servo()
{
  coin_servo.attach(coin_servo_DATA_PIN);
  delay(100);
  coin_servo.write(165);
}

#endif
