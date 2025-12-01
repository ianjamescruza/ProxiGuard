#include "sensor.h"
#include <util/delay.h>

void Sensor_Init(void) {
    DDRD |= (1 << TRIG_PIN);
    DDRB &= ~(1 << ECHO_PIN);
    TCCR1A = 0; 
    TCCR1B = (1 << CS11); 
}

uint16_t Sensor_GetDistance(void) {
    uint16_t rising_edge, falling_edge;
    uint32_t pulse_width;
    uint32_t distance;

    PORTD &= ~(1 << TRIG_PIN);
    _delay_us(2);
    PORTD |= (1 << TRIG_PIN);
    _delay_us(10);
    PORTD &= ~(1 << TRIG_PIN);

    TCNT1 = 0;           
    TIFR1 = (1 << ICF1); 
    TCCR1B |= (1 << ICES1); 

    while (!(TIFR1 & (1 << ICF1))) {
        if (TCNT1 > 60000) return 0; 
    }
    rising_edge = ICR1; 

    TIFR1 = (1 << ICF1); 
    TCCR1B &= ~(1 << ICES1); 

    while (!(TIFR1 & (1 << ICF1))) {
        if (TCNT1 > 60000) return 0; 
    }
    falling_edge = ICR1; 

    if (falling_edge > rising_edge) {
        pulse_width = falling_edge - rising_edge;
    } else {
        pulse_width = (65535 - rising_edge) + falling_edge;
    }

    distance = pulse_width / 116;

    return (uint16_t)distance;
}