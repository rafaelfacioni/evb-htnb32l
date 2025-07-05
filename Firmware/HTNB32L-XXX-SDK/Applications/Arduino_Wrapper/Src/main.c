
#include "bsp.h"

#include "Arduino_Wrapper.h"

static const uint16_t kPinLed = 7;
static const uint16_t kButton = 2;

static int counter = 0;

void main_entry(void) {
    pinMode(kPinLed, OUTPUT);
    pinMode(kButton, INPUT_PULLDOWN);
    digitalWrite(kPinLed, HIGH);

    while(counter < 4) {
        if(digitalRead(kButton) == 1) {
            delay_us(250000);
            digitalWrite(kPinLed, LOW);
            counter++;
        }
    }

    while(1) {
        digitalWrite(kPinLed, HIGH);
        delay_us(500000);
        digitalWrite(kPinLed, LOW);
        delay_us(500000);
    }
}
