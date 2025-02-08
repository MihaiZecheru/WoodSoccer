#ifndef LASER_H
#define LASER_H

class Laser
{
private:
  const uint8_t shooter_pin;
  const uint8_t input_pin;

public:
  Laser(const uint8_t _shooter_pin, const uint8_t _input_pin) : shooter_pin(_shooter_pin), input_pin(_input_pin)
  {
    pinMode(_shooter_pin, OUTPUT);
    pinMode(_input_pin, INPUT);
  }

  void On()
  {
    digitalWrite(shooter_pin, HIGH);
  }

  void Off()
  {
    digitalWrite(shooter_pin, LOW);
  }

  bool IsReceiving()
  {
    return digitalRead(input_pin);
  }

  /**
   * Wait for the laser to stop receiving
   */
  void Reset()
  {
    uint8_t i = 0;
    while (i < 5)
    {
      // Wait for 5 ticks of the laser receiving the signal
      if (this->IsReceiving()) i++;
      else i = 0;
    }
  }
};

#endif