/**
 * Scetch to read data from DS18B20 thermometer via one wire interface
 *
 * @author Igor Martens
 * @since 13.10.2018
 */

#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>

ISR (TIMER0_OVF_vect) {
    // will be triggered every interrupt cycle
}

void setup() {
    DDRB |= (1 << DDB1); // Setup the Output for PWM (OC1A)


    // Set Timer/Counter1 prescaler to clock/64.
    // At 16 MHz this is 250 kHz = 4us.
    TCCR0 |= (0 << CS02) | (1 << CS01) | (1 << CS00);

    // Enable overflow interrupt
    TIMSK |= (1 << TOIE0);

    sei();
}

int main(void) {
    setup();

    while(1) {
    }

    return 0;
}
