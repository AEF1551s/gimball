// CMSIS
#include <stm32f410rx.h>
#include <stm32f4xx.h>

// STEPPER MOTOR
#include <stepper.h>

int main()
{

    stepperInit();

    stepperConstantFreq(200);

    return 1;
}