

#pragma once

#include <stdint.h>

#define   OUTPUT           (0)
#define   INPUT            (1)
#define   INPUT_PULLDOWN   (2)
#define   INPUT_PULLUP     (3)

#define   LOW    (0)
#define   HIGH   (1)

void pinMode(uint16_t pin, uint16_t mode);

void digitalWrite(uint16_t pin, uint16_t value);

uint32_t digitalRead(uint16_t pin);
