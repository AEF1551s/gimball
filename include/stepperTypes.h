// CMSIS
#include <stm32f410rx.h>
#include <stm32f4xx.h>
// GPIO Types
#include <GPIOTypes.h>

// Type definition for 4 phase stepper motor used pins
typedef struct
{
    // Pin ID 0-15
    uint8_t pins[4];
    // Port 32bit registers
    uint32_t ports[4];

} stepper4PinConfig;

// Full step 4 phase sequence
typedef struct
{
    uint32_t stepMask[4];
} stepperSequence;