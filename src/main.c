// CMSIS
#include <stm32f410rx.h>
#include <stm32f4xx.h>

// STEPPER MOTOR
#include <stepper.h>

int main()
{

    stepperInit();
    for (int i = 0; i < 20; i++)
    {
        stepperConstantFreq(200, REVERSE);
        stepperConstantFreq(200, FORWARD);
    }
}