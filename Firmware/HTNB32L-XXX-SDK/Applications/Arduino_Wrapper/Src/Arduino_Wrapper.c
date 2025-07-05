
#include "Arduino_Wrapper.h"

#include "pad_qcx212.h"
#include "ic_qcx212.h"
#include "HT_ic_qcx212.h"
#include "HT_gpio_qcx212.h"

#define INIT_PAD (12)
#define GET_PAD_ID(pin) ((pin - 1) + INIT_PAD)

static const uint32_t kPinInstance = 0;

void pinMode(uint16_t pin, uint16_t mode) {
  GPIO_InitType GPIO_InitStruct = {0};
  
  if(mode == OUTPUT) {
    GPIO_InitStruct.pin_direction = GPIO_DirectionOutput;
    GPIO_InitStruct.pull = PAD_AutoPull;
  }else if(mode == INPUT) {
     GPIO_InitStruct.pin_direction = GPIO_DirectionInput;
  }else if(mode == INPUT_PULLDOWN) {
     GPIO_InitStruct.pull = PAD_InternalPullDown;
      GPIO_InitStruct.pin_direction = GPIO_DirectionInput;
  }else if(mode == INPUT_PULLUP) {
    GPIO_InitStruct.pull = PAD_InternalPullUp;
     GPIO_InitStruct.pin_direction = GPIO_DirectionInput;
  }

  GPIO_InitStruct.af = PAD_MuxAlt0;
  GPIO_InitStruct.pad_id = GET_PAD_ID(pin);
  GPIO_InitStruct.gpio_pin = pin;
  GPIO_InitStruct.init_output = 0;
  GPIO_InitStruct.instance = kPinInstance;
  GPIO_InitStruct.exti = GPIO_EXTI_DISABLED;
  HT_GPIO_Init(&GPIO_InitStruct);
}

void digitalWrite(uint16_t pin, uint16_t value) {
   HT_GPIO_WritePin(pin, kPinInstance, value);
}

uint32_t digitalRead(uint16_t pin) {
  return HT_GPIO_PinRead(kPinInstance, pin);
}
