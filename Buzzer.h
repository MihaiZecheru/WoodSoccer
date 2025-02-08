#ifndef BUZZER_H
#define BUZZER_H

#define BUZZER_PIN 3

void Beep()
{
  tone(BUZZER_PIN, 3000, 200);
}

#endif
