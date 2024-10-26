#include <stepper.h>

/* ------------DEFINE STEPPER POLE PINS,PORTS,STEP SEQUENCE------------ */

/*Reason for static const - I dont want anyone else except the stepper functions access this,
at the same time once its assigned, there should NOT be ANY changes made to pin configuration*/
static const stepper4PinConfig XStepperPins = {
    .pins = {PIN0, PIN1, PIN2, PIN3},
    .ports = {GPIOC_BASE, GPIOC_BASE, GPIOC_BASE, GPIOC_BASE}

};

// Set 0 and 1, reset 3
static const uint32_t stepMask0 = (1U << XStepperPins.pins[0]) | (1U << XStepperPins.pins[1]) | ((1U << XStepperPins.pins[3]) << 16);
// Set 1 and 2, reset 0
static const uint32_t stepMask1 = (1U << XStepperPins.pins[1]) | (1U << XStepperPins.pins[2]) | ((1U << XStepperPins.pins[0]) << 16);
// Set 2 and 3, reset 1
static const uint32_t stepMask2 = (1U << XStepperPins.pins[2]) | (1U << XStepperPins.pins[3]) | ((1U << XStepperPins.pins[1]) << 16);
// Set 3 and 0, reset 2
static const uint32_t stepMask3 = (1U << XStepperPins.pins[3]) | (1U << XStepperPins.pins[0]) | ((1U << XStepperPins.pins[2]) << 16);

static const stepperSequence sequence = {
    .stepMask = {stepMask0, stepMask1, stepMask2, stepMask3},
};

static int currentStep = 0;

/* ------------END DEFINE STEPPER POLE PINS,PORTS,STEP SEQUENCE------------ */

static void stepperPinInit()
{
    /* ------------X AXIS STEPPER PIN INIT------------ */

    // Enable GPIO port C.It uses HSI clock 16Mhz per instruction
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);

    // GPIO MODER mask for stepper pins
    static const uint32_t maskPin0 = OUTPUT << (XStepperPins.pins[0] * 2);
    static const uint32_t maskPin1 = OUTPUT << (XStepperPins.pins[1] * 2);
    static const uint32_t maskPin2 = OUTPUT << (XStepperPins.pins[2] * 2);
    static const uint32_t maskPin3 = OUTPUT << (XStepperPins.pins[3] * 2);

    static const uint32_t GPIOMask = maskPin0 | maskPin1 | maskPin2 | maskPin3;

    SET_BIT(GPIOC->MODER, GPIOMask);
    /* ------------X AXIS STEPPER PIN INIT END------------ */
}

void stepperInit()
{
    stepperPinInit();
    delayInit();
}

void stepperConstantFreq(int stepCount)
{
    for (int i = 0; i < stepCount; i++)
    {
        SET_BIT(GPIOC->BSRR, sequence.stepMask[currentStep]);
        delayMs(1);
        currentStep++;
        currentStep %= 4;
    }
}