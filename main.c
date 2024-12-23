#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL

int main(void) {
    DDRB |= (1 << PB1);

    while (1) {
        PORTB ^= (1 << PB1);
        _delay_ms(250);
    }

    return 0;
}
