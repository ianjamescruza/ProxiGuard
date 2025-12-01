#include "gpio.h"
#include <util/delay.h>

void GPIO_Init(void) {
    DDRD |= (1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN) | (1 << BUZZER_PIN);
    PORTD &= ~((1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN) | (1 << BUZZER_PIN));
}

void LED_Control(uint8_t led1, uint8_t led2, uint8_t led3) {
    if (led1) PORTD |= (1 << LED1_PIN);
    else      PORTD &= ~(1 << LED1_PIN);

    if (led2) PORTD |= (1 << LED2_PIN);
    else      PORTD &= ~(1 << LED2_PIN);

    if (led3) PORTD |= (1 << LED3_PIN);
    else      PORTD &= ~(1 << LED3_PIN);
}

void All_Off(void) {
    PORTD &= ~((1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN) | (1 << BUZZER_PIN));
}

void Buzzer_LongBeep(uint8_t times) {
    uint8_t i;
    uint16_t j;
    for (i = 0; i < times; i++) {
        for (j = 0; j < 1000; j++) {
            PORTD |= (1 << BUZZER_PIN);
            _delay_us(500); 
            PORTD &= ~(1 << BUZZER_PIN);
            _delay_us(500);
        }
        _delay_ms(300); 
    }
}

void Buzzer_ShortBeep(uint8_t times) {
    uint8_t i;
    uint16_t j;
    for (i = 0; i < times; i++) {
        for (j = 0; j < 200; j++) { 
            PORTD |= (1 << BUZZER_PIN);
            _delay_us(500); 
            PORTD &= ~(1 << BUZZER_PIN);
            _delay_us(500);
        }
        _delay_ms(100); 
    }
}