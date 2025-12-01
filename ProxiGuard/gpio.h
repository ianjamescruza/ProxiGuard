#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>

//PIN MAPPING 
#define BUZZER_PIN  PD3  
#define LED1_PIN    PD4  
#define LED2_PIN    PD5  
#define LED3_PIN    PD6  

void GPIO_Init(void);

void LED_Control(uint8_t led1_state, uint8_t led2_state, uint8_t led3_state);

void Buzzer_LongBeep(uint8_t times);
void Buzzer_ShortBeep(uint8_t times);

void All_Off(void);

#endif