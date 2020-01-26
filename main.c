// main.c
// 
// A simple blinky program for ATtiny85
// Connect red LED at pin 2 (PB3)
//
// electronut.in

#include <avr/io.h>
#include <util/delay.h>
 
#define GPIO_PORT   PORTB
#define GPIO_DDR    DDRB

static void GPIO_config(void)
{
    // PB3 output
    GPIO_DDR = 0b00001000;
}

static void GPIO_toggle(uint8_t pin)
{
    uint8_t mask = (1 << pin);
    GPIO_PORT ^= mask;
}

int main (void)
{
    // Setup
    GPIO_config();

    // Do forever
    while (1) 
    {
        // Toggle PB3 high
        GPIO_toggle(3);
        _delay_ms(5);
    }
 
  return 1;
}
