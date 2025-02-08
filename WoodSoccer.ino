#include "CoinInput.h"
#include "Laser.h"
#include "Buzzer.h"

#define P1_SHOOTER_PIN 7
#define P2_SHOOTER_PIN 8
#define P1_RECEIVER_PIN 6
#define P2_RECEIVER_PIN 9

Laser p1_laser(P1_SHOOTER_PIN, P1_RECEIVER_PIN);
Laser p2_laser(P2_SHOOTER_PIN, P2_RECEIVER_PIN);

enum Phase
{
  PRE,
  MID,
  POST
};

Phase phase = PRE;

uint8_t p1_score = 0;
uint8_t p2_score = 0;

void pregame();
void midgame();
void postgame();
void UpdateScoreDisplay();

void setup()
{
  coin_input_setup();
}

void loop()
{
  if (phase == PRE)
  {
    pregame();
  }
  else if (phase == MID)
  {
    midgame();
  }
  else if (phase == POST)
  {
    postgame();
  }
}

void pregame()
{
  // Wait for the two players to each give a coin
  handle_pregame_coin_inputs();

  // Once the pregame is complete, turn on the lasers, reset scores, and change phase
  p1_laser.On();
  p2_laser.On();
  p1_score = 0;
  p2_score = 0;
  UpdateScoreDisplay();
  phase = MID;
}

void midgame()
{
  if (!p1_laser.IsReceiving())
  {
    p1_score++;
    Beep();
    UpdateScoreDisplay();
    p1_laser.Reset();
  }
  else if (!p2_laser.IsReceiving())
  {
    p2_score++;
    Beep();
    UpdateScoreDisplay();
    p2_laser.Reset();
  }

  if (p1_score >= 10 || p2_score >= 10)
  {
    phase = POST;
  }
}

void postgame()
{
  // Flash the winning score and dispense the money
  
  release_coins();
  phase = PRE;
}

void UpdateScoreDisplay()
{
  
}
