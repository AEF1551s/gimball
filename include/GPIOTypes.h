#if !defined(GPIO_TYPES_H)
#define GPIO_TYPES_H

// GPIO MODE register values
typedef enum GPIOMode
{
    INPUT = 0x0U,
    OUTPUT = 0x1U,
    ALTERNATE = 0x2U,
    ANALOG = 0x3U
} GPIOModeTypeDef;

// GPIO pins
typedef enum GPIOPin
{
    PIN0 = 0,
    PIN1 = 1,
    PIN2 = 2,
    PIN3 = 3,
    PIN4 = 4,
    PIN5 = 5,
    PIN6 = 6,
    PIN7 = 7,
    PIN8 = 8,
    PIN9 = 9,
    PIN10 = 10,
    PIN11 = 11,
    PIN12 = 12,
    PIN13 = 13,
    PIN14 = 14,
    PIN15 = 15,
} GPIOPinTypeDef;

#endif // GPIO_TYPES_H
