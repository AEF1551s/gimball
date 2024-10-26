#if !defined(STEPPER_H)
#define STEPPER_H

// CMSIS
#include <stm32f410rx.h>
#include <stm32f4xx.h>
// Type definitions
#include <stepperTypes.h>
#include <GPIOTypes.h>

// Testing purposes
#include <delay.h>

static void stepperPinInit();
void stepperInit();
void stepperConstantFreq(int stepCount);

#endif // STEPPER_H
